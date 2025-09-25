# MFCreateAC3MediaSink function

## Description

Creates an instance of the AC-3 media sink.

## Parameters

### `pTargetByteStream` [in]

A pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of a byte stream. The media sink writes the AC-3 file to this byte stream. The byte stream must be writable.

### `pAudioMediaType` [in]

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface. This parameter specifies the media type for the AC-3 audio stream. The media type must contain the following attributes.

| Attribute | Value |
| --- | --- |
| [MF_MT_MAJOR_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-major-type-attribute) | **MFMediaType_Audio** |
| [MF_MT_SUBTYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-subtype-attribute) | **MFAudioFormat_Dolby_AC3** or **MFAudioFormat_Dolby_DDPlus** |

### `ppMediaSink` [out]

Receives a pointer to the [IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The AC-3 media sink takes compressed AC-3 audio as input and writes the audio to the byte stream without modification. The primary use for this media sink is to stream AC-3 audio over a network. The media sink does not perform AC-3 audio encoding.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)