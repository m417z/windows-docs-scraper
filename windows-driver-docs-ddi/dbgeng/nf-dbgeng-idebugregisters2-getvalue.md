# IDebugRegisters2::GetValue

## Description

The **GetValue** method gets the value of one of the target's [registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## Parameters

### `Register` [in]

Specifies the index of the register whose value is requested.

### `Value` [out]

Receives the value of the register. See [DEBUG_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_value) for a description of this parameter type.

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_UNEXPECTED** | The target is not accessible, or the register could not be accessed. |
| **E_INVALIDARG** | The value of Register is greater than the number of registers on the target machine. |

## Remarks

To receive the values of multiple registers, use the [GetValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getvalues) method instead.

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## See also

[GetValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getvalues)

[GetValues2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getvalues2)

[IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters)

[IDebugRegisters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters2)