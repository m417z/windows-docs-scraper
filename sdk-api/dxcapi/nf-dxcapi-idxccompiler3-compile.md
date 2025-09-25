## Description

Compile a shader. Depending on the arguments, you can use this method to:

* Compile a single entry point to the target shader model
* Compile a library to a library target (`-T lib_*`)
* Compile a root signature (`-T rootsig_*`),
* Preprocess HLSL source (`-P`)

You can use [IDxcUtils::BuildArguments](https://learn.microsoft.com/windows/win32/api/dxcapi/nf-dxcapi-idxcutils-buildarguments) to assist in building the *pArguments* and *argCount* arguments.

## Parameters

### `pSource`

The source text to compile.

### `pArguments`

An array of pointers to arguments.

### `argCount`

The number of arguments.

### `pIncludeHandler`

An optional user-provided interface to handle `#include` directives.

### `riid`

The interface ID for the result.

### `ppResult`

An [IDxcResult](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcresult) representing the compiler output status, buffer, and errors.

## Return value

## Remarks

## See also