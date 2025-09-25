# StorPortCompleteRequest function

## Description

The **StorPortCompleteRequest** routine completes all outstanding requests setting the SRB status value to **SrbStatus**.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `PathId` [in]

Identifies the SCSI bus. A value of SP_UNTAGGED indicates all buses controlled by the HBA.

### `TargetId` [in]

Identifies the target controller or device on the given buses. A value of SP_UNTAGGED indicates all targets on the bus.

### `Lun` [in]

Identifies the logical unit for the given target controller or device. A value of SP_UNTAGGED indicates all logical units for the given target controllers on the given buses. Full-duplex miniport drivers must not assign a value of SP_UNTAGGED to this member.

### `SrbStatus` [in]

Specifies the completion status to be set in the **SrbStatus**member of each SRB.

## Return value

None

## Remarks

We do not recommend that writers of Storport miniport drivers use this particular Storport interface routine. Instead, the miniport driver should call StorPortNotification( RequestComplete ) for each outstanding request.

## See also

[ScsiPortCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportcompleterequest)