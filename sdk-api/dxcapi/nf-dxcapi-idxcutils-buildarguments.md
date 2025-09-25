## Description

Build arguments that can be passed to the [Compile](https://learn.microsoft.com/windows/win32/api/dxcapi/nf-dxcapi-idxccompiler3-compile) method.

## Parameters

### `pSourceName`

An optional file name. Used in errors and include handlers.

### `pEntryPoint`

Entry point name (`-E`).

### `pTargetProfile`

Shader profile to compile (`-T`).

### `pArguments`

An array of pointers to arguments.

### `argCount`

The number of arguments.

### `pDefines`

An array of defines.

### `defineCount`

The number of defines.

### `ppArgs`

Arguments that you can use with the [IDxcCompiler3::Compile](https://learn.microsoft.com/windows/win32/api/dxcapi/nf-dxcapi-idxccompiler3-compile) method.

## Return value

## Remarks

## See also