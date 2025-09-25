# PFNKSDEVICECREATE callback function

## Description

An AVStream minidriver's *AVStrMiniDeviceAdd* routine notifies the minidriver that AVStream's PnP *AddDevice* routine has completed.

## Parameters

### `Device` [in]

Pointer to a [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure describing the functional device object (FDO) that has just been created.

## Return value

Should return STATUS_SUCCESS or the error code that was returned from the attempt to perform the operation. If the minidriver returns failure status, the related *AddDevice* call will also fail. See the Remarks section below for more details.

## Remarks

The minidriver specifies this routine's address in the **Add** member of its [KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch) structure.

AVStream calls *AVStrMiniDeviceAdd* from its default *AddDevice* routine, at [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) initialization time. At the point at which this routine is called, the WDM device object ([DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)) has been created, the **KSDEVICE** structure has been instantiated and initialized, and the KS device header has been allocated.

Minidrivers can use this routine to associate context information with the AVStream device object, or to initialize a device extension.

If this routine returns an unsuccessful status code, AVStream's *AddDevice* routine will fail. STATUS_PENDING is not a legal return code because no IRP is involved. The routine is called at IRQL = PASSIVE_LEVEL only.

This routine is optional.

## See also

[KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch)