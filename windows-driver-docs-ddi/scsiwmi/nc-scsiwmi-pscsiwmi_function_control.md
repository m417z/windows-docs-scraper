# PSCSIWMI_FUNCTION_CONTROL callback function

## Description

A miniport driver's **HwScsiWmiFunctionControl** routine is called to enable or disable notification of events. It is also called to enable or disable data collection for data blocks that the miniport driver designated as expensive to collect. This routine is optional.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `DeviceContext` [in]

Points to the miniport driver-defined context value passed to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction).

### `RequestContext` [in]

Points to a value containing an enumerator value of type [SCSIWMI_REQUEST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmi_request_context) that the miniport driver passed to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction).

### `GuidIndex` [in]

Specifies the block by its index into the list of GUIDs in the SCSI_WMILIB_CONTEXT structure that the miniport driver passed to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction).

### `Function` [in]

Specifies **ScsiWmiEventControl** to enable or disable an event, or **ScsiWmiDataBlockControl** to enable or disable data collection for a block that was registered as expensive to collect (that is, a block for which the miniport driver set WMIREG_FLAG_EXPENSIVE in **Flags** of the SCSIWMIGUIDREGINFO structure used to register the block).

### `Enable` [in]

Specifies **TRUE** to enable the event or data collection, or **FALSE** to disable it.

## Return value

**HwScsiWmiFunctionControl** returns SRB_STATUS_PENDING if the request is pending, or a nonzero SRB status value if the request was completed. The SRB status value returned by this routine is the same as what was passed in to [ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess). Although the return value data type is BOOLEAN, the **HwScsiWmiFunctionControl** routine actually returns an SRB status value.

## Remarks

When a miniport driver receives an SRB in which the **Function** member is set to SRB_FUNCTION_WMI, it calls [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction) with a pointer to an initialized SCSI_WMILIB_CONTEXT structure and *MinorFunction* set to **Srb->WmiSubFunction**. The SCSI port driver calls a miniport driver's **HwScsiWmiFunctionControl** routine if *MinorFunction* indicates a request to enable or disable an event, or to enable or disable collection for a data block that the miniport driver registered as expensive to collect.

If a miniport driver does not implement a **HwScsiWmiFunctionControl** routine, it must set **WmiFunctionControl** to **NULL** in the SCSI_WMILIB_CONTEXT the miniport driver passes to [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction). The port driver returns SRB_STATUS_SUCCESS to the caller.

It is unnecessary for the miniport driver to check whether events or data collection are already enabled for a block because the port driver sends a single enable request when the first data consumer enables the block, and sends a single disable request when the last data consumer disables the block. The port driver will not call **HwScsiWmiFunctionControl** more than once to enable a block without an intervening call to disable it.

If the SRB is completed in the **HwScsiWmiFunctionControl** callback, then the miniport driver calls [ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess) with an appropriate *SrbStatus*. If the miniport driver pends this SRB, then it should call **ScsiPortWmiPostProcess** when the SRB is done and before completing the SRB.

## See also

[SCSIWMIGUIDREGINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmiguidreginfo)

[SCSI_WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-_scsiwmilib_context)

[ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction)

[ScsiPortWmiPostProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmipostprocess)