# IDebugRegisters2::SetValues2

## Description

The **SetValues2** method sets the value of several of the target's [registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## Parameters

### `Source` [in]

Specifies the register source to query.

The possible values are listed in the following table.

| Value | Register source |
| --- | --- |
| DEBUG_REGSRC_DEBUGGEE | Fetch register information from the target. |
| DEBUG_REGSRC_EXPLICIT | Fetch register information from the current explicit [register context](https://learn.microsoft.com/windows-hardware/drivers/debugger/changing-contexts). |
| DEBUG_REGSRC_FRAME | Fetch register information from the current scope's register context.<br><br>**Note** Stack unwinding does not guarantee accurate updating of the register context, so the scope frame's register context might not be accurate in all cases. |

### `Count` [in]

Specifies the number of registers for which to set the values.

### `Indices` [in, optional]

Specifies an array that contains the indices of the registers for which to set the values. The number of elements in this array is *Count*. If *Indices* is **NULL**, *Start* is used instead.

### `Start` [in]

If *Indices* is **NULL**, the registers will be set consecutively starting at this index. Otherwise, it is ignored.

### `Values` [in]

An array that contains the values to which to set the registers. The number of elements that this array holds is *Count*. See [DEBUG_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_value) for a description of this parameter type.

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The engine does its best to cast the values in *Values* into the type of the registers; this conversion is the same as that performed by [CoerceValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-coercevalue). If the value is larger than what the register can hold, the least significant bits are dropped. Floating-point and integer conversions will also be performed if necessary.

If the return value is not S_OK, some of the registers still might have been set.

When a subregister is altered, the register that contains it is also altered.

The method [SetValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-setvalues) performs the same task as this method but always uses the target as the register source.

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## See also

[IDebugRegisters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters2)

[SetValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-setvalue)

[SetValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-setvalues)