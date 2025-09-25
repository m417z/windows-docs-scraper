# IDebugRegisters2::GetPseudoDescriptionWide

## Description

The **GetPseudoDescriptionWide** method returns a description of a pseudo-register, including its name and type.

## Parameters

### `Register` [in]

Specifies the index of the pseudo-register whose description is requested. The index is always between zero and the number of pseudo-registers (returned by [GetNumberPseudoRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getnumberpseudoregisters)) minus one.

### `NameBuffer` [out, optional]

Receives the name of the pseudo-register. If *NameBuffer* is **NULL**, this information is not returned.

### `NameBufferSize` [in]

Specifies the size, in characters, of the buffer that *NameBuffer* specifies. This size includes the space for the '\0' terminating character.

### `NameSize` [out, optional]

Receives the size in characters of the name of the pseudo-register. This size includes the space for the '\0' terminating character. If *NameSize* is **NULL**, this information is not returned.

### `TypeModule` [out, optional]

Receives the base address of the module to which the register's type belongs. If the type of the register is not known, zero is returned. If *TypeModule* is **NULL**, no information is returned.

### `TypeId` [out, optional]

Receives the type ID of the type within the module returned in *TypeModule*. If the type ID is not known, zero is returned. If *TypeId* is **NULL**, no information is returned.

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The description for the register was not available |

## Remarks

Descriptions are not always available for all registers. If a pseudo-register does not have a value - for example, **$eventip** will not have a value before an event has occurred - or a type cannot be determined for a pseudo-register, this method will return E_FAIL.

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## See also

[GetNumberPseudoRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getnumberpseudoregisters)

[GetPseudoIndexByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getpseudoindexbyname)

[IDebugRegisters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters2)