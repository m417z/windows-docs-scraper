# _DXVADDI_EXTENDEDFORMAT structure

## Description

The DXVADDI_EXTENDEDFORMAT structure describes the extended format of the video frame.

## Members

### `SampleFormat` [in]

A UINT value that specifies how a video frame is sampled. The eight bits are defined by one of the values in the [DXVADDI_SAMPLEFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvaddi_sampleformat) enumeration type.

### `VideoChromaSubsampling` [in]

The chroma encoding scheme for Y'Cb'Cr' data. The four bits are defined by a bitwise OR of the values in the [DXVADDI_VIDEOCHROMASUBSAMPLING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvaddi_videochromasubsampling) enumeration type.

### `NominalRange` [in]

A UINT value that specifies whether sample data includes headroom (that is, values beyond 1.0 white) and toeroom (that is, superblacks below the reference 0.0 black). The three bits are defined by one of the values in the [DXVADDI_NOMINALRANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvaddi_nominalrange) enumeration type.

### `VideoTransferMatrix` [in]

The conversion matrix from Y'Cb'Cr' to (studio) R'G'B'. The three bits are defined by one of the values in the [DXVADDI_VIDEOTRANSFERMATRIX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvaddi_videotransfermatrix) enumeration type.

### `VideoLighting` [in]

Lighting conditions for viewing video. The four bits are defined by one of the values in the [DXVADDI_VIDEOLIGHTING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvaddi_videolighting) enumeration type.

### `VideoPrimaries` [in]

Color primaries, which state which RGB basis functions are used. The five bits are defined by one of the values in the [DXVADDI_VIDEOPRIMARIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvaddi_videoprimaries) enumeration type.

### `VideoTransferFunction` [in]

The conversion function from R'G'B' to RGB. The five bits are defined by the [DXVADDI_VIDEOTRANSFERFUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvaddi_videotransferfunction) enumeration type.

### `Value`

A 32-bit value that describes the extended format of the video frame.

## See also

[DXVADDI_VIDEODESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc)