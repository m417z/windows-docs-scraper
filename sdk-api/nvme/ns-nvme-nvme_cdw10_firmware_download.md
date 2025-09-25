# NVME_CDW10_FIRMWARE_DOWNLOAD structure

## Description

Contains parameters for the Firmware Image Download command that is used to copy a new firmware image (in whole or in part) to the controller.

The Firmware Image Download command uses the PRP Entry 1 **PRP1** and PRP Entry 2 **PRP2** fields, and the Command Dword 10 **CDW10** and Command Dword 11 **CDW11** fields in the **FIRMWAREDOWNLOAD** parameter of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure. All other command specific fields in the **FIRMWAREDOWNLOAD** parameter are reserved.

The **NVME_CDW10_FIRMWARE_DOWNLOAD** structure is used as the value of the **CDW10** parameter in the **FIRMWAREDOWNLOAD** field of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `NUMD`

The Number of Dwords (NUMD) field specifies the number of Dwords to transfer for this portion of the firmware. This is a 0’s based value.

## Remarks

The Firmware Image Download command may be submitted while other commands on the Admin Submission Queue or I/O Submission Queues are outstanding.

## See also

- [NVME_CDW11_FIRMWARE_DOWNLOAD](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_firmware_download)