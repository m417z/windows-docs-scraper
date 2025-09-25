# NVME_CDW10_CREATE_IO_QUEUE structure

## Description

Contains parameters that are used in the Create I/O Completion Queue and Create IO Submission Queue commands. The Create I/O Completion Queue command is used to create all I/O Completion Queues with the exception of the Admin Completion Queue and the Create I/O Submission Queue command is used to create I/O Submission Queues.

The **NVME_CDW10_CREATE_IO_QUEUE** structure is used in the **CDW10** field of the **CREATEIOCQ** and **CREATEIOSQ** parameters of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.QID`

The Queue Identifier (QID) field indicates the identifier to assign to the Completion Queue or Submission Queue to be created.

This identifier corresponds to either the [Completion Queue Head Doorbell](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_completion_queue_head_doorbell) used for the Completion Queue command or the [Submission Queue Tail Doorbell](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_submission_queue_tail_doorbell) used for the Submission Queue command.

This 16-bit ID value should not exceed the value reported in the [NVME_FEATURE_NUMBER_OF_QUEUES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_features) feature for I/O Completion Queues or I/O Submission Queues. If the value specified is `0h`, exceeds the Number of Queues reported, or corresponds to an identifier already in use, the controller should return an error of [NVME_STATUS_INVALID_QUEUE_IDENTIFIER](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_command_specific_codes).

### `DUMMYSTRUCTNAME.QSIZE`

The Queue Size (QSIZE) field indicates the size of the Completion Queue or Submission Queue to be created. The Queue Size is indicated in a 16-bit 0’s based field that specifies the number of entries in the queue.

The minimum size for a queue is two entries. The maximum size for either an I/O Submission Queue or an I/O Completion Queue is 64K entries, limited by the maximum queue size supported by the controller that is reported in the Maximum Queue Entries Supported (**MQES**) field of the [NVME_CONTROLLER_CAPABILITIES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_capabilities) structure.

The maximum size for the Admin Submission and Admin Completion Queue is defined as 4K entries. One entry in each queue is not available for use due to Head and Tail entry pointer definition.

If the size is `0h` or larger than the controller supports, the controller should return an error of [Invalid Queue Size](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_command_specific_codes).

### `AsUlong`

## Remarks

## See also

- [NVME_CDW11_CREATE_IO_CQ](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_create_io_cq)
- [NVME_CDW11_CREATE_IO_SQ](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_create_io_sq)