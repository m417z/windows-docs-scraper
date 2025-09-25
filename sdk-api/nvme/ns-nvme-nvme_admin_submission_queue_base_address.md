# NVME_ADMIN_SUBMISSION_QUEUE_BASE_ADDRESS structure

## Description

Contains the base memory address of the Admin Submission Queue.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.Reserved0`

A Read Only reserved field.

### `DUMMYSTRUCTNAME.ASQB`

Admin Submission Queue Base (ASQB) is a Read/Write field that indicates the 64-bit physical address for the Admin Submission Queue.

This address is memory page aligned based on the value in contiguous [Memory Page Size (**MPS**)](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_configuration) units. All Admin commands, including creation of I/O Submission Queues and I/O Completions Queues are submitted to this queue.

### `AsUlonglong`

## Remarks

## See also