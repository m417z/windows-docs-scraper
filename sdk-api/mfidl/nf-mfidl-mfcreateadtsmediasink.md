# MFCreateADTSMediaSink function

## Description

Creates an instance of the audio data transport stream (ADTS) media sink.

## Parameters

### `pTargetByteStream` [in]

A pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of a byte stream. The media sink writes the ADTS stream to this byte stream. The byte stream must be writable.

### `pAudioMediaType` [in]

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface. This parameter specifies the media type for the ADTS stream. The media type must contain the following attributes.

| Attribute | Value |
| --- | --- |
| [MF_MT_MAJOR_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-major-type-attribute) | **MFMediaType_Audio** |
| [MF_MT_SUBTYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-subtype-attribute) | **MFAudioFormat_AAC** |
| [MF_MT_AAC_PAYLOAD_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-aac-payload-type) | 0 (raw AAC) or 1 (ADTS) |

### `ppMediaSink` [out]

Receives a pointer to the [IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The ADTS media sink converts Advanced Audio Coding (AAC) audio packets into an ADTS stream. The primary use for this media sink is to stream ADTS over a network. The output is not an audio file, but a stream of audio frames with ADTS headers.

The media sink can accept raw AAC frames ([MF_MT_AAC_PAYLOAD_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-aac-payload-type) = 0) or ADTS packets (MF_MT_AAC_PAYLOAD_TYPE = 1). If the input is raw AAC, the media sink inserts an ADTS header at the start of each audio frame. If the input is ADTS packets, the media sink passes the packets through to the byte stream, without modification.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)