# IMFMediaSession::Shutdown

## Description

Shuts down the Media Session and releases all the resources used by the Media Session.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Call this method when you are done using the Media Session, before the final call to **IUnknown::Release**. Otherwise, your application will leak memory.

After this method is called, other [IMFMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasession) methods return MF_E_SHUTDOWN.

## See also

[IMFMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasession)