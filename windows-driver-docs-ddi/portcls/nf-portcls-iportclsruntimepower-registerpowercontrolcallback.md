# IPortClsRuntimePower::RegisterPowerControlCallback

## Description

The port class driver (PortCls) uses the `RegisterPowerControlCallback` method to register a power control callback.

## Parameters

### `_DeviceObject` [in]

The device object.

### `_Callback` [in]

The callback object.

### `_Context` [in, optional]

The callback context.

## Return value

The `RegisterPowerControlCallback` method returns STATUS_SUCCESS, if the call is successful. Otherwise, it returns the appropriate error code.

## See also

[IPortClsRuntimePower](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportclsruntimepower)