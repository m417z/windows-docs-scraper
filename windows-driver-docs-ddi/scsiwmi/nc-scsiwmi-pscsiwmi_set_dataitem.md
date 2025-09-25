# PSCSIWMI_SET_DATAITEM callback function

## Description

A miniport driver's **HwScsiWmiSetDataItem** routine is called to change a single data item in an instance of a data block. This routine is optional.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `DeviceContext` [in]

Points to the miniport driver-defined context value passed to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction).

### `RequestContext` [in]

Points to the SCSIWMI_REQUEST_CONTEXT structure that the miniport driver passed to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction).

### `GuidIndex` [in]

Specifies the data block by its index into the list of GUIDs in the SCSI_WMILIB_CONTEXT structure that the miniport driver passed to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction).

### `InstanceIndex` [in]

If the block specified by *GuidIndex* has multiple instances, *InstanceIndex* specifies the instance.

### `DataItemId` [in]

Specifies the ID of the data item to set.

### `BufferSize` [in]

Specifies the size in bytes of the buffer at *Buffer*.

### `Buffer` [in]

Points to a buffer that contains the new value for the data item.

## Return value

**HwScsiWmiSetDataItem** returns SRB_STATUS_PENDING if the request is pending, or a nonzero SRB status value if the request was completed. The SRB status value returned by this routine is the same as what was passed in to **HwScsiWmiSetDataItem**. Although the return value data type is BOOLEAN, the **HwScsiWmiSetDataItem** routine actually returns an SRB status value.

## Remarks

When a miniport driver receives an SRB in which the **Function** member is set to SRB_FUNCTION_WMI, it calls [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction) with a pointer to an initialized SCSI_WMILIB_CONTEXT structure and *MinorFunction* set to **Srb->WmiSubFunction**. The SCSI port driver calls the miniport driver's **HwScsiWmiSetDataItem** routine if *MinorFunction* indicates a request to change an item in an instance of a data block.

If a miniport driver does not implement a **HwScsiWmiSetDataItem** routine, it must set **SetWmiDataItem** to **NULL** in the SCSI_WMILIB_CONTEXT the miniport driver passes to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction). In this circumstance, the port driver will return SRB_STATUS_ERROR to the caller.

If the request does not pend, the miniport driver should call [ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess) in its **HwScsiWmiSetDataItem** callback. Otherwise, the miniport driver should call **ScsiPortWmiPostProcess** when the request is actually completed. The miniport driver should call **ScsiPortWmiPostProcess** with the appropriate *SrbStatus* value.

If the item is read-only, the miniport driver calls [ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess) with SRB_STATUS_ERROR. Otherwise, the miniport driver changes the item and calls **ScsiPortWmiPostProcess** with SRB_STATUS_SUCCESS.

## See also

[SCSI_WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-_scsiwmilib_context)

[ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction)

[ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess)