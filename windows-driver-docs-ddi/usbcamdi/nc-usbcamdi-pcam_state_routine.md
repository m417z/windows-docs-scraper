# PCAM_STATE_ROUTINE callback function

## Description

[CamRestoreState is not supported and may be altered or unavailable in the future. ]

A camera minidriver's state callback function restores a previously saved device context state or saves the current device context state.

## Parameters

### `BusDeviceObject`

Pointer to the camera minidriver's device object created by the USB hub.

For **CamSaveState**, this value can be NULL.

### `DeviceContext`

Pointer to the camera minidriver's device context.

## Return value

 This callback routine must return STATUS_SUCCESS.

## Remarks

**About CamRestoreState**

USBCAMD calls the minidriver's **CamRestoreState** callback function in the context of an SRB_CHANGE_POWER_STATE request when the power state is going from OFF to ON (D3 to D0).

USBCAMD ignores the return value from the minidriver's **CamRestoreState**.

**CamRestoreState** is called by both versions 1.0 and 2.0 of USBCAMD.

This function is optional.

**About CamSaveState**

USBCAMD version 1.0 calls the minidriver's **CamSaveState** in the context of an SRB_CHANGE_POWER_STATE request where the power state is going from ON to OFF (D0 to D3).

USBCAMD ignores the return value from the minidriver's **CamSaveState** callback function.

**CamSaveState** is called by both versions 1.0 and 2.0 of USBCAMD.

This function is optional.

## See also

[SRB_CHANGE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-change-power-state)