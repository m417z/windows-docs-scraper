# NVME_CDW11_FEATURE_NUMBER_OF_QUEUES structure

## Description

Contains parameters for the Number of Queues Feature that indicate the number of I/O Completion Queues and I/O Submission Queues that the host requests for this controller.

The values from this structure are used in the **NumberOfQueues** field of the [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.NSQ`

Indicates the number of I/O Submission Queues requested by the host. This number does not include the Admin Submission Queue. A minimum of one should be requested, reflecting that the minimum support is for one I/O Submission Queue. This is a 0’s based value.

The maximum value that may be specified is 65,534 (indicating 65,535 I/O Submission Queues).

If the specified value specified is greater than the maximum value, the controller will return a status of [NVME_STATUS_INVALID_FIELD_IN_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_generic_command_codes).

### `DUMMYSTRUCTNAME.NCQ`

Indicates the number of I/O Completion Queues requested by the host. This number does not include the Admin Completion Queue. A minimum of one should be requested, reflecting that the minimum support is for one I/O Completion Queue. This is a 0’s based value.

The maximum value that may be specified is 65,534 (indicating 65,535 I/O Completion Queues).

If the specified value specified is greater than the maximum value, the controller will return a status of [NVME_STATUS_INVALID_FIELD_IN_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_generic_command_codes).

### `AsUlong`

## Remarks

## See also

- [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features)