# DXVA2_ExtendedFormat structure

## Description

Describes the format of a video stream.

## Members

### `SampleFormat`

Describes the interlacing of the video frames. Contains a value from the [DXVA2_SampleFormat](https://learn.microsoft.com/windows/desktop/api/dxva2api/ne-dxva2api-dxva2_sampleformat) enumeration.

### `VideoChromaSubsampling`

Describes the chroma siting. Contains a value from the [DXVA2_VideoChromaSubSampling](https://learn.microsoft.com/windows/desktop/api/dxva2api/ne-dxva2api-dxva2_videochromasubsampling) enumeration.

### `NominalRange`

Describes the nominal range of the Y'CbCr or RGB color data. Contains a value from the [DXVA2_NominalRange](https://learn.microsoft.com/windows/desktop/api/dxva2api/ne-dxva2api-dxva2_nominalrange) enumeration.

### `VideoTransferMatrix`

Describes the transform from Y'PbPr (component video) to studio R'G'B'. Contains a value from the [DXVA2_VideoTransferMatrix](https://learn.microsoft.com/windows/desktop/api/dxva2api/ne-dxva2api-dxva2_videotransfermatrix) enumeration.

### `VideoLighting`

Describes the intended viewing conditions. Contains a value from the [DXVA2_VideoLighting](https://learn.microsoft.com/windows/desktop/api/dxva2api/ne-dxva2api-dxva2_videolighting) enumeration.

### `VideoPrimaries`

Describes the color primaries. Contains a value from the [DXVA2_VideoPrimaries](https://learn.microsoft.com/windows/desktop/api/dxva2api/ne-dxva2api-dxva2_videoprimaries) enumeration.

### `VideoTransferFunction`

Describes the gamma correction transfer function. Contains a value from the [DXVA2_VideoTransferFunction](https://learn.microsoft.com/windows/desktop/api/dxva2api/ne-dxva2api-dxva2_videotransferfunction) enumeration.

### `value`

Use this member to access all of the bits in the union.

## Remarks

Most of the values in this structure can be translated directly to and from [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) attributes. For a code example that fills in the values from an **IMFMediaType** pointer, see [DXVA2_VideoDesc](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videodesc).

## See also

[Extended Color Information](https://learn.microsoft.com/windows/desktop/medfound/extended-color-information)

[IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)