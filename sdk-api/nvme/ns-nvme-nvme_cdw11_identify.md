# NVME_CDW11_IDENTIFY structure

## Description

Contains a parameter for the Identify command.

The **NVME_CDW11_IDENTIFY** structure is used in the **CDW11** field of the **IDENTIFY** parameter in the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.NVMSETID`

Specifies the NVM Set Identifier (NVMSETID) that is used as part of some Identify operations.

### `DUMMYSTRUCTNAME.Reserved`

### `AsUlong`

## Remarks

The Identify command returns information about the controller in the [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure, and namespace information in the [NVME_IDENTIFY_NAMESPACE_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data) data structure.

## See also

- [NVME_CDW10_IDENTIFY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_identify)
- [NVME_IDENTIFY_NAMESPACE_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data)
- [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data)