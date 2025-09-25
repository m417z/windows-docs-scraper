# ITaskScheduler::SetTargetComputer

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

The
**SetTargetComputer** method selects the computer that the
[ITaskScheduler](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itaskscheduler) interface operates on, allowing remote task management and enumeration.

## Parameters

### `pwszComputer` [in]

A pointer to a **null**-terminated wide character string that specifies the target computer name for the current instance of the
**ITaskScheduler** interface. Specify the target computer name in the Universal Naming Convention (UNC) format. To indicate the local computer, set this value to **NULL** or to the local computer's UNC name.

**Note** When specifying a remote computer name, use two backslash (\\) characters before the computer name. For example, use "\\ComputerName" instead of "ComputerName".

## Return value

The
**SetTargetComputer** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **SCHED_E_SERVICE_NOT_INSTALLED** | The Task Scheduler service is not installed on the target computer. |
| **E_ACCESS_DENIED** | The user does not have access to the remote computer. |
| **E_INVALIDARG** | The *pwszComputer* parameter is not valid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## Remarks

For a Windows Server 2003, Windows XP computer to create, monitor, or control tasks on a Windows Vista computer, the following operations should be completed on the Windows Vista computer, and the user who is calling the **ITaskScheduler::SetTargetComputer** method must be a member of the Administrators group on the remote Windows Vista computer.

**Enable the "Share File and Printers" exception in Windows Firewall**

1. Click Start, and then click Control Panel.
2. In Control Panel, click **Classic View** and then double-click the **Windows Firewall**  icon.
3. In the Windows Firewall window, click the **Exceptions** tab and select **File and Printer Sharing exception** check box.

**Enable the "Remote Registry" service**

* Open a Command Prompt window and enter the following command: **net start "Remote Registry"**

## See also

[ITaskScheduler](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itaskscheduler)