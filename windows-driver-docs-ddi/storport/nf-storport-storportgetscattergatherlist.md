# StorPortGetScatterGatherList function

## Description

The **StorPortGetScatterGatherList** routine retrieves the associated scatter/gather list for the specified SCSI request block (SRB).

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `Srb` [in]

Pointer to the SRB for which the scatter gather list is to be constructed.

## Return value

**StorPortGetScatterGatherList** returns a pointer to the scatter/gather list.

## Remarks

This routine is provided with the Storport driver library. There is no parallel routine provided in the SCSI port library.

The pointer to the scatter/gather list that is returned is valid only until the SRB is completed.

The miniport driver does not have to free the memory for the scatter/gather list that **StorPortGetScatterGatherList** returns.

The miniport driver must not modify the scatter/gather list.

Starting in Windows 8, the *Srb* parameter may point to either [SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) or [STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block). If the function identifier in the **Function** field of *Srb* is **SRB_FUNCTION_STORAGE_REQUEST_BLOCK**, the SRB is a **STORAGE_REQUEST_BLOCK** request structure.

## See also

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)

[STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)

[STOR_SCATTER_GATHER_ELEMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_scatter_gather_element)

[STOR_SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_scatter_gather_list)