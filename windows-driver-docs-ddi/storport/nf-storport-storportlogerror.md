# StorPortLogError function

## Description

The **StorPortLogError** routine notifies the port driver that an error occurred.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `Srb` [in, optional]

Pointer to a SCSI request block if one is associated with the error. Otherwise, this parameter is **NULL**.

### `PathId` [in]

Identifies the SCSI bus.

### `TargetId` [in]

Identifies the target controller or device on the bus.

### `Lun` [in]

Identifies the logical unit number of the target device.

### `ErrorCode` [in]

Specifies an error code indicating one of the following values as the type of error.

| Value | Meaning |
| --- | --- |
| SP_BAD_FW_ERROR | Indicates the driver has detected bad or old firmware. The device will not be used. |
| SP_BAD_FW_WARNING | Indicates the driver has detected a card with old or bad firmware, which can result in reduced performance or functionality. |
| SP_BUS_PARITY_ERROR | Indicates a SCSI bus parity error was detected. |
| SP_BUS_TIME_OUT | Indicates a SCSI bus connection to a logical unit timed out. |
| SP_INTERNAL_ADAPTER_ERROR | Indicates an internal HBA error was detected. |
| SP_INVALID_RESELECTION | Indicates a logical unit reselected unexpectedly or with an invalid queue tag. |
| SP_IRQ_NOT_RESPONDING | Indicates the HBA is not interrupting when expected. |
| SP_PROTOCOL_ERROR | Indicates the miniport driver detected a SCSI bus protocol error. |
| SP_REQUEST_TIMEOUT | Indicates an operation to the controller has timed out. |
| SP_UNEXPECTED_DISCONNECT | Indicates that a target disconnected unexpectedly. |

### `UniqueId` [in]

Specifies a unique identifier for the error. This value differentiates the current error from other errors with the same *ErrorCode* value. For some miniport drivers, this identifies the line of code where the error was detected. For others, it is additional information returned by the HBA.

## Return value

None

## Remarks

The port driver will log an error to the system event log.

Starting in Windows 8, the *Srb* parameter may point to either [SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) or [STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block). If the function identifier in the **Function** field of *Srb* is **SRB_FUNCTION_STORAGE_REQUEST_BLOCK**, the SRB is a **STORAGE_REQUEST_BLOCK** request structure.

## See also

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)

[STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)

[ScsiPortLogError](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportlogerror)

[StorPortLogSystemEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportlogsystemevent)