# ITaskService::Connect

## Description

Connects to a remote computer and associates all subsequent calls on this interface with a remote session. If the *serverName* parameter is empty, then this method will execute on the local computer. If the *user* is not specified, then the current token is used.

## Parameters

### `serverName` [in, optional]

The name of the computer that you want to connect to. If the *serverName* parameter is empty, then this method will execute on the local computer.

### `user` [in, optional]

The user name that is used during the connection to the computer. If the *user* is not specified, then the current token is used.

### `domain` [in, optional]

The domain of the user specified in the *user* parameter.

### `password` [in, optional]

The password that is used to connect to the computer. If the user name and password are not specified, then the current token is used.

## Return value

This method can return one of these values.

| Return code/value | Description |
| --- | --- |
| **S_OK**<br><br>0 | The operation completed successfully. |
| **E_ACCESS_DENIED**<br><br>0x80070005 | Access is denied to connect to the Task Scheduler service. |
| **SCHED_E_SERVICE_NOT_RUNNING**<br><br>0x80041315 | The Task Scheduler service is not running. |
| **E_OUTOFMEMORY**<br><br>0x8007000e | The application does not have enough memory to complete the operation or the *user*, *password*, or *domain* has at least one null and one non-null value. |
| **ERROR_BAD_NETPATH**<br><br>53 | This error is returned in the following situations:<br><br>* The computer name specified in the *serverName* parameter does not exist.<br>* When you are trying to connect to a Windows Server 2003 or Windows XP computer, and the remote computer does not have the File and Printer Sharing firewall exception enabled or the Remote Registry service is not running.<br>* When you are trying to connect to a Windows Vista computer, and the remote computer does not have the Remote Scheduled Tasks Management firewall exception enabled and the File and Printer Sharing firewall exception enabled, or the Remote Registry service is not running. |
| **ERROR_NOT_SUPPORTED**<br><br>50 | The *user*, *password*, or *domain* parameters cannot be specified when connecting to a remote Windows XP or Windows Server 2003 computer from a Windows Vista computer. |

## Remarks

The **ITaskService::Connect** method should be called before calling any of the other [ITaskService](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskservice) methods.

If you are to connecting to a remote Windows Vista computer from a Windows Vista, you need to allow the Remote Scheduled Tasks Management firewall exception on the remote computer. To allow this exception click **Start**, **Control Panel**, **Security**, **Allow a program through Windows Firewall**, and then select the **Remote Scheduled Tasks Management** check box. Then click the **Ok** button in the Windows Firewall Settings dialog box.

If you are connecting to a remote Windows XP or Windows Server 2003 computer from a Windows Vista computer, you need to allow the File and Printer Sharing firewall exception on the remote computer. To allow this exception click **Start**, **Control Panel**, double-click **Windows Firewall**, select the **Exceptions** tab, and then select the **File and Printer Sharing** firewall exception. Then click the **OK** button in the Windows Firewall dialog box. The Remote Registry service must also be running on the remote computer.

**Note** The **ITaskService::Connect** may return an error **SCHED_E_INVALIDVALUE** while reading the task definition if the schema of the remote task is not supported by the current machine. To verify the highest schema version supported by the current machine, check the  [ITaskService::HighestVersion](https://learn.microsoft.com/windows/desktop/TaskSchd/taskservice-highestversion) property.

## See also

[ITaskService](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskservice)

 [ITaskService::HighestVersion](https://learn.microsoft.com/windows/desktop/TaskSchd/taskservice-highestversion)