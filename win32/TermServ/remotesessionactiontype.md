# RemoteSessionActionType enumeration

Used to specify the type of remote action.

## Constants

### RemoteSessionActionCharms

Displays the charms in the remote session.

### RemoteSessionActionAppbar

Displays the app bar in the remote session.

### RemoteSessionActionSnap

Docks the application in the remote session. This option has been deprecated and should not be used.

### RemoteSessionActionStartScreen

Causes the start screen to be displayed in the remote session.

### RemoteSessionActionAppSwitch

Causes the application switch window to be displayed in the remote session. This is the same as the user pressing Alt+Tab.

### RemoteSessionActionActionCenter

Causes the Action Center to be displayed in the remote session. This is the same as the user pressing Win+A.

**Windows Server 2012 R2, Windows 8.1, Windows Server 2012 and Windows 8:** This value is not supported before Windows Server 2016 and Windows 10.

### RemoteSessionActionTaskManager

Causes the Task Manager to be displayed in the remote session. Introduced in Windows 11, version 24H2.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8<br> |
| Minimum supported server<br> | Windows Server 2012<br> |
| Type library<br> | MsTscAx.dll |

## See also

[**IMsRdpClient8::SendRemoteAction**](https://learn.microsoft.com/windows/win32/termserv/imsrdpclient8-sendremoteaction)

