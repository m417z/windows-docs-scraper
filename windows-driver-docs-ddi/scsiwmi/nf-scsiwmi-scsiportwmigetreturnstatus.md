# ScsiPortWmiGetReturnStatus macro

## Description

The **ScsiPortWmiGetReturnStatus** routine returns the status of a WMI SRB.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `RequestContext`

Pointer to the request context for this SRB.

## Remarks

A miniport driver must call **ScsiPortWmiGetReturnStatus** to obtain the value to put into **Srb->SrbStatus**. **ScsiPortWmiGetReturnStatus** should be called sometime after the miniport driver calls **ScsiPortWmiPostProcess.**

## See also

[SCSIWMI_REQUEST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmi_request_context)

[ScsiPortWmiGetReturnStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmigetreturnstatus)

[ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess)