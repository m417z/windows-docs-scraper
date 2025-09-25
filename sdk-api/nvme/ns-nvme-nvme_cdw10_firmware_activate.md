# NVME_CDW10_FIRMWARE_ACTIVATE structure

## Description

Contains parameters used in the Firmware Commit command.

The Firmware Commit command is used to verify that a valid firmware image has been downloaded and to commit that revision to a specific firmware slot.

> [!NOTE]
> The Firmware Commit command was called Firmware Activate in previous versions of NVM Express.

This structure is used as the value of the **CDW10** parameter in the **FIRMWAREACTIVATE** field of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure. All other command specific fields are reserved.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.FS`

The Firmware Slot (FS) field specifies the firmware slot that is used for the Commit Action, if applicable. If the value specified is `0h`, then the controller will choose the firmware slot (1 – 7) to use for the operation.

### `DUMMYSTRUCTNAME.AA`

The Activate Action (AA) field specifies the action that is taken on the image downloaded with the Firmware Image Download command or on a previously downloaded and placed image. The actions are indicated by one of the values in the [NVME_FIRMWARE_ACTIVATE_ACTIONS](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_firmware_activate_actions) enumeration.

### `DUMMYSTRUCTNAME.Reserved`

### `AsUlong`

## Remarks

## See also