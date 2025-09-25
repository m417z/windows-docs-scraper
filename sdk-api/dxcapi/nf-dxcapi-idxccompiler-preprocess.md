## Description

Preprocess source text. **IDxcCompiler::Preprocess** is deprecated; use [IDxcCompiler3::Compile](https://learn.microsoft.com/windows/win32/api/dxcapi/nf-dxcapi-idxccompiler3-compile) with the `-P` argument instead.

## Parameters

### `pSource`

The source text to preprocess.

### `pSourceName`

An optional file name for *pSource*. Used in errors and include handlers.

### `pArguments`

An array of pointers to arguments.

### `argCount`

The number of arguments.

### `pDefines`

An array of defines.

### `defineCount`

The number of defines.

### `pIncludeHandler`

An optional user-provided interface to handle `#include` directives.

### `ppResult`

The preprocessor output status, buffer, and errors.

## Return value

## Remarks

## See also