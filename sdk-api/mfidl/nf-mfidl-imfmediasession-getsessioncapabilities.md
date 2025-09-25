# IMFMediaSession::GetSessionCapabilities

## Description

Retrieves the capabilities of the Media Session, based on the current presentation.

## Parameters

### `pdwCaps` [out]

Receives a bitwise **OR** of zero or more of the following flags.

| Value | Meaning |
| --- | --- |
| **MFSESSIONCAP_PAUSE** | The Media Session can be paused. |
| **MFSESSIONCAP_RATE_FORWARD** | The Media Session supports forward playback at rates faster than 1.0. |
| **MFSESSIONCAP_RATE_REVERSE** | The Media Session supports reverse playback. |
| **MFSESSIONCAP_SEEK** | The Media Session can be seeked. |
| **MFSESSIONCAP_START** | The Media Session can be started. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | NULL pointer argument. |
| **MF_E_SHUTDOWN** | The Media Session has been shut down. |

## See also

[IMFMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasession)