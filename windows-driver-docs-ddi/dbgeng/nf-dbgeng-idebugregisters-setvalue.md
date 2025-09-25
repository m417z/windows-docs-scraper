# IDebugRegisters::SetValue

## Description

The **SetValue** method sets the value of one of the target's [registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## Parameters

### `Register` [in]

Specifies the index of the register whose value is to be set.

### `Value` [in]

Specifies the value to which to set the register. See [DEBUG_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_value) for a description of this parameter type.

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_UNEXPECTED** | The target is not accessible, or the register could not be accessed. |
| **E_INVALIDARG** | The value of *Register* is greater than the number of registers on the target machine. |

## Remarks

The engine does its best to coerce the value of *Value* into the type of the register; this coercion is the same as that performed by [CoerceValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-coercevalue). If the value is larger than what the register can hold, the least significant bits are dropped. Floating-point and integer conversions will also be performed if necessary.

When a subregister is altered, the register containing it is also altered.

To set the values of multiple registers, use the [SetValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-setvalues) method instead.

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## See also

[IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters)

[IDebugRegisters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters2)

[SetValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-setvalues)

[SetValues2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-setvalues2)