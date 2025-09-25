# NVME_FIRMWARE_ACTIVATE_ACTIONS enumeration

## Description

Contains values that indicate the action that is taken on the image downloaded by the Firmware Image Download command or on a previously downloaded and placed image.

The values from this enumeration are passed to the Firmware Commit command.

The Firmware Activate command was renamed to the Firmware Commit command in NVME spec v1.2. For a list of Admin commands, see the [NVME_ADMIN_COMMANDS](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_admin_commands) enumeration.

## Constants

### `NVME_FIRMWARE_ACTIVATE_ACTION_DOWNLOAD_TO_SLOT`

The downloaded image replaces the image specified by the Firmware Slot field. This image is not activated.

### `NVME_FIRMWARE_ACTIVATE_ACTION_DOWNLOAD_TO_SLOT_AND_ACTIVATE`

The downloaded image replaces the image specified by the Firmware Slot field. This image is activated at the next reset.

### `NVME_FIRMWARE_ACTIVATE_ACTION_ACTIVATE`

The image specified by the Firmware Slot field is activated at the next reset.

### `NVME_FIRMWARE_ACTIVATE_ACTION_DOWNLOAD_TO_SLOT_AND_ACTIVATE_IMMEDIATE`

The image specified by the Firmware Slot field is requested to be activated immediately without reset.

## Remarks

## See also

[NVME_ADMIN_COMMANDS](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_admin_commands)