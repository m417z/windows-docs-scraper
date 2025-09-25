# PFNKSDEVICEQUERYCAPABILITIES callback function

## Description

An AVStream minidriver's *AVStrMiniDeviceQueryCapabilities* routine is called when an [IRP_MN_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-capabilities) is dispatched by the device.

## Parameters

### `Device` [in]

Pointer to the [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) that dispatched the [IRP_MN_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-capabilities).

### `Irp` [in]

The [IRP_MN_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-capabilities) issued by *Device*.

### `Capabilities` [in, out]

Pointer to the DEVICE_CAPABILITIES structure that describes PnP and Power capabilities of *Device*.

## Return value

Should return STATUS_SUCCESS or the error code that was returned from the attempt to perform the operation. Return success if providing query capabilities. If not, return an appropriate error code. Do not return STATUS_PENDING.

## Remarks

The minidriver specifies this routine's address in the **QueryCapabilities** member of its [KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch) structure.

This routine is called when an [IRP_MN_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-capabilities) is dispatched by the device. It will usually be provided by minidrivers that need to supply information regarding power management capabilities. This routine is optional.

## See also

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch)