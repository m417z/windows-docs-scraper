# NVME_CDW12_FEATURES structure

## Description

Contains parameters for the Set Features command that sets the attributes of the specified feature.

This structure is used in the **CDW12** parameter of the **SETFEATURES** field in the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `HostMemoryBuffer`

Specifies an [NVME_CDW12_FEATURE_HOST_MEMORY_BUFFER](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_feature_host_memory_buffer) structure containing a value that indicates the size of the host memory buffer.

### `AsUlong`

## Remarks

## See also

- [NVME_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command)
- [NVME_CDW10_SET_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_set_features)
- [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features)
- [NVME_CDW13_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_features)
- [NVME_CDW14_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw14_features)
- [NVME_CDW15_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw15_features)