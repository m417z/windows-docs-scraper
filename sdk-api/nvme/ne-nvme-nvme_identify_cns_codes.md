# NVME_IDENTIFY_CNS_CODES enumeration

## Description

Contains values that indicate the type of controller or namespace information that will be returned in the Controller or Namespace Structure (**CNS**) member of the Identify command [NVME_CDW10_IDENTIFY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_dword0) structure.

## Constants

### `NVME_IDENTIFY_CNS_SPECIFIC_NAMESPACE`

Information for a specific namespace will be returned.

The Identify Namespace [NVME_IDENTIFY_NAMESPACE_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data) structure is returned to the host for the namespace specified in the Namespace Identifier (**NSID**) member of the [NVME_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure, if the namespace is attached to this controller.

If the specified namespace is an inactive namespace ID, then the controller returns a zero filled data structure.

If the controller supports Namespace Management and **NSID** is set to `FFFFFFFFh`, the controller returns an **NVME_IDENTIFY_NAMESPACE_DATA** that specifies capabilities that are common across namespaces.

### `NVME_IDENTIFY_CNS_CONTROLLER`

Information for a controller will be returned to the host in an Identify Controller [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure.

### `NVME_IDENTIFY_CNS_ACTIVE_NAMESPACES`

A list of active namespaces will be returned.

A list of up to 1024 active namespace IDs is returned to the host containing active namespaces with a namespace identifier greater than the value specified in the **NSID** member of the **NVME_COMMAND** structure.

### `NVME_IDENTIFY_CNS_DESCRIPTOR_NAMESPACE`

Information for a descriptor namespace will be returned.

### `NVME_IDENTIFY_CNS_NVM_SET`

An [NVM_SET_LIST](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvm_set_list) will be returned.

## Remarks

## See also

[NVME_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command)
[NVME_CDW10_IDENTIFY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_dword0)
[NVME_IDENTIFY_NAMESPACE_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data)
[NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data)
[NVM_SET_LIST](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvm_set_list)