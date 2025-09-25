# NVME_NVM_QUEUE_PRIORITIES enumeration

## Description

Contains values that indicate a priority which can be assigned to an I/O Submission Queue for consideration by an arbitration mechanism if one is supported by the controller.

If the weighted round robin with urgent priority class arbitration mechanism is supported, then host software may assign a queue priority service class of urgent, high, medium or low. If the weighted round robin with urgent priority class arbitration mechanism is not supported, then the priority setting is not used and is ignored by the controller

## Constants

### `NVME_NVM_QUEUE_PRIORITY_URGENT`

The queue has an urgent priority.

### `NVME_NVM_QUEUE_PRIORITY_HIGH`

The queue has a high priority.

### `NVME_NVM_QUEUE_PRIORITY_MEDIUM`

The queue has a medium priority.

### `NVME_NVM_QUEUE_PRIORITY_LOW`

The queue has a low priority.

## Remarks

Use this enumeration to specify values in the **QPRIO** field of the [NVME_CDW11_CREATE_IO_SQ](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_create_io_sq) structure that is used in the [Create IO Submission Queue (CREATEIOSQ)](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) Admin command.

## See also

- [NVME_CDW11_CREATE_IO_SQ](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_create_io_sq)