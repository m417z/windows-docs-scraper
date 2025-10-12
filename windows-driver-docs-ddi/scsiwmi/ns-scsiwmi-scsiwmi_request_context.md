# SCSIWMI_REQUEST_CONTEXT structure

## Description

A SCSIWMI_REQUEST_CONTEXT structure contains context information for a WMI SRB.

> [!NOTE]
> The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `UserContext`

Points to a miniport driver buffer that contains any data the miniport driver requires to process the SRB. This can be a pointer to the miniport driver's HW_DEVICE_EXTENSION structure or some other buffer.

### `BufferSize`

Reserved for system use and not available for use by miniport drivers.

### `Buffer`

Reserved for system use and not available for use by miniport drivers.

### `MinorFunction`

Reserved for system use and not available for use by miniport drivers.

### `ReturnStatus`

Indicates the return status of the SRB. This member is not valid until after the miniport driver has called [**ScsiPortWmiPostProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess) to update the request context.

### `ReturnSize`

Indicates the number of bytes of data transferred for the SRB. This member is not valid until after the miniport driver has called [**ScsiPortWmiPostProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess) to update the request context.

## Remarks

When the miniport driver receives an SRB in which the **Function** member is set to SRB_FUNCTION_WMI, it calls [**ScsiPortWmiDispatchFunction**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction) with request parameters, including a pointer to a request context. **ScsiPortWmiDispatchFunction** passes the request context to the miniport driver's appropriate **HwScsiWmi*Xxx*** routine.

When the miniport driver is done processing the SRB and prior to completing the SRB, the miniport driver should call [**ScsiPortWmiPostProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess) to update the **ReturnStatus** and **ReturnSize** members of the request context. The miniport driver updates the SRB's data transfer length and status to these values by calling [**ScsiPortWmiGetReturnSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmigetreturnsize) and [**ScsiPortWmiGetReturnStatus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmigetreturnstatus). respectively.

A request context must remain valid throughout the processing of an SRB. If the SRB can pend, the miniport driver must allocate the SCSIWMI_REQUEST_CONTEXT structure from the SRB extension so it remains valid until the SRB completes. For nonpending SRBs the structure can be allocated from a stack frame that does not go out of scope.

## See also

[**ScsiPortWmiDispatchFunction**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction)

[**ScsiPortWmiGetReturnSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmigetreturnsize)

[**ScsiPortWmiGetReturnStatus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmigetreturnstatus)

[**ScsiPortWmiPostProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess)