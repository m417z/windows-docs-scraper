# IWMDMDevice2::GetFormatSupport2

## Description

The **GetFormatSupport2** method retrieves the formats supported by the device, including audio and video codecs, and MIME file formats.

## Parameters

### `dwFlags` [in]

**DWORD** specifying audio formats, video formats, and MIME types. This flag specifies what the application is requesting the service provider to fill in. The caller can set one or more of the following three values.

| Value | Description |
| --- | --- |
| WMDM_GET_FORMAT_SUPPORT_AUDIO | Service provider should fill in audio parameters. |
| WMDM_GET_FORMAT_SUPPORT_VIDEO | Service provider should fill in video parameters. |
| WMDM_GET_FORMAT_SUPPORT_FILE | Service provider should fill in file parameters. |

### `ppAudioFormatEx` [out]

Pointer to an array of **_WAVEFORMATEX** structures specifying information about audio codecs and bit rates supported by the device. The memory for this parameter is allocated by Windows Media Device Manager, and must be released by the caller with the Win32 function **CoTaskMemFree**.

### `pnAudioFormatCount` [out]

Pointer to an integer specifying the audio format count.

### `ppVideoFormatEx` [out]

Pointer to an array of **_VIDEOFORMATEX** structures specifying information about video codes and formats supported by the device. The memory for this parameter is allocated by Windows Media Device Manager, and must be released by the caller with the Win32 function **CoTaskMemFree**.

### `pnVideoFormatCount` [out]

Pointer to an integer specifying the video format count.

### `ppFileType` [out]

Pointer to an array of **WMFILECAPABILITIES** file-type objects. The memory for this parameter is allocated by Windows Media Device Manager, and must be released by the caller with the Win32 function **CoTaskMemFree**.

### `pnFileTypeCount` [out]

Pointer to an integer specifying the file-type count.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method extends [IWMDMDevice::GetFormatSupport](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice-getformatsupport) to handle video formats. The recommended method for getting format support, however, is [IWMDMDevice3::GetFormatCapability](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-getformatcapability). If **GetFormatCapability** isn't supported, the device will probably not support video, and **GetFormatSupport** is probably sufficient.

## See also

[Discovering Device Format Capabilities](https://learn.microsoft.com/windows/desktop/WMDM/discovering-device-format-capabilities)

[IWMDMDevice2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice2)

[IWMDMDevice3::GetFormatCapability](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-getformatcapability)