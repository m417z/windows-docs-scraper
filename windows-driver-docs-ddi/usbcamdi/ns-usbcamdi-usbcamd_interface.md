# USBCAMD_INTERFACE structure

## Description

The USBCAMD_INTERFACE structure defines a set of services related to the USB bus interfaces.

## Members

### `Interface`

Describes the interface that USBCAMD exports for use by other drivers.

### `USBCAMD_WaitOnDeviceEvent`

Pointer to the camera minidriver defined [USBCAMD_WaitOnDeviceEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pfnusbcamd_waitondeviceevent) service.

### `USBCAMD_BulkReadWrite`

Pointer to the camera minidriver defined [USBCAMD_BulkReadWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pfnusbcamd_bulkreadwrite) service.

### `USBCAMD_SetVideoFormat`

Pointer to the camera minidriver defined [USBCAMD_SetVideoFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pfnusbcamd_setvideoformat) service.

### `USBCAMD_SetIsoPipeState`

Pointer to the camera minidriver defined [USBCAMD_SetIsoPipeState](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pfnusbcamd_setisopipestate) service.

### `USBCAMD_CancelBulkReadWrite`

Pointer to the camera minidriver defined [USBCAMD_CancelBulkReadWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pfnusbcamd_cancelbulkreadwrite) service.

## Remarks

The camera minidriver may obtain the USBCAMD_INTERFACE entry points at any point after it has received [SRB_INITIALIZATION_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-initialization-complete). The IRP for acquiring a USBCAMD_INTERFACE is [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) and must be sent at IRQL = PASSIVE_LEVEL. Typically, a camera minidriver obtains the addresses of the USBCAMD_INTERFACE entry points once toward the end of the initialization of the camera minidriver. The members of the USBCAMD_INTERFACE structure are filled with the minidriver's entry points as described in [Acquiring USBCAMD2 Features](https://learn.microsoft.com/windows-hardware/drivers/stream/acquiring-usbcamd2-features)

**USBCAMD_INTERFACE** is not supported in the original USBCAMD.

## See also

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface)

[SRB_INITIALIZATION_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-initialization-complete)

[USBCAMD_BulkReadWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pfnusbcamd_bulkreadwrite)

[USBCAMD_CancelBulkReadWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pfnusbcamd_cancelbulkreadwrite)

[USBCAMD_SetIsoPipeState](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pfnusbcamd_setisopipestate)

[USBCAMD_SetVideoFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pfnusbcamd_setvideoformat)

[USBCAMD_WaitOnDeviceEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pfnusbcamd_waitondeviceevent)