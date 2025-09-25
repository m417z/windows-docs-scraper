# IDebugSymbols::GetFieldOffset

## Description

The **GetFieldOffset** method returns the offset of a field from the base address of an instance of a type.

## Parameters

### `Module` [in]

Specifies the module containing the types of both the container and the field.

### `TypeId` [in]

Specifies the type ID of the type containing the field.

### `Field` [in]

Specifies the name of the field whose offset is requested. Subfields may be specified by using a dot-separated path.

### `Offset` [out]

Receives the offset of the specified field from the base memory location of an instance of the type.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | The field *Field* could not be found in the type specified by *TypeId*. |

## Remarks

An example of a dot-separated path for the *Field* parameter is as follows. Suppose the MyStruct structure contains a field **MyField** of type MySubStruct, and the MySubStruct structure contains the field **MySubField**. Then the location of this field relative to the location of MyStruct structure can be found by setting the *Field* parameter to "MyField.MySubField".

For more information about types, see [Types](https://learn.microsoft.com/windows-hardware/drivers/debugger/types).