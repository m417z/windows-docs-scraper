# IDebugControl3::CoerceValue

## Description

The **CoerceValue** method converts a value of one type into a value of another type.

## Parameters

### `In` [in]

Specifies the value to be converted

### `OutType` [in]

Specifies the desired type for the converted value. See [DEBUG_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_value) for possible values.

### `Out` [out]

Receives the converted value. The type of this value will be the type specified by *OutType*.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method converts a value of one type into a value of another type. If the specified *OutType* is not capable of containing the information supplied by the *In* variable, data will be lost.

## See also

[DEBUG_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_value)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)