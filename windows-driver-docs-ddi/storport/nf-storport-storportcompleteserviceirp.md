# StorPortCompleteServiceIrp function

## Description

The **StorPortCompleteServiceIrp** routine is called by a Storport virtual miniport driver when it needs to complete a request that it received in its [HwStorProcessServiceRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_process_service_request) callback routine.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `Irp` [in]

A pointer to the I/O request.

## Return value

**StorPortCompleteServiceIrp** returns one of the following values:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | Indicates that the routine completed the request successfully. |
| **STOR_STATUS_INVALID_PARAMETER** | The Irp that was passed was **NULL**. |

## Remarks

The Storport virtual miniport driver's [HwStorProcessServiceRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_process_service_request) callback routine receives an IRP that is produced by an IOCTL when a caller, such as a user-mode application or kernel-mode driver, requires a reverse callback operation. The I/O is completed by the miniport driver by calling the **StorPortCompleteServiceIrp** routine when it needs to tell the caller of something or needs the caller to do something.

## See also

[HwStorProcessServiceRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_process_service_request)