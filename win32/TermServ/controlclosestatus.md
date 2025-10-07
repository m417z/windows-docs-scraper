# ControlCloseStatus enumeration

Indicates whether the application containing the control can close the control immediately.

## Constants

**controlCloseCanProceed**

Container can go ahead with close immediately. This can happen if the control is not connected.

**controlCloseWaitForEvents**

Container should wait for events [**IMsTscAxEvents::OnDisconnected**](https://learn.microsoft.com/windows/win32/termserv/imstscaxevents-ondisconnected) or [**IMsTscAxEvents::OnConfirmClose**](https://learn.microsoft.com/windows/win32/termserv/imstscaxevents-onconfirmclose).

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8.1<br> |
| Minimum supported server<br> | Windows Server 2012 R2<br> |
| Type library<br> | MsTscAx.dll |

## See also

[**IMsRdpClient::RequestClose**](https://learn.microsoft.com/windows/win32/termserv/imsrdpclient-requestclose)

[**IMsTscAxEvents::OnConfirmClose**](https://learn.microsoft.com/windows/win32/termserv/imstscaxevents-onconfirmclose)

[**IMsTscAxEvents::OnDisconnected**](https://learn.microsoft.com/windows/win32/termserv/imstscaxevents-ondisconnected)

