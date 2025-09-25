# _DXVA_SliceInfo structure

## Description

The DXVA_SliceInfo structure is sent by the host decoder to the accelerator to specify the slice-level parameters of a slice of bitstream data for off-host bitstream compressed picture decoding.

## Members

### `wHorizontalPosition`

Specifies the horizontal position of the first macroblock of the slice expressed in units of macroblocks, with zero indicating the left-most or top-most macroblock of the picture.

### `wVerticalPosition`

Specifies the vertical position of the first macroblock of the slice expressed in units of macroblocks, with zero indicating the left-most or top-most macroblock of the picture.

### `dwSliceBitsInBuffer`

Specifies the total number of bits in the corresponding bitstream data buffer that contain data for the current slice. This must be a multiple of eight for MPEG-1, MPEG-2, MPEG-4. It must also be in the slice-structured mode of H.263, because slice start codes in these cases are byte-aligned.

### `dwSliceDataLocation`

Specifies the location of the first byte containing data for the slice (for example, the location of a slice start code) in the bitstream data buffer. Must be zero if the start of the slice is not within the corresponding bitstream data buffer.

### `bStartCodeBitOffset`

Specifies the number of most significant bits of the byte at **dwSliceDataLocation** that do not contain data for the slice. **bStartCodeBitOffset** must be zero for MPEG-1, MPEG-2, and MPEG-4, because slice start codes in these specifications are byte-aligned. **bStartCodeBitOffset** could possibly be nonzero for H.261 and H.263, because these standards do not force byte alignment of GOB (group of blocks) start codes. This member must be in the range of zero through 7, and must be zero if the start of the slice is not within the corresponding bitstream data buffer. The most significant bits marked irrelevant for the current slice by **bStartCodeBitOffset** may contain data for a previous slice in the case of start codes that are not byte aligned (for example, in H.263 baseline mode).

### `bReservedBits`

Reserved bits used for packing and alignment. Must be zero.

### `wMBbitOffset`

Specifies the number of bits of slice header data prior to the first bit of macroblock layer data in the bitstream buffer. For example, if **wMBbitOffset** is 83, the macroblock layer data for the slice starts after 83 bits of slice header data. Must be zero if the start of the slice is not within the corresponding bitstream data buffer.

### `wNumberMBsInSlice`

Specifies the number of macroblocks of data in the slice, including skipped macroblocks. May be zero if this number cannot be readily determined from the header of the picture and the headers and initial macroblock data of the current and next slice in the bitstream, such as in the rectangular slice and arbitrary slice ordering submodes of the slice mode of H.263. Must not be zero for H.261, MPEG-1, MPEG-2, MPEG-4, or when not using the rectangular slice or arbitrary slice submodes of the slice-structured mode in H.263.

### `wQuantizerScaleCode`

The quantizer scaling code from the slice level of the bitstream, as specified in the particular video coding specification (ranging from 1 through 31 for H.261, H.262/MPEG-2, H.263, MPEG-1, and MPEG-4).

### `wBadSliceChopping`

Specifies the location of data within a slice for a corresponding bitstream data buffer. If zero, indicates that all bits for the slice are in the bitstream data buffer. If nonzero, indicates what part of the bits for the slice are missing from the corresponding bitstream data buffer as follows.

|Value|Description|
|--- |--- |
|1|The bits for the start of the slice are within the corresponding bitstream data buffer, and the bits for the end of the slice are not (because the bitstream data buffer is full).|
|2|The bits for the start of the slice are not within the corresponding bitstream data buffer (because the previous bitstream data buffer was full), but the bits for the end of the slice are within the corresponding bitstream data buffer.|
|3|The bits for the start of the slice are not within the corresponding bitstream data buffer (because the previous bitstream data buffer was full), and the bits for the end of the slice are also not within the corresponding bitstream data buffer (because the corresponding bitstream data buffer is also full).|

> [!NOTES]
> Nonzero values of **wBadSliceChopping** should generally be avoided by the host software decoder.

## Remarks

Slice-control buffers are provided to guide the operation of off-host VLD bitstream processing. Slice-control buffers are sent only when the **bConfigBitstreamRaw** member of [DXVA_ConfigPictureDecode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configpicturedecode) is 1. The host software decoder must determine the location of slice-level resynchronization points in the bitstream. A *slice* is defined to be a multimacroblock layer that includes a resynchronization point in the bitstream data.

In H.261 bitstreams, a GOB is considered a slice. In H.263 bitstreams, a sequence of one or more GOBs starting with a GOB start code and containing no additional GOB start codes, is considered a slice. A slice-control buffer must contain one or more DXVA_SliceInfo structures, according to the contents of a corresponding bitstream data buffer.

## See also

[DXVA_ConfigPictureDecode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configpicturedecode)