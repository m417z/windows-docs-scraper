# NVME_ACCESS_LATENCIES enumeration

## Description

Defines values that indicate the latency of a read and write operation.

## Constants

### `NVME_ACCESS_LATENCY_NONE`

None. No latency information provided.

### `NVME_ACCESS_LATENCY_IDLE`

Idle. Longer latency acceptable.

### `NVME_ACCESS_LATENCY_NORMAL`

Normal. Typical latency.

### `NVME_ACCESS_LATENCY_LOW`

Low. Smallest possible latency.

## Remarks

This enumeration is used to specify values in the **AccessLatency** field of the [NVME_CDW13_READ_WRITE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_read_write) structure and in the **AccessLatency** field of the [NVME_CONTEXT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_context_attributes) structure.

## See also

[NVME_CDW13_READ_WRITE struct](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_read_write)