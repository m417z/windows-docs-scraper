# IDebugRegisters2::GetPseudoIndexByNameWide

## Description

The **GetPseudoIndexByNameWide** method returns the index of a pseudo-register.

## Parameters

### `Name` [in]

Specifies the name of the pseudo-register whose index is requested. The name includes the leading dollar sign ( **$** ), for example, "$frame".

### `Index` [out]

Receives the index of the pseudo-register.

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For the names of all the pseudo-registers, see [Pseudo-Register Syntax](https://learn.microsoft.com/windows-hardware/drivers/debugger/pseudo-register-syntax).

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## See also

[GetPseudoDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getpseudodescription)

[IDebugRegisters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters2)