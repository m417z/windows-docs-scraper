# DXVA2_VideoDesc structure

## Description

Describes a video stream for a DXVA decoder device or video processor device.

## Members

### `SampleWidth`

Width of the video frame, in pixels.

### `SampleHeight`

Height of the video frame, in pixels.

### `SampleFormat`

Additional details about the video format, specified as a [DXVA2_ExtendedFormat](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_extendedformat) structure.

### `Format`

Surface format, specified as a **D3DFORMAT** value or FOURCC code. A FOURCC code can be constructed using the **D3DFORMAT** or **MAKEFOURCC** macros.

### `InputSampleFreq`

Frame rate of the input video stream, specified as a [DXVA2_Frequency](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_frequency) structure.

### `OutputFrameFreq`

Frame rate of the output video, specified as a [DXVA2_Frequency](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_frequency) structure.

### `UABProtectionLevel`

Level of data protection required when the user accessible bus (UAB) is present. If **TRUE**, the video must be protected when a UAB is present. If **FALSE**, the video is not required to be protected.

### `Reserved`

Reserved. Must be zero.

## Remarks

The **InputSampleFreq** member gives the frame rate of the decoded video stream, as received by the video renderer. The **OutputFrameFreq** member gives the frame rate of the video that is displayed after deinterlacing. If the input video is interlaced and the samples contain interleaved fields, the output frame rate is twice the input frame rate. If the input video is progressive or contains single fields, the output frame rate is the same as the input frame rate.

Decoders should set the values of **InputSampleFreq** and **OutputFrameFreq** if the frame rate is known. Otherwise, set these members to 0/0 to indicate an unknown frame rate.

#### Examples

The following code converts a Media Foundation media type, represented using the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface, into a **DXVA2_VideoDesc** structure.

```cpp
// Fills in the DXVA2_ExtendedFormat structure.
void GetDXVA2ExtendedFormatFromMFMediaType(
    IMFMediaType *pType,
    DXVA2_ExtendedFormat *pFormat
)
{
    // Get the interlace mode.
    MFVideoInterlaceMode interlace =
        (MFVideoInterlaceMode)MFGetAttributeUINT32(
            pType, MF_MT_INTERLACE_MODE, MFVideoInterlace_Unknown
         );

    // The values for interlace mode translate directly, except for mixed
    // interlace or progressive mode.

    if (interlace == MFVideoInterlace_MixedInterlaceOrProgressive)
    {
        // Default to interleaved fields.
        pFormat->SampleFormat = DXVA2_SampleFieldInterleavedEvenFirst;
    }
    else
    {
        pFormat->SampleFormat = (UINT)interlace;
    }

    // The remaining values translate directly.

    // Use the "no-fail" attribute functions and default to "unknown."

    pFormat->VideoChromaSubsampling = MFGetAttributeUINT32(
        pType, MF_MT_VIDEO_CHROMA_SITING, MFVideoChromaSubsampling_Unknown);

    pFormat->NominalRange = MFGetAttributeUINT32(
        pType, MF_MT_VIDEO_NOMINAL_RANGE, MFNominalRange_Unknown);

    pFormat->VideoTransferMatrix = MFGetAttributeUINT32(
        pType, MF_MT_YUV_MATRIX, MFVideoTransferMatrix_Unknown);

    pFormat->VideoLighting = MFGetAttributeUINT32(
        pType, MF_MT_VIDEO_LIGHTING, MFVideoLighting_Unknown);

    pFormat->VideoPrimaries = MFGetAttributeUINT32(
        pType, MF_MT_VIDEO_PRIMARIES, MFVideoPrimaries_Unknown);

    pFormat->VideoTransferFunction = MFGetAttributeUINT32(
        pType, MF_MT_TRANSFER_FUNCTION, MFVideoTransFunc_Unknown);

}

HRESULT ConvertMFTypeToDXVAType(IMFMediaType *pType, DXVA2_VideoDesc *pDesc)
{
    ZeroMemory(pDesc, sizeof(*pDesc));

    GUID                    subtype = GUID_NULL;
    UINT32                  width = 0;
    UINT32                  height = 0;
    UINT32                  fpsNumerator = 0;
    UINT32                  fpsDenominator = 0;

    // The D3D format is the first DWORD of the subtype GUID.
    HRESULT hr = pType->GetGUID(MF_MT_SUBTYPE, &subtype);
    if (FAILED(hr))
    {
        goto done;
    }

    pDesc->Format = (D3DFORMAT)subtype.Data1;

    // Frame size.
    hr = MFGetAttributeSize(pType, MF_MT_FRAME_SIZE, &width, &height);
    if (FAILED(hr))
    {
        goto done;
    }

    pDesc->SampleWidth = width;
    pDesc->SampleHeight = height;

    // Frame rate.
    hr = MFGetAttributeRatio(pType, MF_MT_FRAME_RATE, &fpsNumerator, &fpsDenominator);
    if (FAILED(hr))
    {
        goto done;
    }

    pDesc->InputSampleFreq.Numerator = fpsNumerator;
    pDesc->InputSampleFreq.Denominator = fpsDenominator;

    // Extended format information.
    GetDXVA2ExtendedFormatFromMFMediaType(pType, &pDesc->SampleFormat);

    // For progressive or single-field types, the output frequency is the same as
    // the input frequency. For interleaved-field types, the output frequency is
    // twice the input frequency.
    pDesc->OutputFrameFreq = pDesc->InputSampleFreq;

    if ((pDesc->SampleFormat.SampleFormat == DXVA2_SampleFieldInterleavedEvenFirst) ||
        (pDesc->SampleFormat.SampleFormat == DXVA2_SampleFieldInterleavedOddFirst))
    {
        pDesc->OutputFrameFreq.Numerator *= 2;
    }

done:
    return hr;
}

```

## See also

[IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)