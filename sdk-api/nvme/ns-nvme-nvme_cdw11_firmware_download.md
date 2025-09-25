# NVME_CDW11_FIRMWARE_DOWNLOAD structure

## Description

Contains parameters for the Firmware Image Download command that is used to copy a new firmware image (in whole or in part) to the controller.

The Firmware Image Download command uses the PRP Entry 1 **PRP1** and PRP Entry 2 **PRP2** fields, and the Command Dword 10 **CDW10** and Command Dword 11 **CDW11** fields in the **FIRMWAREDOWNLOAD** parameter of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure. All other command specific fields in the **FIRMWAREDOWNLOAD** parameter are reserved.

The **NVME_CDW11_FIRMWARE_DOWNLOAD** structure is used as the value of the **CDW11** parameter in the **FIRMWAREDOWNLOAD** field of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `OFST`

The Offset (OFST) field specifies the number of Dwords offset from the start of the firmware image being downloaded to the controller. The offset is used to construct the complete firmware image when the firmware is downloaded in multiple pieces. The piece corresponding to the start of the firmware image has an Offset of `0h`.

## Remarks

## See also

- [NVME_CDW10_FIRMWARE_DOWNLOAD](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_firmware_download)