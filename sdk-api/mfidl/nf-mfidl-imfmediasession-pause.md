# IMFMediaSession::Pause

## Description

Pauses the Media Session.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | The operation cannot be performed in the Media Session's current state. |
| **MF_E_SHUTDOWN** | The Media Session has been shut down. |
| **MF_E_SESSION_PAUSEWHILESTOPPED** | The Media Session cannot pause while stopped. |

## Remarks

This method pauses the presentation clock.

This method is asynchronous. When the operation completes, the Media Session sends an [MESessionPaused](https://learn.microsoft.com/windows/desktop/medfound/mesessionpaused) event.

This method fails if the Media Session is stopped.

## See also

[IMFMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasession)

[MESessionPaused](https://learn.microsoft.com/windows/desktop/medfound/mesessionpaused)