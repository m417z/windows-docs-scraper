# WerGetFlags function

## Description

Retrieves the [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) fault reporting settings for the specified process.

## Parameters

### `hProcess` [in]

A handle to the process. This handle must have the PROCESS_VM_READ or PROCESS_QUERY_INFORMATION access right.

### `pdwFlags` [out]

This parameter can contain one or more of the following values.

|Value|Meaning|
|--- |--- |
|**WER_FAULT_REPORTING_FLAG_DISABLE_THREAD_SUSPENSION**|Do not suspend the process threads before reporting the error.|
|**WER_FAULT_REPORTING_FLAG_NOHEAP**|Do not collect heap information in the event of an application crash or non-response.|
|**WER_FAULT_REPORTING_FLAG_QUEUE**|Queue critical reports for the specified process. This does not show any UI.|
|**WER_FAULT_REPORTING_FLAG_QUEUE_UPLOAD**|Queue critical reports and upload from the queue.|
|**WER_FAULT_REPORTING_ALWAYS_SHOW_UI**|Always show error reporting UI for this process. This is applicable for interactive applications only.|

## Return value

This function returns **S_OK** on success or an error code on failure.

## See also

[WerSetFlags](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-wersetflags), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)