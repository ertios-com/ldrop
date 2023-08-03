#include <iostream>
#include <string>
#include <unordered_set>

using Keys = std::unordered_set<std::string_view>;

size_t skipValue(const std::string& line, size_t i)
{
  const bool quoted = i < line.size() && line[i] == '"';

  size_t j = i + static_cast<size_t>(quoted);
  while (j < line.size())
  {
    if (line[j] == '\\')           { j += 2; continue; }
    if (line[j] == ' ' && !quoted) { break; }
    if (line[j] == '"' && quoted)  { j++; break; }
    j++;
  }
  return std::min<size_t>(j, line.size());
}

size_t skipSpace(const std::string &line, size_t i)
{
  while (i < line.size() && line[i] == ' ')
  {
    ++i;
  }
  return i;
}

size_t skipColor(const std::string &line, size_t i)
{
  while (i < line.size() && line[i] == '\033')
  {
    while (i < line.size() && line[i] != 'm')
    {
      ++i;
    }
    ++i;
    i = skipSpace(line, i);
  }
  return i;
}

void removeKeysFromLine(const Keys &keys, std::string &line)
{
  size_t i = 0;

  while (i < line.size())
  {
    i = skipSpace(line, i);
    i = skipColor(line, i);

    size_t keyStart = i;
    size_t eqpos = line.find('=', i);
    if (eqpos == std::string::npos)
    {
      break;
    }

    const std::string_view key(line.data() + i, eqpos - i);
    i = eqpos + 1;
    i = skipValue(line, i);
    i = skipSpace(line, i);

    if (keys.find(key) != keys.end())
    {
      line.erase(keyStart, i - keyStart);
      i = keyStart;
    }
  }
}

int main(int argc, char* argv[])
{
  Keys keys;
  for (int i = 1; i < argc; ++i)
  {
    keys.insert(argv[i]);
  }

  std::string line;
  while (getline(std::cin, line))
  {
    removeKeysFromLine(keys, line);
    printf("%s\n", line.c_str());
  }

  return 0;
}
