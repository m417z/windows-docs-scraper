# IMFMediaSession::Close

## Description

Closes the Media Session and releases all of the resources it is using.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The Media Session has been shut down. |

## Remarks

This method is asynchronous. When the operation completes, the Media Session sends an [MESessionClosed](https://learn.microsoft.com/windows/desktop/medfound/mesessionclosed) event.

After the **Close** method is called, the only valid methods on the Media Session are the following:

* [IMFMediaSession::GetClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-getclock)
* [IMFMediaSession::GetFullTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-getfulltopology)
* [IMFMediaSession::GetSessionCapabilities](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-getsessioncapabilities)
* [IMFMediaSession::Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-shutdown)

All other methods return MF_E_INVALIDREQUEST, or else queue an event with that error code.

## See also

[IMFMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasession)