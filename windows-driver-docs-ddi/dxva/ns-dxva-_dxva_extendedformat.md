# _DXVA_ExtendedFormat structure

## Description

The DXVA_ExtendedFormat structure describes the extended format of the video frame.

## Members

### `SampleFormat`

Specifies how a video frame is sampled. The 8 bits are defined by one of the enumerators in the [DXVA_SampleFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_sampleformat) enumeration type.

### `VideoChromaSubsampling`

Specifies the chroma encoding scheme for Y'Cb'Cr' data. The 4 bits are defined by an ORed combination of the enumerators in the [DXVA_VideoChromaSubsampling](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_videochromasubsampling) enumeration type.

### `NominalRange`

Specifies whether sample data includes headroom (values beyond 1.0 white) and toeroom (superblacks below the reference 0.0 black). The 3 bits are defined by one of the enumerators in the [DXVA_NominalRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_nominalrange) enumeration type.

### `VideoTransferMatrix`

Specifies the conversion matrix from Y'Cb'Cr' to (studio) R'G'B'. The 3 bits are defined by one of the enumerators in the [DXVA_VideoTransferMatrix](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_videotransfermatrix) enumeration type.

### `VideoLighting`

Specifies lighting conditions for viewing video. The 4 bits are defined by one of the enumerators in the [DXVA_VideoLighting](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_videolighting) enumeration type.

### `VideoPrimaries`

Specifies color primaries, which state which RGB basis functions are used. The 5 bits are defined by one of the enumerators in the [DXVA_VideoPrimaries](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_videoprimaries) enumeration type.

### `VideoTransferFunction`

Specifies the conversion function from R'G'B' to RGB. The 5 bits are defined by the [DXVA_VideoTransferFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_videotransferfunction) enumeration type.

## See also

[DXVA_NominalRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_nominalrange)

[DXVA_SampleFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_sampleformat)

[DXVA_VideoChromaSubsampling](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_videochromasubsampling)

[DXVA_VideoLighting](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_videolighting)

[DXVA_VideoPrimaries](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_videoprimaries)

[DXVA_VideoTransferFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_videotransferfunction)

[DXVA_VideoTransferMatrix](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ne-dxva-_dxva_videotransfermatrix)