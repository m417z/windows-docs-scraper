# IPortClsRuntimePower::SendPowerControl

## Description

The port class driver (PortCls) uses the `SendPowerControl` method to send power control codes to the audio adapter.

## Parameters

### `_DeviceObject` [in]

The device object.

### `_PowerControlCode` [in]

The power control code to be sent to the audio adapter.

### `_InBuffer` [in, optional]

The input buffer.

### `_InBufferSize` [in]

The size of the input buffer.

### `_OutBuffer` [out, optional]

The output buffer.

### `_OutBufferSize` [in]

The size of the output buffer.

### `_BytesReturned` [out, optional]

The number of bytes returned.

## Return value

The `SendPowerControl` method returns STATUS_SUCCESS, if the call is successful. Otherwise, it returns the appropriate error code.

## See also

[IPortClsRuntimePower](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportclsruntimepower)