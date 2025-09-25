# ScsiPortWmiPostProcess function

## Description

The **ScsiPortWmiPostProcess** routine updates a request context for a WMI SRB.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `RequestContext` [in]

A pointer to the request context for this SRB.

### `SrbStatus` [in]

Specifies any valid SRB status. If the output buffer passed to the miniport driver was too small to contain all of the data from a request, the miniport driver sets *SrbStatus* to SRB_STATUS_DATA_OVERRUN.

### `BufferUsed` [in]

If *SrbStatus* indicates success, the miniport driver sets *BufferUsed* to the number of bytes of data written to the buffer. If *SrbStatus* is SRB_STATUS_DATA_OVERRUN, the miniport driver sets *BufferUsed* to the number of bytes required to complete the SRB successfully.

## Remarks

A miniport driver must call **ScsiPortWmiPostProcess** after the WMI SRB request has been processed and is ready to be completed.

For synchronous SRBs, **ScsiPortWmiPostProcess** is called in the callback routine.

For pending SRBs, **ScsiPortWmiPostProcess** is called after the SRB has been processed, and before it is completed.

If a miniport driver sets *SrbStatus* to SRB_STATUS_DATA_OVERRUN and sets *BufferUsed*, successive identical WMI SRBs with an allocated buffer equal to or greater than *BufferUsed* bytes should succeed. This should be achieved if the driver sets the exact value for *BufferUsed* that is needed to complete the request when calling **ScsiPortWmiPostProcess** with *SrbStatus* equal to SRB_STATUS_DATA_OVERRUN. For a variable-sized output structure, the input data buffer of the SRB should have enough information to determine the exact *BufferUsed* value. If the input data buffer does not contain enough information, the driver should never fail the same SRB two times with SRB_STATUS_DATA_OVERRUN. Instead, the driver should set SRB_STATUS_DATA_OVERRUN and request the minimum size necessary for the output buffer first, and then set SRB_STATUS_SUCCESS and indicate the failure in the contents of the output buffer.

## See also

[SCSIWMI_REQUEST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmi_request_context)

[ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction)

[ScsiPortWmiGetReturnSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmigetreturnsize)

[ScsiPortWmiGetReturnStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmigetreturnstatus)