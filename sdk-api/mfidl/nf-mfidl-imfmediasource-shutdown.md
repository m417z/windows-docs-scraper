# IMFMediaSource::Shutdown

## Description

Shuts down the media source and releases the resources it is using.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the application creates the media source, either directly or through the source resolver, the application is responsible for calling **Shutdown** to avoid memory or resource leaks.

After this method is called, methods on the media source and all of its media streams return MF_E_SHUTDOWN (except for **IUnknown** methods).

## See also

[IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource)

[Media Sources](https://learn.microsoft.com/windows/desktop/medfound/media-sources)