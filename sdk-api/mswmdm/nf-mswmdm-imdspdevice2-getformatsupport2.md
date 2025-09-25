# IMDSPDevice2::GetFormatSupport2

## Description

The **GetFormatSupport2** method gets the formats supported by a device, including audio and video codecs, and MIME file formats.

## Parameters

### `dwFlags` [in]

**DWORD** containing audio formats, video formats, and MIME types. This flag specifies what the application is requesting the service provider to fill in. The caller can set one or more of the following three values.

| Value | Description |
| --- | --- |
| WMDM_GET_FORMAT_SUPPORT_AUDIO | Service provider should fill in audio parameters. |
| WMDM_GET_FORMAT_SUPPORT_VIDEO | Service provider should fill in video parameters. |
| WMDM_GET_FORMAT_SUPPORT_FILE | Service provider should fill in file parameters. |

### `ppAudioFormatEx` [out]

Pointer to an array of [_WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex) structures containing information about audio codecs and bit rates supported by the device.

### `pnAudioFormatCount` [out]

Pointer to an integer containing the audio format count.

### `ppVideoFormatEx` [out]

Pointer to an array of [_VIDEOINFOHEADER](https://learn.microsoft.com/windows/desktop/WMDM/-videoinfoheader) structures containing information about video codecs and formats supported by the device.

### `pnVideoFormatCount` [out]

Pointer to an integer containing the video format count.

### `ppFileType` [out]

Pointer to an array of [WMFILECAPABILITIES](https://learn.microsoft.com/windows/desktop/WMDM/wmfilecapabilities) structures containing information about file types supported by the device.

### `pnFileTypeCount` [out]

Pointer to an integer containing the file format count.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPDevice2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice2)