# IMFSourceReader::SetCurrentPosition

## Description

Seeks to a new position in the media source.

## Parameters

### `guidTimeFormat` [in]

A GUID that specifies the *time format*. The time format defines the units for the *varPosition* parameter. The following value is defined for all media sources:

| Value | Meaning |
| --- | --- |
| **GUID_NULL** | 100-nanosecond units. |

Some media sources might support additional values.

### `varPosition` [in]

The position from which playback will be started. The units are specified by the *guidTimeFormat* parameter. If the *guidTimeFormat* parameter is **GUID_NULL**, set the variant type to **VT_I8**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | One or more sample requests are still pending. |

## Remarks

The **SetCurrentPosition** method does not guarantee exact seeking. The accuracy of the seek depends on the media content. If the media content contains a video stream, the **SetCurrentPosition** method typically seeks to the nearest key frame before the desired position. The distance between key frames depends on several factors, including the encoder implementation, the video content, and the particular encoding settings used to encode the content. The distance between key frame can vary within a single video file (for example, depending on scene complexity).

After seeking, the application should call [IMFSourceReader::ReadSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-readsample) and advance to the desired position.

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)