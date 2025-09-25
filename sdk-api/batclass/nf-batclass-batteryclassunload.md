# BatteryClassUnload function

## Description

**BatteryClassUnload** frees resources for a battery device that is no longer in use.

## Parameters

### `ClassData` [in]

Pointer to a battery class handle previously returned by [BatteryClassInitializeDevice](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassinitializedevice).

## Return value

**BatteryClassUnload** returns STATUS_SUCCESS.

## Remarks

**BatteryClassUnload** frees the battery class handle and unloads the battery device. In essence, it undoes the registration and initialization performed by **BatteryClassInitializeDevice**.

A miniclass driver should call this routine when its battery device is no longer available for use. Typically, the driver might make such a call from its Unload routine or when handling a PnP [IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) request.