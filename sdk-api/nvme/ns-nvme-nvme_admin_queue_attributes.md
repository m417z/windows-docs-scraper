# NVME_ADMIN_QUEUE_ATTRIBUTES structure

## Description

Contains the Admin Queue Attributes (AQA) for the Admin Submission Queue and Admin Completion Queue.

The Queue Identifier for the Admin Submission Queue and Admin Completion Queue is `0h`. The Admin Submission Queue’s priority is determined by the selected arbitration mechanism. The Admin Submission Queue and Admin Completion Queue are required to be in physically contiguous memory.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.ASQS`

Admin Submission Queue Size (ASQS) is a Read/Write field that defines the size of the Admin Submission Queue in entries.

Enabling a controller while this field is cleared to `00h` produces undefined results. The minimum size of the Admin Submission Queue is two entries. The maximum size of the Admin Submission Queue is 4096 entries. This is a 0’s based value.

### `DUMMYSTRUCTNAME.Reserved0`

A Read Only reserved field.

### `DUMMYSTRUCTNAME.ACQS`

Admin Completion Queue Size (ACQS) is a Read/Write field that defines the size of the Admin Completion Queue in entries.

Enabling a controller while this field is cleared to `00h` produces undefined results. The minimum size of the Admin Completion Queue is two entries. The maximum size of the Admin Completion Queue is 4096 entries. This is a 0’s based value.

### `DUMMYSTRUCTNAME.Reserved1`

A Read Only reserved field.

### `AsUlong`

## Remarks

> [!NOTE]
> A Unified Extensible Firmware Interface (UEFI) should be used during boot operations. In low memory environments (like Option ROMs in legacy BIOS environments) there may
> not be sufficient available memory to allocate the necessary Submission and Completion Queues. In these types of conditions, low memory operation of the controller is
> vendor specific.

## See also