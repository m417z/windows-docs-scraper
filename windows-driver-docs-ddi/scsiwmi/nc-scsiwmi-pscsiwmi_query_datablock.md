# PSCSIWMI_QUERY_DATABLOCK callback function

## Description

A miniport driver's **HwScsiWmiQueryDataBlock** routine is called to obtain either a single instance or all instances of a data block. This routine is required.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Context` [in]

Points to the miniport driver-defined context value passed to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction).

### `DispatchContext` [in]

Points to the SCSIWMI_REQUEST_CONTEXT structure that the miniport driver passed to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction).

### `GuidIndex` [in]

Specifies the data block by its index into the list of GUIDs in the SCSI_WMILIB_CONTEXT structure that the miniport driver passed to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction).

### `InstanceIndex` [in]

If **HwScsiWmiQueryDataBlock** is called in response to an IRP_MN_QUERY_SINGLE_INSTANCE request, *InstanceIndex* specifies the instance to be queried. If **HwScsiWmiQueryDataBlock** is called in response to an IRP_MN_QUERY_ALL_DATA REQUEST, *InstanceIndex* is zero.

### `InstanceCount` [in]

If **HwScsiWmiQueryDataBlock** is called in response to an IRP_MN_QUERY_SINGLE_INSTANCE request, *InstanceCount* is 1. If **HwScsiWmiQueryDataBlock** is called in response to an IRP_MN_QUERY_ALL_DATA REQUEST, *InstanceCount* is the number of instances to be returned.

### `InstanceLengthArray` [in, out]

Points to an array of ULONGs that indicate the length of each instance of the data block to be returned. This array has *InstanceCount* elements. This value may be **NULL** when there is not enough space in the output buffer to fulfill the request.

### `BufferAvail` [in]

Specifies the maximum number of bytes available to receive data in the buffer at *Buffer*.

### `Buffer` [out]

Points to the buffer to receive instance data. If the buffer is large enough to receive all of the data, the miniport driver writes instance data to the buffer with each instance aligned on an 8-byte boundary. If the buffer is too small to receive all of the data, the miniport driver calls [ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess) with a status of SRB_STATUS_DATA_OVERRUN and sets *BufferUsed* to the size of the output buffer needed to fulfill the request.

## Return value

**HwScsiWmiQueryDataBlock** returns SRB_STATUS_PENDING if the request is pending or a nonzero SRB status value if the request was completed. The SRB status value returned by this routine is the same as what was passed in to [ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess). Although the return value data type is BOOLEAN, the **HwScsiWmiQueryDataBlock** routine actually returns an SRB status value.

## Remarks

When a miniport driver receives an SRB in which the **Function** member is set to SRB_FUNCTION_WMI, it calls [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction) with a pointer to an initialized SCSI_WMILIB_CONTEXT structure and *MinorFunction* set to **Srb->WmiSubFunction**. The SCSI port driver calls the miniport driver's **HwScsiWmiQueryDataBlock** routine if *MinorFunction* indicates a request to obtain a single instance or all instances of a data block.

The miniport driver writes instance data to the buffer. For requests that do not pend, the miniport driver calls [ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess) with an appropriate *SrbStatus* value before returning from **HwScsiWmiQueryDataBlock**. If the request pends, the miniport driver calls **ScsiPortWmiPostProcess** when the request is complete.

## See also

[SCSI_WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-_scsiwmilib_context)

[ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction)

[ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess)