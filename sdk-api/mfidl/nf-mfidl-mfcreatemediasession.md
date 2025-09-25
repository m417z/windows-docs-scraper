# MFCreateMediaSession function

## Description

Creates the [Media Session](https://learn.microsoft.com/windows/desktop/medfound/media-session) in the application's process.

## Parameters

### `pConfiguration`

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. This parameter can be **NULL**. See Remarks.

### `ppMediaSession`

Receives a pointer to the Media Session's [IMFMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasession) interface. The caller must release the interface. Before releasing the last reference to the **IMFMediaSession** pointer, the application must call the [IMFMediaSession::Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-shutdown) method.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

If your application does not play protected content, you can use this function to create the Media Session in the application's process. To use the Media Session for protected content, you must call [MFCreatePMPMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatepmpmediasession).

You can use the *pConfiguration* parameter to specify any of the following attributes:

* [MF_SESSION_GLOBAL_TIME](https://learn.microsoft.com/windows/desktop/medfound/mf-session-global-time-attribute)
* [MF_SESSION_QUALITY_MANAGER](https://learn.microsoft.com/windows/desktop/medfound/mf-session-quality-manager-attribute)
* [MF_SESSION_TOPOLOADER](https://learn.microsoft.com/windows/desktop/medfound/mf-session-topoloader-attribute)
* [MF_LOW_LATENCY](https://learn.microsoft.com/windows/desktop/medfound/mf-low-latency)

## See also

[About the Media Session](https://learn.microsoft.com/windows/desktop/medfound/about-the-media-session)

[MFCreatePMPMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatepmpmediasession)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Session](https://learn.microsoft.com/windows/desktop/medfound/media-session)