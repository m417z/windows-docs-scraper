# IAMDeviceRemoval::DeviceInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DeviceInfo` method retrieves information about the device.

## Parameters

### `pclsidInterfaceClass` [out]

Receives a GUID that specifies the device interface class.

### `pwszSymbolicLink` [out]

Receives a pointer to a string that contains the Plug and Play (PnP) device path for the device. The caller must release the string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree). This parameter can be **NULL**.

## Return value

If the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

For more information about the device interface classes and device paths, see Device I/O in the Windows SDK documentation.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMDeviceRemoval Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamdeviceremoval)