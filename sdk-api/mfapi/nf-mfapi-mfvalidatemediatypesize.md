# MFValidateMediaTypeSize function

## Description

Validates the size of a buffer for a video format block.

## Parameters

### `FormatType` [in]

GUID that specifies the type of format block. It must be one of the following values:

#### FORMAT_DvInfo

#### FORMAT_MFVideoFormat

#### FORMAT_MPEG2Video

#### FORMAT_MPEGStreams

#### FORMAT_MPEGVideo

#### FORMAT_VideoInfo

#### FORMAT_VideoInfo2

#### FORMAT_WaveFormatEx

### `pBlock` [in]

Pointer to a buffer that contains the format block.

### `cbSize` [in]

Size of the *pBlock* buffer, in bytes.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The buffer that contains the format block is large enough. |
| **MF_E_INVALIDMEDIATYPE** | The buffer that contains the format block is too small, or the format block is not valid. |
| **MF_E_UNSUPPORTED_FORMAT** | This function does not support the specified format type. |

## Remarks

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)