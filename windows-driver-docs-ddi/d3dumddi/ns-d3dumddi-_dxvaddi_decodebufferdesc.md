# _DXVADDI_DECODEBUFFERDESC structure

## Description

The DXVADDI_DECODEBUFFERDESC structure describes a buffer that is currently passed from the host decoder to the accelerator.

## Members

### `hBuffer` [in]

A handle to the buffer.

### `CompressedBufferType` [in]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the buffer.

### `BufferIndex` [in]

Reserved. Do not use this member. For more information, see the Remarks section.

### `DataOffset` [in]

The offset of the relevant data from the beginning of the buffer, in bytes. The use of this member is currently restricted to the value zero.

### `DataSize` [in]

The amount of relevant data in the buffer, in bytes. The location of the last byte of content in the buffer is the value of **DataOffset** plus the value of **DataSize** minus 1.

### `FirstMBaddress` [in]

The macroblock address of the first macroblock in the buffer that is passed to the accelerator. The macroblock address is given in raster scan order. The address is determined by the members of the [DXVA_PictureParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_pictureparameters) structure. The following table shows examples of macroblock addresses.

| **Macroblock** | **Address** |
|:--|:--|
| Top-left | Zero |
| Top-right | wPicWidthInMBminus1 of DXVA_PictureParameters. |
| Bottom-left | wPicHeightInMBminus1 x (wPicWidthInMBminus1+1). Members of DXVA_PictureParameters. |
| Bottom-right | (wPicHeightInMBminus1+1) x (wPicWidthInMBminus1+1)-1. Members of DXVA_PictureParame |

The **FirstMBaddress** member must be zero if the data buffer is one of the following types: picture decoding parameters, inverse-quantization matrix, slice control, bitstream data, AYUV, IA44/AI44, DPXD, Highlight, and DCCMD.

If the data buffer is a residual difference block data buffer, **FirstMBaddress** must have the same value as for the corresponding macroblock control command buffer.

### `NumMBsInBuffer` [in]

The number of macroblocks of data in the buffer, including skipped macroblocks. This member must be zero if the data buffer is one of the following types: picture decoding parameters, inverse-quantization matrix, AYUV, IA44/AI44, DPXD, Highlight, or DCCMD.

The value for **NumMBsInBuffer** depends on the type of data buffer that is being used, as shown in the following table.

| **Buffer type** | **Value of NumMBsInBuffer** |
|:--|:--|
| Macroblock control command | The sum of all of the values for MBskipsFollowing, added to the number of macroblock control commands in the macroblock control command buffer. |
| Residual difference block | The same value as for the corresponding macroblock control command buffer. |
| Slice-control command | The value of the wNumberMBsInSlice member of the [DXVA_SliceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_sliceinfo) structure in the slice-control buffer. |
| Bitstream | The same value as for the corresponding slice-control command buffer. |

### `Width` [in]

Reserved. Do not use this member. For more information, see the Remarks section.

### `Height` [in]

Reserved. Do not use this member. For more information, see the Remarks section.

### `Stride` [in]

Reserved. Do not use this member. For more information, see the Remarks section.

### `ReservedBits` [in]

Reserved bits that are used for packing and alignment. This member must be zero.

### `pCipherCounter` [in]

A pointer to a [DXVADDI_PVP_HW_IV](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_pvp_hw_iv) structure that contains a 128-bit protected video path (PVP) value.

## Remarks

An array of DXVADDI_DECODEBUFFERDESC structures is referred to as a *buffer description list*. When a set of buffers is sent from the host decoder to the hardware accelerator, a buffer description list is sent to describe the buffers. The buffer description list contains one DXVADDI_DECODEBUFFERDESC structure for each buffer in this set. The buffer description list starts with a DXVADDI_DECODEBUFFERDESC structure for the first buffer of the first type, followed by a DXVADDI_DECODEBUFFERDESC structure for the next buffer of the same type, and so on. The buffer description list then continues with a DXVADDI_DECODEBUFFERDESC structure for the first buffer of the next type, and so on. This entire list is contained in a [D3DDDIARG_DECODEEXECUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decodeexecute) structure.

Because Microsoft DirectX Video Acceleration (VA) version 2.0 uses Microsoft Direct3D surfaces rather than the private surfaces that DirectX VA 1.0 uses, the user-mode display driver obtains values for the index, width, height, and stride from the given compressed buffer type rather than from the values in the **BufferIndex**, **Width**, **Height**, and **Stride** members. In fact, the Microsoft Direct3D runtime sets these members to zero.

## See also

[D3DDDIARG_DECODEEXECUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_decodeexecute)

[DXVADDI_PVP_HW_IV](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_pvp_hw_iv)

[DXVA_PictureParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_pictureparameters)

[DXVA_SliceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_sliceinfo)