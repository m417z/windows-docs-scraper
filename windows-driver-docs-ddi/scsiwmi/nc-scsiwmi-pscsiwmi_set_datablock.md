# PSCSIWMI_SET_DATABLOCK callback function

## Description

A miniport driver's **HwScsiWmiSetDataBlock** routine is called to change all data items in a single instance of a data block. This routine is optional.

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

### `BufferSize` [in]

Specifies the size in bytes of the buffer at *Buffer*.

### `Buffer` [in]

Points to a buffer that contains new values for the instance.

## Return value

**HwScsiWmiSetDataBlock** returns SRB_STATUS_PENDING if the request is pending, or a nonzero SRB status value if the request was completed. The SRB status value returned by this routine is the same as what was passed in to [ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess).

## Remarks

When a miniport driver receives an SRB in which the **Function** member is set to SRB_FUNCTION_WMI, it calls [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction) with a pointer to an initialized SCSI_WMILIB_CONTEXT structure and *MinorFunction* set to **Srb->WmiSubFunction**. The SCSI port driver calls the miniport driver's **HwScsiWmiSetDataBlock** routine if *MinorFunction* indicates a request to change an instance of a data block.

If a miniport driver does not implement a **HwScsiWmiSetDataBlock** routine, it must set **SetWmiDataBlock** to **NULL** in the SCSI_WMILIB_CONTEXT the miniport driver passes to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction). In this case, the port driver returns SRB_STATUS_ERROR to the caller.

If the miniport driver implements **HwScsiWmiSetDataBlock** it should change the instance of the data block to the new values from the buffer.

If all of the items in the data block are read-only, the miniport driver should return SRB_STATUS_ERROR. Otherwise, the miniport driver changes the items it can and returns SRB_STATUS_SUCCESS.

The miniport driver should call [ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess) with an appropriate *SrbStatus* value when the request is completed. If the request does not pend, **ScsiPortWmiPostProcess** should be called in the **HwScsiWmiSetDataBlock** callback. Otherwise, **ScsiPortWmiPostProcess** should be called when the request is actually completed.

## See also

[SCSI_WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-_scsiwmilib_context)

[ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction)

[ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess)