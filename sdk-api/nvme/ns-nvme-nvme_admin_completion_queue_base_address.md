# NVME_ADMIN_COMPLETION_QUEUE_BASE_ADDRESS structure

## Description

Contains the base memory address of the Admin Completion Queue.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.Reserved0`

A Read Only reserved field.

### `DUMMYSTRUCTNAME.ACQB`

Admin Completion Queue Base (ACQB) is a Read/Write field that indicates the 64-bit physical address for the Admin Completion Queue.

This address is memory page aligned based on the value in contiguous [Memory Page Size (**MPS**)](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_configuration) units. All completion queue entries for the commands submitted to the Admin Submission Queue are posted to this Completion Queue. This queue is always associated with interrupt vector 0.

### `AsUlonglong`

## Remarks

## See also