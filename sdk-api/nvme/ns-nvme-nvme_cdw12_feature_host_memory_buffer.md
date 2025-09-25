# NVME_CDW12_FEATURE_HOST_MEMORY_BUFFER structure

## Description

Contains a parameter for the Host Memory Buffer Feature that specifies the size of the host memory buffer.

This structure is used in the **HostMemoryBuffer** field of the [NVME_CDW12_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_features) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.HSIZE`

Specifies the size of the host memory buffer allocated in Memory Page Size (MPS) units.

Memory Page size is configured in the **MPS** field of the [NVME_CONTROLLER_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_configuration).

### `AsUlong`

## Remarks

## See also

- [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features)
- [NVME_CDW11_FEATURE_HOST_MEMORY_BUFFER](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_feature_host_memory_buffer)
- [NVME_CDW13_FEATURE_HOST_MEMORY_BUFFER](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_feature_host_memory_buffer)
- [NVME_CDW14_FEATURE_HOST_MEMORY_BUFFER](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw14_feature_host_memory_buffer)
- [NVME_CDW15_FEATURE_HOST_MEMORY_BUFFER](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw15_feature_host_memory_buffer)