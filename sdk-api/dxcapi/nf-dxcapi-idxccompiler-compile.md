## Description

Compile a single entry point to the target shader model. **IDxcCompiler::Compile** is deprecated; use [IDxcCompiler3::Compile](https://learn.microsoft.com/windows/win32/api/dxcapi/nf-dxcapi-idxccompiler3-compile) instead.

## Parameters

### `pSource`

The source text to compile.

### `pSourceName`

An optional file name for *pSource*. Used in errors and include handlers.

### `pEntryPoint`

Entry point name.

### `pTargetProfile`

Shader profile to compile.

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

The compiler output status, buffer, and errors.

## Return value

## Remarks

## See also