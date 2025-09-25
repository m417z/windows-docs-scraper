## Description

Filter Manager uses the **FSCTL_SET_PURGE_FAILURE_MODE** control code to synchronize operations during the lifetime of a section created for [data scan](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatesectionfordatascan). Filters should never issue this control code.

## Parameters

### Major code

### Input buffer

A [**SET_PURGE_FAILURE_MODE_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-set_purge_failure_mode_input) structure.

### Input buffer length

Size in bytes of [**SET_PURGE_FAILURE_MODE_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-set_purge_failure_mode_input).

### Output buffer

None

### Output buffer length

n/a

### Input/output buffer

None

### Input/output buffer length

n/a

### Status block

Reserved for system use.

## Remarks

Filter Manager uses this control code with IRP_MJ_FILE_SYSTEM_CONTROL calls to bracket the life of the section. These calls serve to instruct a file system (and, rarely, minifilters) to behave in the following manner if it fails to purge the Cache Manager caches.

For every FSCTL_SET_PURGE_FAILURE_MODE issued with SET_PURGE_FAILURE_MODE_ENABLED set, a FSCTL_SET_PURGE_FAILURE_MODE will be issued with the SET_PURGE_FAILURE_MODE_DISABLED set. While there is an outstanding SET_PURGE_FAILURE_MODE_ENABLED, Filter Manager responds as follows to certain failure statuses for certain types of operations (see below table):

* Pends the operation, expediting the close of the section (where possible).
* Requeues the operation to the minifilter or file system that issued the failure.

To trigger the Filter Manager to respond accordingly, the file system (or filter) responds to a failure to purge a section in the following ways:

| Operation | Required return status |
| --------- | ---------------------- |
| IRP_MJ_CREATE (destructive operations) | STATUS_USER_MAPPED_FILE |
| IRP_MJ_WRITE (unbuffered operations only) | STATUS_PURGE_FAILED |
| IRP_MJ_SET_INFORMATION | STATUS_PURGE_FAILED |

These statuses should only be returned while there is an outstanding SET_PURGE_FAILURE_MODE_ENABLED (no balancing SET_PURGE_FAILURE_MODE_DISABLED received). In all other cases, error statuses will be returned to the application.

For any other operation (for instance, a cached write), if the filesystem (or filter) fails to purge a section while there is an FSCTL_SET_PURGE_FAILURE_MODE outstanding then it is responsible for pending the operation and reissuing it when the count of outstanding FSCTL_SET_PURGE_FAILURE_MODE drops to zero. If the filesystem (or filter) just returns a failure status (including those listed above), that status will be returned to the application.

The error status is processed entirely within Filter Manager, as is the requeuing of the failed operation. This means that neither are visible to filters, which has the following important implications:

* File system monitoring tools such as [Process Monitor](https://learn.microsoft.com/sysinternals/downloads/procmon) will not report these operations.
* If an upper filter is required to be involved for the re-issued operation to succeed, then the requeued operation will fail. In this situation filter writers are required to ensure that this second filter returns the failure status.

## See also

[**SET_PURGE_FAILURE_MODE_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-set_purge_failure_mode_input)