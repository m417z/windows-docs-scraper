# BG_JOB_TIMES structure

## Description

Provides job-related time stamps.

## Members

### `CreationTime`

Time the job was created. The time is specified as
[FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime).

### `ModificationTime`

Time the job was last modified or bytes were transferred. Adding files or calling any of the set methods in the
[IBackgroundCopyJob*](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibackgroundcopyjob4) interfaces changes this value. In addition, changes to the state of the job and calling the
[Suspend](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-suspend),
[Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume),
[Cancel](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-cancel), and
[Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) methods change this value. The time is specified as
[FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime).

### `TransferCompletionTime`

Time the job entered the BG_JOB_STATE_TRANSFERRED state. The time is specified as
[FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime).

## See also

[IBackgroundCopyJob::GetTimes](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-gettimes)