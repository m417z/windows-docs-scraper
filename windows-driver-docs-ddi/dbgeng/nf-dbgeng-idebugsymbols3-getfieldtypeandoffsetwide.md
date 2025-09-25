# IDebugSymbols3::GetFieldTypeAndOffsetWide

## Description

The **GetFieldTypeAndOffsetWide** method returns the type of a field and its offset within a container.

## Parameters

### `Module` [in]

Specifies the module containing the types of both the container and the field.

### `ContainerTypeId` [in]

Specifies the type ID for the container's type. Examples of containers include structures, unions, and classes.

### `Field` [in]

Specifies the name of the field whose type and offset are requested. Subfields may be specified by using a dot-separated path.

### `FieldTypeId` [out, optional]

Receives the type ID of the field.

### `Offset` [out, optional]

Receives the offset of the field *Field* from the base memory location of an instance of the container.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | The field *Field* could not be found in the type specified by *ContainerTypeId*. |

## Remarks

An example of a dot-separated path for the *Field* parameter is as follows. Suppose the MyStruct structure contains a field **MyField** of type MySubStruct, and the MySubStruct structure contains the field **MySubField**. Then the type of this field and its location relative to the location of MyStruct structure can be found by passing "MyField.MySubField" as the *Field* parameter to this method.

For more information about types, see [Types](https://learn.microsoft.com/windows-hardware/drivers/debugger/types). For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[GetFieldOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols-getfieldoffset)

[GetTypeId](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-gettypeid)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)