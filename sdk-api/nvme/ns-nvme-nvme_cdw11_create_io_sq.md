# NVME_CDW11_CREATE_IO_SQ structure

## Description

Contains parameters for the Create IO Submission Queue command, that is used to create IO Submission Queues.

The **NVME_CDW11_CREATE_IO_SQ** structure is used in the **CDW11** field of the **CREATEIOSQ** parameter of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.PC`

The Physically Contiguous (PC) field indicates whether the Submission Queue is physically contiguous in memory.

When this value is set to `1`, the Submission Queue is physically contiguous and PRP Entry 1 (**PRP1** in the [Command data structure](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command)) is the address of a contiguous physical buffer. If the value is set to `0`, the Submission Queue is not physically contiguous and **PRP1** is a PRP List pointer.

If this value is cleared to `0` and the Contiguous Queues Required (**CQR**) field is set to `1` in [Controller Capabilities](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_capabilities), the controller should return a status of [NVME_STATUS_INVALID_FIELD_IN_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_generic_command_codes).

If the queue is located in the Controller Memory Buffer and **PC** is cleared to `0`, the controller will fail the command with a status of [NVME_STATUS_INVALID_USE_OF_CONTROLLER_MEMORY_BUFFER](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_generic_command_codes).

### `DUMMYSTRUCTNAME.QPRIO`

The Queue Priority (QPRIO) field indicates the priority class to use for commands within this Submission Queue by specifying an [NVME_NVM_QUEUE_PRIORITIES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_nvm_queue_priorities) enumeration value.

This field is only used when the weighted round robin with urgent priority class is the arbitration mechanism selected, the field is ignored if weighted round robin with urgent priority class is not used.

### `DUMMYSTRUCTNAME.Reserved0`

### `DUMMYSTRUCTNAME.CQID`

The Queue Identifier (QID) field indicates the identifier of the Completion Queue to utilize for any command completions entries associated with this Submission Queue.

The value of `0h` (Admin Completion Queue) should not be specified.

If the value specified is `0h` or does not correspond to a valid I/O Completion Queue, the controller should return an error of [NVME_STATUS_INVALID_QUEUE_IDENTIFIER](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_command_specific_codes).

### `AsUlong`

## Remarks

## See also

- [NVME_CDW10_CREATE_IO_QUEUE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_create_io_queue)