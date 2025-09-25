# StorPortSetDeviceQueueDepth function

## Description

The **StorPortSetDeviceQueueDepth** routine sets the maximum depth of the device queue for the indicated device.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the miniport driver's per-HBA storage area.

### `PathId` [in]

Contains the path ID of the target device.

### `TargetId` [in]

Contains the device number of the target device.

### `Lun` [in]

Contains the logical unit number of the target device.

### `Depth` [in]

Supplies the depth to which the queue is to be set. This value is always > 0.

## Return value

**StorPortSetDeviceQueueDepth** returns **TRUE** if the queue depth was successfully set, or **FALSE** if the operation failed.

## Remarks

Before the first call to **StorPortSetDeviceQueueDepth**, the device queue depth is set to the default value.

The **StorPortSetDeviceQueueDepth** routine should be called when the miniport driver receives the first SCSI Inquiry command for the specified LUN, or at any time thereafter (but not before), as long as the LUN is valid.