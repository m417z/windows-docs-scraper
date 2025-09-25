# PFNKSDEVICESETPOWER callback function

## Description

AVStream calls a minidriver's *AVStrMiniDeviceSetPower* routine when it receives an [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power).

## Parameters

### `Device` [in]

Pointer to the [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure that received the [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power).

### `Irp` [in]

The [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power) issued by *Device*.

### `To` [in]

The target device power state.

### `From` [in]

The current device power state.

## Remarks

If a driver has registered its device for idle detection, the power manager sends an [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power) to change the power state of an idle device.

The minidriver specifies this routine's address in the **SetPower** member of its [KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch) structure.

This routine is optional.

## See also

[IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power)

[KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch)