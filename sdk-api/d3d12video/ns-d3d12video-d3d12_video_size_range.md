# D3D12_VIDEO_SIZE_RANGE structure

## Description

Describes the range of supported sizes for a video scaler.

## Members

### `MaxWidth`

The largest output width to which content can be scaled. The largest value allowed is **D3D12\_REQ\_TEXTURE2D\_U\_OR\_V\_DIMENSION** (16384).

### `MaxHeight`

The largest output height to which content can be scaled. The largest value allowed is **D3D12\_REQ\_TEXTURE2D\_U\_OR\_V\_DIMENSION** (16384).

### `MinWidth`

The smallest output width to which content can be scaled. The smallest allowed value is 1.

### `MinHeight`

The smallest output height to which content can be scaled. The smallest allowed value is 1.

## Remarks

## See also