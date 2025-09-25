# NVME_HOST_MEMORY_BUFFER_DESCRIPTOR_ENTRY structure

## Description

Defines the parameters of a single entry in the Host Memory Descriptor List.

## Members

### `BADD`

Indicates the host memory address for this entry aligned to the memory page size. the memory page size is defined in the **MPS** field of the [NVME_CONTROLLER_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_configuration).

The lower bits (n:0) of this field indicate that the offset within the memory page is `0h`. For example, if the memory page size is 4KB, then bits 11:00 will be zero; if the memory page size is 8KB, then bits 12:00 will be zero.

### `BSIZE`

Indicates the number of contiguous memory page size **MPS** units for this entry.

### `Reserved`

## Remarks

For a description of the fields and structures that define the Host Memory Descriptor List, see [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features#host-memory-buffer).

## See also

- [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features#host-memory-buffer)
- [NVME_CDW11_FEATURE_HOST_MEMORY_BUFFER](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_feature_host_memory_buffer)
- [NVME_CDW12_FEATURE_HOST_MEMORY_BUFFER](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_feature_host_memory_buffer)
- [NVME_CDW13_FEATURE_HOST_MEMORY_BUFFER](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_feature_host_memory_buffer)
- [NVME_CDW14_FEATURE_HOST_MEMORY_BUFFER](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw14_feature_host_memory_buffer)
- [NVME_CDW15_FEATURE_HOST_MEMORY_BUFFER](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw15_feature_host_memory_buffer)