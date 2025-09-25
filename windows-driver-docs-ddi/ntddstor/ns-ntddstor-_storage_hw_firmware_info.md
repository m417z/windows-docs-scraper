# _STORAGE_HW_FIRMWARE_INFO structure

## Description

This structure contains information about the device firmware.

## Members

### `Version`

The version of this structure. This should be set to sizeof(STORAGE_HW_FIRMWARE_INFO)

### `Size`

The size of this structure as a buffer including slot.

### `SupportUpgrade`

Indicates that this firmware supports an upgrade.

### `Reserved0`

Reserved for future use.

### `SlotCount`

The number of firmware slots on the device. This is the dimension of the Slot array.

**Note** Some devices can store more than 1 firmware image, if they have more than 1 firmware slot.

### `ActiveSlot`

The firmware slot containing the currently active/running firmware image.

### `PendingActivateSlot`

The firmware slot that is pending activation.

### `FirmwareShared`

Indicates that the firmware applies to both the device and controller/adapter, e.g. NVMe SSD.

### `Reserved`

Reserved for future use.

### `ImagePayloadAlignment`

The alignment of the image payload, in number of bytes. The maximum is PAGE_SIZE. The transfer size is a multiple of this size. Some protocols require at least sector size. When this value is set to 0, this means that this value is invalid.

### `ImagePayloadMaxSize`

The image payload maximum size, this is used for a single command.

### `Slot`

Contains the slot information for each slot on the device.