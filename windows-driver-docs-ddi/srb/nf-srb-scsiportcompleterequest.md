# ScsiPortCompleteRequest function

## Description

The **ScsiPortCompleteRequest** routine completes all of the active requests for the given SCSI bus, controller, or LU, including a request being processed by the calling miniport driver routine.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the hardware device extension. This is a per-HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the HBA's mapped access ranges. This area is available to the miniport driver in the **DeviceExtension->HwDeviceExtension** member of the HBA's device object immediately after the miniport driver calls [ScsiPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportinitialize). The port driver frees this memory when it removes the device.

### `PathId` [in]

Identifies the SCSI bus; SP_UNTAGGED indicates all buses controlled by the HBA.

### `TargetId` [in]

Identifies the target controller or device on the given buses; SP_UNTAGGED indicates all targets on the bus.

### `Lun` [in]

Identifies the logical unit for the given target controller or device; SP_UNTAGGED indicates all logical units for the given target controllers on the given buses.

### `SrbStatus` [in]

Specifies the completion status to be set in the **SrbStatus** member of each SRB.

## Return value

None

## Remarks

**ScsiPortCompleteRequest** can be called to complete outstanding requests after a bus reset, a device reset, or an abort, rather than calling [ScsiPortNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportnotification) for each outstanding request individually. After calling **ScsiPortCompleteRequest**, do not also call **ScsiPortNotification**.

## See also

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)

[ScsiPortNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportnotification)