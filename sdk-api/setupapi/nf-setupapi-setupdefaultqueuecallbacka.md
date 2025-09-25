# SetupDefaultQueueCallbackA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupDefaultQueueCallback** function is the default queue callback routine included with the Setup API. You can use it to process notifications sent by the
[SetupCommitFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcommitfilequeuea) function.

## Parameters

### `Context` [in]

Pointer to the context initialized by the
[SetupInitDefaultQueueCallback](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinitdefaultqueuecallback) or
[SetupInitDefaultQueueCallbackEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinitdefaultqueuecallbackex) functions.

### `Notification` [in]

Notification of a queue action. This parameter can be one of the values shown in the following table.

| Value | Meaning |
| --- | --- |
| **SPFILENOTIFY_STARTQUEUE** | Started queued file operations. |
| **SPFILENOTIFY_ENDQUEUE** | Finished queued file operations. |
| **SPFILENOTIFY_STARTSUBQUEUE** | Started a copy, rename, or delete subqueue. |
| **SPFILENOTIFY_ENDSUBQUEUE** | Finished a copy, rename, or delete subqueue. |
| **SPFILENOTIFY_STARTRENAME** | Started a rename operation. |
| **SPFILENOTIFY_ENDRENAME** | Finished a rename operation. |
| **SPFILENOTIFY_RENAMEERROR** | Encountered an error while renaming a file. |
| **SPFILENOTIFY_STARTDELETE** | Started a delete operation. |
| **SPFILENOTIFY_ENDDELETE** | Finished a delete operation. |
| **SPFILENOTIFY_DELETEERROR** | Encountered an error while deleting a file. |
| **SPFILENOTIFY_STARTCOPY** | Started a copy operation. |
| **SPFILENOTIFY_ENDCOPY** | Finished a copy operation. |
| **SPFILENOTIFY_COPYERROR** | Encountered an error while copying a file. |
| **SPFILENOTIFY_NEEDMEDIA** | New media is required. |
| **SPFILENOTIFY_LANGMISMATCH** | Existing target file is in a different language than the source. |
| **SPFILENOTIFY_TARGETEXISTS** | Target file exists. |
| **SPFILENOTIFY_TARGETNEWER** | Existing target file is newer than source. |

### `Param1` [in]

Additional message information. The content of this parameter depends on the value of the *Notification* parameter.

### `Param2` [in]

Additional message information. The content of this parameter depends on the value of the *Notification* parameter.

## Return value

Returns an unsigned integer to
[SetupCommitFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcommitfilequeuea) that can be the one of the values shown in the following table.

| Return code | Description |
| --- | --- |
| **FILEOP_ABORT** | Aborts the operation. |
| **FILEOP_DOIT** | Performs the file operation. |
| **FILEOP_SKIP** | Skips the operation. |
| **FILEOP_RETRY** | Retries the operation. |
| **FILEOP_NEWPATH** | Gets a new path for the operation. |

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SetupDefaultQueueCallback** function is usually only called explicitly by a custom queue callback routine. The custom callback handles a subset of the queue commit notifications and calls the
**SetupDefaultQueueCallback** function to handle the rest of the notifications.

For more information see,
[Queue Notifications](https://learn.microsoft.com/windows/desktop/SetupApi/queue-notifications).

> [!NOTE]
> The setupapi.h header defines SetupDefaultQueueCallback as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupCommitFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcommitfilequeuea)