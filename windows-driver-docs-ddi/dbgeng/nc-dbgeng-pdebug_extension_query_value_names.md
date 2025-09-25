# PDEBUG_EXTENSION_QUERY_VALUE_NAMES callback function

## Description

The **DebugExtensionQueryValueNames** callback function recovers [pseudo-register](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers) values.

```cpp
 CALLBACK* PDEBUG_EXTENSION_QUERY_VALUE_NAMES DebugExtensionQueryValueNames;
```

## Parameters

### `Client` [in]

A client to use if the extension needs DbgEng functions.

### `Flags` [in]

Provides behavioral flags. This parameter is currently reserved.

### `Buffer` [out]

A string buffer that the caller provides, to be filled with the set of value names that the client wants to expose.

### `BufferChars` [in]

The count of wide characters in *Buffer*.

### `BufferNeeded` [out]

The number of wide characters that this function needs to complete successfully.

## Return value

**DebugExtensionQueryValueNames** might return one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The function was successfully completed. |
| **S_FALSE** | The function completed without error, but it obtained only partial results. |

This function might also return error values. For more information about possible return values, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

Value names must start with **$$** and have a terminating NULL character. The *Buffer* string must also be NULL-terminated. For example, *Buffer* could be "$$myval1\0$$myval2\0\0".

*DebugExtensionQueryValueNames* is called **PDEBUG_EXTENSION_QUERY_VALUE_NAMES** in the Dbgeng.h header file.

## See also

[DebugExtensionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_extension_initialize)

*DebugExtensionNotify*

*DebugExtensionProvideValue*

*DebugExtensionUninitialize*

*KnownStructOutput*