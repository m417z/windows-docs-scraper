# NVME_CDW14_FEATURE_HOST_MEMORY_BUFFER structure

## Description

Contains a parameter for the Host Memory Buffer Feature that specifies the upper 32 bits of the physical location of the Host Memory Descriptor List.

This structure are used in the **HostMemoryBuffer** field of the [NVME_CDW14_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw14_features) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.HMDLUA`

Specifies the upper 32 bits of the physical location of the Host Memory Descriptor List for the Host Memory Buffer.

The lower bounds of the Host Memory Descriptor List Address defined in the **HMDLLA** field of the [NVME_CDW13_FEATURE_HOST_MEMORY_BUFFER](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_feature_host_memory_buffer).

### `AsUlong`

## Remarks

For a description of the fields and structures that define the Host Memory Descriptor List, see [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features#host-memory-buffer).

## See also

- [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features)
- [NVME_CDW11_FEATURE_HOST_MEMORY_BUFFER](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_feature_host_memory_buffer)
- [NVME_CDW12_FEATURE_HOST_MEMORY_BUFFER](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_feature_host_memory_buffer)
- [NVME_CDW13_FEATURE_HOST_MEMORY_BUFFER](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_feature_host_memory_buffer)
- [NVME_CDW15_FEATURE_HOST_MEMORY_BUFFER](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw15_feature_host_memory_buffer)