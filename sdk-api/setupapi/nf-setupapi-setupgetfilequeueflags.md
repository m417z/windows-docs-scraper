# SetupGetFileQueueFlags function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupGetFileQueueFlags** function gets the flags from a setup file queue.

## Parameters

### `FileQueue` [in]

Handle to an open setup file queue.

### `Flags` [out]

Pointer to location that contains the flag set with
[SetupSetFileQueueFlags](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupsetfilequeueflags) and returned by
**SetupGetFileQueueFlags**.

| Flag | Meaning |
| --- | --- |
| **SPQ_FLAG_BACKUP_AWARE**<br><br>0x001 | If this flag is set, [SetupCommitFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcommitfilequeuea) issues backup notifications. |
| **SPQ_FLAG_ABORT_IF_UNSIGNED**<br><br>0X002 | For internal use only. |

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)