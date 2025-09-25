# StorPortGetPfns function

## Description

A miniport can call the **StorPortGetPfns** to retrieve the page frame numbers (Pfns) for the memory described by the specified MDL (memory descriptor list) associated with a SRB.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver.

Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver in the **DeviceExtension->HwDeviceExtension** member of the device object for the HBA immediately after the miniport driver calls [**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `Srb` [in]

A pointer to the source SCSI request block (SRB). Starting in Windows 8, the **Srb** parameter can point to either [**SCSI_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) or [**STORAGE_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block).

### `Mdl` [in]

A pointer to the MDL for which Pfns are requested. Only MDLs obtained using [**StorPortGetOriginalMdl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetoriginalmdl) or [**StorPortGetDataInBufferMdl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdatainbuffermdl) are supported.

### `Pfns` [out]

Pointer to an array of Pfns that are associated with the MDL. Callers must not modify, update, or free the list.

### `PfnCount` [out]

The number of Pfns in the array that **Pfns** points to.

### `StartingOffset` [out]

Specifies the byte offset within the initial page of the buffer described by the given MDL.

## Return value

**StorPortGetPfns** returns one of the following status codes:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_NOT_IMPLEMENTED | This function is not implemented on the active operating system. |
| STOR_STATUS_SUCCESS | The function completed successfully. |
| STOR_STATUS_INVALID_PARAMETER | A pointer to one of the parameters is **NULL**. |

## See also

[**StorPortGetDataInBufferMdl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdatainbuffermdl)

[**StorPortGetOriginalMdl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetoriginalmdl)

[**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize)