# BG_JOB_TIMES structure

The **BG_JOB_TIMES** structure provides job-related time stamps.

## Members

**CreationTime**

Time the job was created. The time is specified as [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime).

**ModificationTime**

Time the job was last modified or bytes were transferred. Adding files or calling any of the set methods in the [**IBackgroundCopyJob\***](https://learn.microsoft.com/previous-versions//mt811348(v=vs.85)) interfaces changes this value. In addition, changes to the state of the job and calling the [**Suspend**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-suspend), [**Resume**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-resume), [**Cancel**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-cancel), and [**Complete**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-complete) methods change this value. The time is specified as [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime).

**TransferCompletionTime**

Time the job entered the BG_JOB_STATE_TRANSFERRED state. The time is specified as [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1709 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server, version 1709 \[desktop apps only\]<br> |
| Header<br> | Deliveryoptimization.h |

## See also

[**IBackgroundCopyJob::GetTimes**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-gettimes)

