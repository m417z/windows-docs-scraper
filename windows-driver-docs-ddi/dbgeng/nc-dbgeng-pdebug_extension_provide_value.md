# PDEBUG_EXTENSION_PROVIDE_VALUE callback function

## Description

The **DebugExtensionProvideValue** callback function sets [pseudo-register](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers) values.

```cpp
 CALLBACK* PDEBUG_EXTENSION_PROVIDE_VALUE DebugExtensionProvideValue;
```

## Parameters

### `Client` [in]

A client to use if the extension needs DbgEng functions.

### `Flags` [in]

Provides behavioral flags. This parameter is currently reserved.

### `Name` [in]

The name of the value to return. This name might be one of the names that the [DebugExtensionQueryValueNames](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_extension_query_value_names) function returned or a name that the caller might already be aware of.

### `Value` [out]

A pointer to the value to be set.

### `TypeModBase` [out]

The base starting address for *Client.*

### `TypeId` [out]

A pointer to the ID for the type of *Value*.

### `TypeFlags` [out]

A parameter that you can use to return one of the following flags:

| Value | Meaning |
| --- | --- |
| **DEBUG_EXT_PVTYPE_IS_VALUE** | The value that is pointed to by *Value* is not a pointer. |
| **DEBUG_EXT_PVTYPE_IS_POINTER** | The value that is pointed to by *Value* is an address for a pointer to data of the type that TypeModBase and TypeId specify. |

## Return value

**DebugExtensionProvideValue** might return one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The function was successfully completed. |

This function might also return error values. For more information about possible return values, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

The name that the *Name* parameter specifies must start with **$$** and have a terminating NULL character.

*DebugExtensionProvideValue* is called **PDEBUG_EXTENSION_PROVIDE_VALUE** in the Dbgeng.h header file.

## See also

[DebugExtensionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_extension_initialize)

*DebugExtensionNotify*

*DebugExtensionQueryValueNames*

*DebugExtensionUninitialize*

*KnownStructOutput*