# IDebugRegisters::SetValues

## Description

The **SetValues** method sets the value of several of the target's [registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## Parameters

### `Count` [in]

Specifies the number of registers for which to set the values.

### `Indices` [in, optional]

Specifies an array that contains the indices of the registers for which to set the values. The number of elements in this array is *Count*. If *Indices* is **NULL**, *Start* is used instead.

### `Start` [in]

If *Indices* is **NULL**, the registers will be set consecutively starting at this index. Otherwise it is ignored.

### `Values` [in]

Specifies the array that contains values to which to set the registers. The number of elements this array holds is *Count*. See [DEBUG_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_value) for a description of this parameter type.

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_UNEXPECTED** | The target is not accessible, or one or more of the registers could not be accessed. |
| **E_INVALIDARG** | The value of the index of one or more of the registers is greater than the number of registers on the target machine. |

## Remarks

The engine does its best to coerce the values in *Values* into the type of the registers; this coercion is the same as that performed by [CoerceValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-coercevalue). If the value is larger than what the register can hold, the least significant bits are dropped. Floating-point and integer conversions will also be performed if necessary.

If the return value is not S_OK, some of the registers still might have been set.

When a subregister is altered, the register containing it is also altered.

To set the value of only a single register, use the [SetValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-setvalue) method instead.

The method [SetValues2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-setvalues2) performs the same task as this method but also allows the register source to be specified.

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## See also

[IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters)

[IDebugRegisters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters2)

[SetValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-setvalue)

[SetValues2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-setvalues2)