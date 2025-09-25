# SetupCommitFileQueueW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupCommitFileQueue** function performs file operations queued on a setup file queue.

The best practice is to collect all the required file operations for the file queue and commit the queue only once because a file queue cannot be reused after it has been committed. If additional processing of the queue is required after it has been committed, the handle to the queue should be closed and a new file queue created. For more information, see
[Committing a Queue](https://learn.microsoft.com/windows/desktop/SetupApi/committing-a-queue).

If a file is modified, the caller of this function is required have privileges to write into the target directory.

## Parameters

### `Owner` [in]

Optional handle to a window to use as the parent of any progress dialog boxes.

### `QueueHandle` [in]

Handle to a setup file queue, as returned by
[SetupOpenFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenfilequeue).

### `MsgHandler` [in]

Pointer to an optional callback routine to be notified of various significant events that are in the queue processing. For more information, see
[Default Queue Callback Routine](https://learn.microsoft.com/windows/desktop/SetupApi/default-queue-callback-routine) or
[FileCallback](https://learn.microsoft.com/windows/desktop/api/setupapi/nc-setupapi-psp_file_callback_a) If the callback routine is **null**,
**SetupCommitFileQueue** returns **TRUE** and the error is 0 or NO_ERROR.

### `Context` [in]

Value that is passed to the callback function supplied by the *MsgHandler* parameter. If the default callback routine has been specified as *MsgHandler*, this context must be the context returned from
[SetupInitDefaultQueueCallback](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinitdefaultqueuecallback) or
[SetupInitDefaultQueueCallbackEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinitdefaultqueuecallbackex).

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The callback routine specified in *MsgHandler* should be compatible with the parameters that
**SetupCommitFileQueue** passed to it during a queue commit.

If Unicode is defined in your callback application, and you specify *MsgHandler* as the default queue callback routine, the callback routine will expect Unicode parameters. Otherwise, the default queue callback routine will expect ANSI parameters.

> [!NOTE]
> The setupapi.h header defines SetupCommitFileQueue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupCloseFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupclosefilequeue)