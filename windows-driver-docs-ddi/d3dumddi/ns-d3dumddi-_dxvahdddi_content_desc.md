# _DXVAHDDDI_CONTENT_DESC structure

## Description

The DXVAHDDDI_CONTENT_DESC structure describes the video content that a decode device processes.

## Members

### `InputFrameFormat` [in]

A [DXVAHDDDI_FRAME_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_frame_format)-typed value that indicates the frame format of the input video stream.

### `InputFrameRate`

 [in] A [DXVAHDDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_rational) structure that specifies a fractional value that represents the frame rate of the input video stream.

### `InputWidth` [in]

The width, in pixels, of the input video stream.

### `InputHeight` [in]

The height, in pixels, of the input video stream.

### `OutputFrameRate`

 [in] A [DXVAHDDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_rational) structure that specifies a fractional value that represents the frame rate of the output.

### `OutputWidth` [in]

The width, in pixels, of the output video stream.

### `OutputHeight` [in]

The height, in pixels, of the output video stream.

## Remarks

The driver can use the information in the members of DXVAHDDDI_CONTENT_DESC to optimize its capabilities. For example, the driver might not require to expose costly capabilities for high-definition content and the de-interlacing capability for progressive content.

## See also

[DXVAHDDDI_FRAME_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_frame_format)

[DXVAHDDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_rational)