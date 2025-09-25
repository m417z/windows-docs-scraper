# ScsiPortWmiDispatchFunction function

## Description

The **ScsiPortWmiDispatchFunction** routine is a dispatch routine for miniport drivers that support WMI.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `WmiLibInfo` [in]

Pointer to a [SCSI_WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-_scsiwmilib_context) structure that contains registration information for a miniport driver's data blocks and event blocks and defines entry points for the miniport driver's WMI library callback routines.

### `MinorFunction` [in]

Indicates the WMI action to perform. The miniport driver sets *MinorFunction* to **Srb->WmiSubFunction** from the input SRB.

### `DeviceContext` [in]

Pointer to a miniport driver-defined context value. The port driver will pass *DeviceContext* to the miniport driver's *HwScsiWmiXxx* callback routine. This value would typically point to a HW_DEVICE_EXTENSION structure.

### `RequestContext` [in]

Pointer to a SCSIWMI_REQUEST_CONTEXT structure that contains context information for the WMI SRB. If the SRB can pend, the miniport driver must allocate this structure from the SRB extension because the request context must remain valid until after **ScsiPortWmiPostProcess** returns with the final SRB return status and buffer size. **ScsiPortWmiDispatchFunction** will pass *RequestContext* to the miniport driver's callback routine that processes this request.

### `DataPath` [in]

Pointer to a GUID that represents the data block associated with the request. The miniport driver sets *DataPath* to **Srb->DataPath** from the input SRB.

### `BufferSize` [in]

Specifies the size in bytes of the data buffer. The miniport driver sets *BufferSize* to **Srb->DataTransferLength** from the input SRB.

### `Buffer` [in]

Pointer to the data buffer. The miniport driver sets *Buffer* to **Srb->DataBuffer** from the input SRB.

## Return value

**ScsiPortWmiDispatchFunction** returns **TRUE** if the request is pending, or **FALSE** if the request was completed.

## Remarks

When a miniport driver receives an SRB in which the **Function** member is set to SRB_FUNCTION_WMI, it calls **ScsiPortWmiDispatchFunction** with request parameters, including a pointer to an initialized SCSI_WMILIB_CONTEXT structure. This structure contains information about the miniport driver's data blocks and event blocks and defines entry points for the miniport driver's *HwScsiWmiXxx* callback routines.

**ScsiPortWmiDispatchFunction** confirms that the SRB is a WMI request and determines whether the block specified by the request is valid for the miniport driver. If these conditions are met, **ScsiPortWmiDispatchFunction** processes the SRB by calling the appropriate *HwScsiWmiXxx* entry point in the miniport driver's SCSI_WMILIB_CONTEXT structure. If the miniport driver does not define an entry point for an optional *HwScsiWmiXxx* routine, the port driver handles the request.

In either case, after **ScsiPortWmiDispatchFunction** returns, the miniport driver should do the following for requests that it does not pend:

* Set **Srb->DataTransferLength** to the value returned by **ScsiPortWmiGetReturnSize**
* Set **Srb->SrbStatus** to the value returned by **ScsiPortWmiGetReturnStatus**
* Call **ScsiPortNotification** with **RequestComplete** and again with **NextRequest**

## See also

[SCSIWMI_REQUEST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmi_request_context)

[SCSI_WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-_scsiwmilib_context)

[ScsiPortNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportnotification)

[ScsiPortWmiGetReturnSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmigetreturnsize)

[ScsiPortWmiGetReturnStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmigetreturnstatus)

[ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess)