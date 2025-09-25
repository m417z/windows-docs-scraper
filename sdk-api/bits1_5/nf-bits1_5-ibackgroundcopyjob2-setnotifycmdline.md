# IBackgroundCopyJob2::SetNotifyCmdLine

## Description

Specifies a program to execute if the job enters the **BG_JOB_STATE_ERROR** or **BG_JOB_STATE_TRANSFERRED** state. BITS executes the program in the context of the user who called this method.

## Parameters

### `Program` [in]

Null-terminated string that contains the program to execute. The *pProgram* parameter is limited to MAX_PATH characters, not including the null terminator. You should specify a full path to the program; the method will not use the search path to locate the program.

To remove command line notification, set *pProgram* and *pParameters* to **NULL**. The method fails if *pProgram* is **NULL** and *pParameters* is non-**NULL**.

### `Parameters` [in]

Null-terminated string that contains the parameters of the program in *pProgram*. The first parameter must be the program in *pProgram* (use quotes if the path uses long file names). The *pParameters* parameter is limited to 4,000 characters, not including the null terminator. This parameter can be **NULL**.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Success. |
| **BG_E_INVALID_STATE** | The state of the job cannot be **BG_JOB_STATE_CANCELLED** or **BG_JOB_STATE_ACKNOWLEDGED**. |
| **BG_E_STRING_TOO_LONG** | The *pProgram* or *pParameters* string is too long. |

## Remarks

BITS calls the
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function to launch the program.

Your program should return an exit code of zero. If your program does not return an exit code of zero, BITS checks the state of the job. If the program did not cancel or complete the job, BITS calls the program again after the [minimum retry delay](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setminimumretrydelay) specified for the job expires.

**BITS 1.5 and earlier:** BITS calls the program only once.

To execute a script, specify WScript.exe (include the full path to WScript.exe) in *pProgram*. The *pParameters* parameter should include WScript.exe, the script name, and any arguments.

If your program requires job related information, you must pass this information as arguments. Do not include environment variables, such as %system32%, in *pProgram* or *pParameters* — they are not expanded.

You should include the full path to the program. If any of the arguments in *pParameters* include a path that uses long file names, such as the module name, use quotes around the path.

If the program you want to execute uses the reply or download file, the program must call the [IBackgroundCopyJob::Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) method to make the files available to the client.

Call the
[IBackgroundCopyJob::SetNotifyFlags](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnotifyflags) method to specify when to execute the program. You can request command line execution only for job error or transferred events, not job modification events. Note that BITS still executes the command line even if you call the
**SetNotifyCmdLine** method after the event occurs.

If the BITS job is in a service account context (ie, networkservice/localsystem/localservice), no form of command-line callback will execute.

If you call both the **SetNotifyCmdLine** method
and the [IBackgroundCopyJob::SetNotifyInterface](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnotifyinterface) method, BITS will execute the command line only if the notification interface becomes invalid or the notification method that BITS calls returns a failure code. For example, if the notification method that BITS calls returns a E_FAIL, BITS will execute the command line. However, if the notification method returns **S_OK**, BITS will not execute the command line. If the notification method and command line execution request both fail, BITS will send the notification again after the minimum retry period expires.

Note that calling the
[IBackgroundCopyJob::TakeOwnership](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-takeownership) method removes command line notification from the job.

#### Examples

For an example that calls the
**SetNotifyCmdLine** method, see
[Registering to Execute a Program](https://learn.microsoft.com/windows/desktop/Bits/registering-to-execute-a-program).

## See also

[IBackgroundCopyJob2::GetNotifyCmdLine](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-getnotifycmdline)

[IBackgroundCopyJob::SetNotifyFlags](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnotifyflags)

[IBackgroundCopyJob::SetNotifyInterface](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnotifyinterface)