# PFNKSDEVICE callback function

## Description

An AVStream minidriver's *AVStrMiniDevicePostStart* routine is called when AVStream performs post-PnP-start processing. Use it to load drivers at start time, for example. Such events then will occur in the context of a worker thread after PnP start.

## Parameters

### `Device` [in]

Pointer to a [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure describing the device for which the [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) request was sent.

## Return value

Should return STATUS_SUCCESS or the error code that was returned from the attempt to perform the operation. If this routine returns failure, any pending [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) requests between the [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) request and the [IRP_MN_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-stop-device) request will be failed. Do not return STATUS_PENDING.

## Remarks

The minidriver specifies this routine's address in the **PostStart** member of its [KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch) structure.

This routine is optional.

## See also

[KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch)