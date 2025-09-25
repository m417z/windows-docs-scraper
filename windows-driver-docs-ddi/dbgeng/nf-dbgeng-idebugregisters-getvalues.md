# IDebugRegisters::GetValues

## Description

The **GetValues** method gets the value of several of the target's [registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## Parameters

### `Count` [in]

Specifies the number of registers whose values are requested.

### `Indices` [in, optional]

Specifies an array that contains the indices of the registers from which to get the values. The number of elements in this array is *Count*. If *Indices* is **NULL**, *Start* is used instead.

### `Start` [in]

If *Indices* is **NULL**, the registers will be read consecutively starting at this index. Otherwise it is ignored.

### `Values` [out]

Receives the values of the registers. The number of elements this array holds is *Count*. See [DEBUG_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_value) for a description of this parameter type.

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_UNEXPECTED** | The target is not accessible, or one of the registers could not be accessed. |
| **E_INVALIDARG** | The value of the index of one of the registers is greater than the number of registers on the target machine. Partial results might have been obtained; those registers that could not be read will have the type DEBUG_VALUE_INVALID. |

## Remarks

**GetValues** gets the value of several of the target's registers.

If the return value is not S_OK, some of the registers still might have been read. If the target was not accessible, the return type is E_UNEXPECTED and *Values* is unchanged; otherwise, *Values* will contain partial results and the registers that could not be read will have type DEBUG_VALUE_INVALID. Ambiguity in the case of the return value E_UNEXPECTED can be avoided by setting the memory of *Values* to zero before calling this method.

To receive the value of only a single register, use the [GetValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-getvalue) method instead.

The method [GetValues2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getvalues2) performs the same task as this method but also allows the register source to be specified.

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## See also

[GetValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-getvalue)

[GetValues2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getvalues2)

[IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters)

[IDebugRegisters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters2)