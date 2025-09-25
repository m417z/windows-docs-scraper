# IPowerNotify::PowerChangeNotify

## Description

The `PowerChangeNotify` method notifies the miniport driver of changes in the power state.

## Parameters

### `PowerState` [in]

Specifies the current power state. This parameter is a union of type POWER_STATE. The new power state (*PowerState*.**DeviceState**) can be one of the DEVICE_POWER_STATE enumeration values listed in [IAdapterPowerManagement::PowerChangeState](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iadapterpowermanagement-powerchangestate).

## Remarks

The PortCls system driver calls the miniport driver's `PowerChangeNotify` method to notify it of changes in the power state. The purpose of this call is to give the miniport driver an opportunity to save any hardware-specific context just before powering down or to restore a previously saved context just after powering up.

The miniport driver can write to the hardware registers or on-board memory during the `PowerChangeNotify` call. If the system is powering down (making a state transition away from PowerDeviceD0), the PortCls system driver calls `PowerChangeNotify` before it calls **IAdapterPowerManagement::PowerChangeState** and after it has paused any active audio data streams. This gives the miniport driver an opportunity to save any hardware-specific device context before the device powers down. For example, a WavePci miniport driver might need to save its DMA registers if the power down occurs during a sequence of scatter/gather data transfers. If the system is powering up (making a state transition toward PowerDeviceD0), PortCls calls `PowerChangeNotify` after it calls **PowerChangeState** and before it restarts any paused audio data streams. This gives the miniport driver an opportunity to restore a previously saved context after the device has powered up.

The code for this method must reside in paged memory.

## See also

[IAdapterPowerManagement::PowerChangeState](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iadapterpowermanagement-powerchangestate)

[IPowerNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-ipowernotify)