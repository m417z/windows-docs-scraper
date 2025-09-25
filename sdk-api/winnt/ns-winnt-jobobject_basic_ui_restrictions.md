# JOBOBJECT_BASIC_UI_RESTRICTIONS structure

## Description

Contains basic user-interface restrictions for a job object.

## Members

### `UIRestrictionsClass`

The restriction class for the user interface. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **JOB_OBJECT_UILIMIT_DESKTOP**<br><br>0x00000040 | Prevents processes associated with the job from creating desktops and switching desktops using the [CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa) and [SwitchDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-switchdesktop) functions. |
| **JOB_OBJECT_UILIMIT_DISPLAYSETTINGS**<br><br>0x00000010 | Prevents processes associated with the job from calling the [ChangeDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changedisplaysettingsa) function. |
| **JOB_OBJECT_UILIMIT_EXITWINDOWS**<br><br>0x00000080 | Prevents processes associated with the job from calling the [ExitWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindows) or [ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex) function. |
| **JOB_OBJECT_UILIMIT_GLOBALATOMS**<br><br>0x00000020 | Prevents processes associated with the job from accessing global atoms. When this flag is used, each job has its own atom table. |
| **JOB_OBJECT_UILIMIT_HANDLES**<br><br>0x00000001 | Prevents processes associated with the job from using USER handles owned by processes not associated with the same job. |
| **JOB_OBJECT_UILIMIT_READCLIPBOARD**<br><br>0x00000002 | Prevents processes associated with the job from reading data from the clipboard. |
| **JOB_OBJECT_UILIMIT_SYSTEMPARAMETERS**<br><br>0x00000008 | Prevents processes associated with the job from changing system parameters by using the [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function. |
| **JOB_OBJECT_UILIMIT_WRITECLIPBOARD**<br><br>0x00000004 | Prevents processes associated with the job from writing data to the clipboard. |

## Remarks

If you specify the JOB_OBJECT_UILIMIT_HANDLES flag, when a process associated with the job broadcasts messages, they are only sent to top-level windows owned by processes associated with the same job. In addition, hooks can be installed only on threads belonging to processes associated with the job.

To grant access to a User handle to a job that has a user-interface restriction, use the
[UserHandleGrantAccess](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-userhandlegrantaccess) function.

## See also

[ExitWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindows)

[ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex)

[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject)

[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject)

[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)

[UserHandleGrantAccess](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-userhandlegrantaccess)