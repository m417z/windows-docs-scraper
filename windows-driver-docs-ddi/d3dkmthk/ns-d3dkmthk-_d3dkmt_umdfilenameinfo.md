# _D3DKMT_UMDFILENAMEINFO structure

## Description

The D3DKMT_UMDFILENAMEINFO structure contains the name of an OpenGL ICD that is based on the specified version of the DirectX runtime.

## Members

### `Version` [in]

A KMTUMDVERSION-typed value that indicates the version of the DirectX runtime to retrieve the name of an OpenGL ICD for. The following table lists the possible values.

|Value|Meaning|
|--- |--- |
|KMTUMDVERSION_DX9 (0)|DirectX version 9.0|
|KMTUMDVERSION_DX10 (1)|DirectX version 10.0|
|KMTUMDVERSION_DX11 (2)|DirectX version 11.0|

### `UmdFileName` [out]

A string that contains the name of the OpenGL ICD.