# NVME_CDW10_IDENTIFY structure

## Description

Contains parameters for the Identify command that returns a data buffer that describes information about the NVM subsystem, the controller or the namespace(s).

The **NVME_CDW10_IDENTIFY** structure is used in the **CDW10** field of the **IDENTIFY** parameter in the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.CNS`

Specifies an [NVME_IDENTIFY_CNS_CODES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_identify_cns_codes) value that indicates the information to be returned to the host.

### `DUMMYSTRUCTNAME.Reserved`

### `DUMMYSTRUCTNAME.CNTID`

Specifies the Controller Identifier (CNTID) that is used as part of some Identify operations.

If this field is not used as part of the Identify operation, then host software will clear this field to `0h`. Controllers that support Namespace Management should support this field.

### `AsUlong`

## Remarks

The Identify command returns information about the controller in the [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure, and namespace information in the [NVME_IDENTIFY_NAMESPACE_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data) data structure.

## See also

- [NVME_CDW11_IDENTIFY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_identify)
- [NVME_IDENTIFY_NAMESPACE_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data)
- [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data)