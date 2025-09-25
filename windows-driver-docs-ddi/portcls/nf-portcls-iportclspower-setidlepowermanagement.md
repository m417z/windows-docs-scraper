# IPortClsPower::SetIdlePowerManagement

## Description

The `SetIdlePowerManagement` method provides a way for the adapter driver to opt in or opt out of idle state detection.

## Parameters

### `_DeviceObject` [in]

Specifies a pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents the functional device object of the adapter.

### `_bEnabled` [in]

Specifies a Boolean variable that indicates whether idle state detection is enabled or disabled.

## Return value

The `SetIdlePowerManagement` method returns STATUS_SUCCESS if the call was successful. Otherwise, it returns the appropriate error code.

## Remarks

When the *bEnabled* parameter is set to **TRUE**, it indicates that the adapter driver has enabled idle state detection. When the system determines that the adapter is idle, the adapter can be put into the sleep state to save power. If the adapter was not designed to suppress the popping sound that is normally associated with power-up, it is possible that the adapter can experience a popping effect when it comes out of the sleep state.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IPortClsPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportclspower)

[Immediate Idle Timeout Opt-in](https://learn.microsoft.com/windows-hardware/drivers/audio/immediate-idle-timeout-opt-in)