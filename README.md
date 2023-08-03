# ldrop

Drop fields from logfmt streams. A complimentary utility to [brandur/hutils](https://github.com/brandur/hutils).

[![Release version](https://img.shields.io/github/v/release/ertios-com/ldrop?logo=github&style=for-the-badge)](https://github.com/ertios-com/ldrop/releases) [![Build status at drone.ertios.com](https://img.shields.io/drone/build/ertios-com/ldrop/master?logo=drone&server=https%3A%2F%2Fdrone.ertios.com&style=for-the-badge)](https://drone.ertios.com/ertios-com/ldrop/) [![License: GPL-3](https://img.shields.io/github/license/ertios-com/ldrop?style=for-the-badge)](https://github.com/ertios-com/ldrop/blob/develop/LICENSE.txt)


## Usage

Original stream
```
$ ./binary
ts=20230-80-1T13:33:21.1252 correlation_id=eda21539-7c3b-4a0b-863c-e32c83a74b56 base_url="/" route=executor hostname=localhost protocol=http name=matthew dto="{\"request\":{\"name\":\"matthew\",\"flags\":[\"online\"]}}" method=get http_status=200
ts=20230-80-1T13:33:21.1318 correlation_id=065126a1-538d-4c53-aa8e-f77407514d28 base_url="/" route=executor hostname=localhost protocol=http name=james dto="{\"request\":{\"name\":\"james\"}}" method=get http_status=200
ts=20230-80-1T13:33:21.1412 correlation_id=bbba3d22-31da-478d-b446-335aa4a1b547 base_url="/" route=executor hostname=localhost protocol=http name=peter dto="{\"request\":{\"name\":\"peter\",\"flags\":[\"online\",\"stable\"]}}" method=get http_status=200
ts=20230-80-1T13:33:21.1789 correlation_id=818f1db4-253f-4507-92de-d504fcf7bb7e base_url="/" route=executor hostname=localhost protocol=http name=roger dto="{\"request\":{\"name\":\"roger\"}}" method=post http_status=405
ts=20230-80-1T13:33:21.1971 correlation_id=b00e6b41-8429-4ee4-908a-5deee61f0723 base_url="/" route=executor hostname=localhost protocol=http name=albert dto="{\"request\":{\"name\":\"albert\"}}" method=get http_status=200
```

With ldrop
```
$ ./binary | ldrop ts dto hostname protocol route base_url
correlation_id=eda21539-7c3b-4a0b-863c-e32c83a74b56 name=matthew method=get http_status=200
correlation_id=065126a1-538d-4c53-aa8e-f77407514d28 name=james method=get http_status=200
correlation_id=bbba3d22-31da-478d-b446-335aa4a1b547 name=peter method=get http_status=200
correlation_id=818f1db4-253f-4507-92de-d504fcf7bb7e name=roger method=post http_status=405
correlation_id=b00e6b41-8429-4ee4-908a-5deee61f0723 name=albert method=get http_status=200
```
