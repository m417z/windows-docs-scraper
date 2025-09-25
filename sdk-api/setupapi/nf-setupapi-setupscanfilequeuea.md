# SetupScanFileQueueA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupScanFileQueue** function scans a setup file queue, performing an operation on each node in its copy list. The operation is specified by a set of flags. This function can be called either before or after the queue has been committed.

## Parameters

### `FileQueue` [in]

Handle to the setup file queue whose copy list is to be scanned or iterated.

### `Flags` [in]

Flags to combine to control the file queue scan operation. Note that either SPQ_SCAN_FILE_PRESENCE, SPQ_SCAN_USE_CALLBACK, SPQ_SCAN_USE_CALLBACKEX, or SPQ_SCAN_FILE_VALIDITY must be specified.

| Flag | Meaning |
| --- | --- |
| **SPQ_SCAN_FILE_PRESENCE** | Target files in the copy queue are already present on the target. |
| **SPQ_SCAN_FILE_VALIDITY** | Target files in the copy queue are already present on the target with valid signatures. Available with Windows 2000 and later versions. |
| **SPQ_SCAN_USE_CALLBACK** | Callback routine for each node of the queue. If the callback routine returns a nonzero value, the queue processing stops and **SetupScanFileQueue** returns zero. Issue a [SPFILENOTIFY_QUEUESCAN](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-queuescan) notification code and a pass a pointer to the target path as *Param1*. |
| **SPQ_SCAN_USE_CALLBACKEX** | Callback routine for each node of the queue. If the callback routine returns a nonzero value, the queue processing stops and **SetupScanFileQueue** returns zero. Issue a SPFILENOTIFY_QUEUESCAN_EX notification and pass a pointer to a [FILEPATHS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-filepaths_a) structure as *Param1*. SPQ_SCAN_USE_CALLBACKEX also checks that the file has a valid signature. Available starting with Windows 2000. On Windows XP only, you can turn off signature checking by combining this flag with SPQ_SCAN_FILE_PRESENCE. |
| **SPQ_SCAN_INFORM_USER** | Flag specified when all files in the queue pass the check for valid signatures. **SetupScanFileQueue** informs the user that the operation requires files that are already present on the target. This flag is ignored if SPQ_SCAN_FILE_PRESENCE or SPQ_SCAN_FILE_VALIDITY is not specified. This flag may not be used with SPQ_SCAN_PRUNE_COPY_QUEUE or SPQ_SCAN_PRUNE_DELREN. |
| **SPQ_SCAN_PRUNE_COPY_QUEUE** | Combined with SPQ_SCAN_FILE_PRESENCE, removes present entries from the copy queue. When combined with SPQ_SCAN_FILE_VALIDITY, removes signed entries from the copy queue. Available starting with Windows 2000. On Windows XP only, files that are also specified in the delete queue or rename queues are not pruned unless SPQ_SCAN_PRUNE_DELREN is specified. |
| **SPQ_SCAN_USE_CALLBACK_SIGNERINFO** | Available starting with Windows XP. Issues SPFILENOTIFY_QUEUESCAN_SIGNERINFO notification and passes a pointer to a [FILEPATHS_SIGNERINFO](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-filepaths_signerinfo_a) structure as *Param1*. Checks each file for a valid signature and reports signature information through the callback function. |
| **SPQ_SCAN_PRUNE_DELREN** | Combined with SPQ_SCAN_FILE_PRESENCE or SPQ_SCAN_FILE_VALIDITY, removes entries in the delete or rename queue that are also in the copy queue. When combined with SPQ_SCAN_PRUNE_COPY_QUEUE, limits files that are removed from the copy queue to files that are not in the delete or rename queues. Available starting with Windows XP. |

### `Window` [in]

Optional handle to the window to own dialog boxes that are presented. This parameter is not used if the *Flags* parameter does not contain SPQ_SCAN_FILE_PRESENCE or if *Flags* does not contain SPQ_SCAN_INFORM_USER.

### `CallbackRoutine` [in]

Optional pointer to a [FileCallback](https://learn.microsoft.com/windows/desktop/api/setupapi/nc-setupapi-psp_file_callback_a) callback function to be called on each node of the copy queue. The notification code passed to the callback function is
[SPFILENOTIFY_QUEUESCAN](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-queuescan). This parameter is required if *Flags* includes SPQ_SCAN_USE_CALLBACK.

**Note** You must supply the callback routine specified by *CallbackRoutine*. The default queue callback routine does not support
**SetupScanFileQueue**.

### `CallbackContext` [in]

Optional pointer to a context that contains caller-defined data passed to the callback routine pointed to by *CallbackRoutine*.

### `Result` [out]

Pointer to a variable that receives the result of the scan operation.

## Return value

The function returns a nonzero value if all nodes in the queue were processed.

If the SPQ_SCAN_USE_CALLBACK flag was set, the value in *Result* is 0. The callback routine specified by *CallbackRoutine* is sent the notification SPFILENOTIFY_QUEUESCAN. *CallbackRoutine.Param1* specifies a pointer to an array that contains the target path information. The pointer has been cast to an unsigned integer and must be recast to a TCHAR array of MAX_PATH elements before a callback routine can access the information. *CallbackRoutine.Param2* is set to SPQ_DELAYED_COPY if the current queue node is in use and cannot be copied until the system is restarted. Otherwise, *CallbackRoutine.Param2* takes the value 0.

If SPQ_SCAN_USE_CALLBACK was not set, *Result* indicates whether the queue passed the presence or validity check as shown in the following table.

| Return code | Description |
| --- | --- |
| **0** | The queue failed the check or it passed the check, but SPQ_SCAN_INFORM_USER was specified and the user wants new copies of the files. |
| **1** | The queue passed the check and, if SPQ_SCAN_INFORM_USER was specified, the user indicated that copying is not required. The copy queue is empty and there are no elements on the delete or rename queues, so the caller can skip queue commit. |
| **2** | The queue passed the check and, if SPQ_SCAN_INFORM_USER was specified, the user indicated that copying is not required. The copy queue is empty, but there are elements on the delete or rename queues, so the caller cannot skip queue commit. |

The function returns zero if an error occurred or the callback function returned nonzero. If *Result* is nonzero, it is the value returned by the callback function that stopped queue processing. If *Result* is zero, extended error information can be retrieved by a call to
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[FileCallback](https://learn.microsoft.com/windows/desktop/api/setupapi/nc-setupapi-psp_file_callback_a)

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupCommitFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcommitfilequeuea)

[SetupDefaultQueueCallback](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdefaultqueuecallbacka)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupScanFileQueue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).