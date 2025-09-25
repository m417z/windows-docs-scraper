# PSCSIWMI_QUERY_REGINFO callback function

## Description

A miniport driver's **HwScsiWmiQueryReginfo** routine is called to obtain information about the data and event blocks to be registered on behalf of the miniport driver by the SCSI port driver. This routine is required.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `DeviceContext` [in]

Points to the miniport driver-defined context value passed to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction).

### `RequestContext` [in]

Points to the SCSIWMI_REQUEST_CONTEXT structure that the miniport driver passed to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction).

### `MofResourceName` [out]

Points to a **null**-terminated Unicode string that indicates the name of the MOF resource attached to the miniport driver's binary image file. This string can be declared as a constant in the miniport driver. If the miniport driver does not have a MOF resource attached, it should set *MofResourceName* to **NULL**.

## Return value

**HwScsiWmiQueryReginfo** always returns SRB_STATUS_SUCCESS.

## Remarks

When a miniport driver receives an SRB in which the **Function** member is set to SRB_FUNCTION_WMI, it calls [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction) with a pointer to an initialized SCSI_WMILIB_CONTEXT structure and *MinorFunction* set to **Srb->WmiSubFunction**. If *MinorFunction* indicates a request for registration information, the SCSI port driver calls the miniport driver's **HwScsiWmiQueryReginfo** routine.

The miniport driver provides new or updated registration information about individual blocks, or indicates blocks to remove, in the SCSI_WMILIB_CONTEXT structure it passes to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction). The miniport driver's **HwScsiWmiQueryReginfo** routine supplies a pointer to its MOF resource name.

The miniport driver must not pend or block the SRB. The miniport driver must not call [ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess) or [ScsiPortNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportnotification) from its **HwScsiWmiQueryReginfo** routine.

## See also

[SCSIWMI_REQUEST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmi_request_context)

[SCSI_WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-_scsiwmilib_context)

[ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction)