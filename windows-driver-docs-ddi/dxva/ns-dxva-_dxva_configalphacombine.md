# _DXVA_ConfigAlphaCombine structure

## Description

The DXVA_ConfigAlphaCombine structure is sent by the host decoder to the accelerator to set the configuration for alpha-blending combination operations.

## Members

### `dwFunction`

Indicates the type of query or response when using probing and locking commands. The most significant 24 bits of **dwFunction** is the [DXVA_ConfigQueryOrReplyFlag](https://learn.microsoft.com/windows-hardware/drivers/display/dxva-configqueryorreplyflag-and-dxva-configqueryorreplyfunc-variables) variable.

The least significant 4 bits of the *DXVA_ConfigQueryOrReplyFlag* variable contain status indicators for the query or response being performed.

The least significant 8 bits of **dwFunction** is the [bDXVA_Func variable](https://learn.microsoft.com/windows-hardware/drivers/display/bdxva-func-variable) that, in this case, is equal to 3.

### `dwReservedBits`

Specifies the reserved bits used for packing and alignment. This member must be zero.

### `bConfigBlendType`

Specifies the type of alpha-blend combinations to be performed. Zero indicates front-end buffer-to-buffer blend, and 1 indicates back-end hardware blend.

The preferred value for an accelerator to support is zero.

### `bConfigPictureResizing`

Specifies whether the **PictureSourceRect16thPel** member of [DXVA_BlendCombination](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_blendcombination) for graphic blending may differ in width and height from the **PictureDestinationRect** member of DXVA_BlendCombination (adjusted for the one-sixteenth sample scaling of **PictureSourceRect16thPel**). This member also specifies whether the values in **PictureSourceRect16thPel** are multiples of 16, thus requiring the source picture to be resampled by the accelerator. A value of 1 indicates that resampling (whether for resizing or for subpixel accuracy) is supported; a value of zero indicates that it is not.

### `bConfigOnlyUsePicDestRectArea`

Specifies whether the decoder can perform operations that use values for areas of a destination picture outside the area defined by the **PictureDestinationRect** member of the DXVA_BlendCombination structure. The value zero indicates that areas outside of **PictureDestinationRect** can be specified and displayed by the blend combination commands. The value 1 indicates that the decoder cannot rely on the values of, or display, any region of the blended surface outside of the area specified by **PictureDestinationRect**.

### `bConfigGraphicResizing`

Indicates whether alpha blending is supported in graphic image resizing. A value of 1 indicates that it is; a value of zero indicates that it is not. **bConfigGraphicResizing** specifies whether the **GraphicSourceRect** member of [DXVA_BlendCombination](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_blendcombination) (for subpicture blending) may differ in size from the **GraphicDestinationRect** member of DXVA_BlendCombination. If these values are different, the alpha-blending graphic must be resampled by the accelerator.

### `bConfigWholePlaneAlpha`

Specifies whether a whole-plane alpha opacity value can be applied to the graphic image. A value of 1 indicates that a whole-plane alpha can be applied; a value of zero indicates that it cannot.

## See also

[DXVA_BlendCombination](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_blendcombination)