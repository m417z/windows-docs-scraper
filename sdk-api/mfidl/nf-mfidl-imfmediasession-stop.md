# IMFMediaSession::Stop

## Description

Stops the Media Session.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | The operation cannot be performed in the Media Session's current state. |
| **MF_E_SHUTDOWN** | The Media Session has been shut down. |

## Remarks

This method is asynchronous. When the operation completes, the Media Session sends an [MESessionStopped](https://learn.microsoft.com/windows/desktop/medfound/mesessionstopped) event.

## See also

[IMFMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasession)