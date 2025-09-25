# NVME_CMBSZ_SIZE_UNITS enumeration

## Description

Contains values that specify the size units that indicate the size of the Controller Memory Buffer.

## Constants

### `NVME_CMBSZ_SIZE_UNITS_4KB`

The buffer size is in units of 4 KB.

### `NVME_CMBSZ_SIZE_UNITS_64KB`

The buffer size is in units of 64 KB.

### `NVME_CMBSZ_SIZE_UNITS_1MB`

The buffer size is in units of 1 MB.

### `NVME_CMBSZ_SIZE_UNITS_16MB`

The buffer size is in units of 16 MB.

### `NVME_CMBSZ_SIZE_UNITS_256MB`

The buffer size is in units of 256 MB.

### `NVME_CMBSZ_SIZE_UNITS_4GB`

The buffer size is in units of 4 GB.

### `NVME_CMBSZ_SIZE_UNITS_64GB`

The buffer size is in units of 64 GB.

## Remarks

The size of the Controller Memory Buffer indicated in the **SZ** member of the [NVME_CONTROLLER_MEMORY_BUFFER_SIZE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_memory_buffer_size) structure is expressed in multiples of the size units value specified in the **SZU** member (offset 3Ch).

## See also

[NVME_CONTROLLER_MEMORY_BUFFER_SIZE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_memory_buffer_size) structure