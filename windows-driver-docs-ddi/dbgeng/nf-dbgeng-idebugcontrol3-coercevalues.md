# IDebugControl3::CoerceValues

## Description

The **CoerceValues** method converts an array of values into an array of values of different types.

## Parameters

### `Count` [in]

Specifies the number of values to convert.

### `In` [in]

Specifies the array of values to convert. The number of elements that this array holds is *Count*.

### `OutTypes` [in]

Specifies the array of desired types for the converted values. For possible values, see [DEBUG_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_value). The number of elements that this array holds is *Count*.

### `Out` [out]

Specifies the array to be populated by the converted values. The types of these values are specified by *OutType*. The number of elements that this array holds is *Count*.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method converts an array of values of one type into values of another type. Some of these conversions can result in loss of precision.

## See also

[CoerceValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-coercevalue)

[DEBUG_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_value)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)