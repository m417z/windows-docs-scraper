# PowerClearRequest function

## Description

Decrements the count of power requests of the specified type for a power request object.

## Parameters

### `PowerRequest` [in]

A handle to a power request object.

### `RequestType` [in]

The power request type to be decremented. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PowerRequestDisplayRequired** | The display remains on even if there is no user input for an extended period of time. |
| **PowerRequestSystemRequired** | The system continues to run instead of entering sleep after a period of user inactivity. |
| **PowerRequestAwayModeRequired** | The system enters away mode instead of sleep. In away mode, the system continues to run but turns off audio and video to give the appearance of sleep. |
| **PowerRequestExecutionRequired** | The calling process continues to run instead of being suspended or terminated by process lifetime management mechanisms. When and how long the process is allowed to run depends on the operating system and power policy settings. <br><br>When a **PowerRequestExecutionRequired** request is active, it implies **PowerRequestSystemRequired**.<br><br>The **PowerRequestExecutionRequired** request type can be used only by applications. Services cannot use this request type.<br><br>**Windows 7 and Windows Server 2008 R2:** This request type is supported starting with Windows 8 and Windows Server 2012. |

## Return value

If the function succeeds, it returns a nonzero value.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[PowerCreateRequest](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-powercreaterequest)

[PowerSetRequest](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-powersetrequest)