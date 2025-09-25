# PFND3DWDDM2_0DDI_VIDEOPROCESSORSETSTREAMMIRROR callback function

## Description

Indicates whether the stream should be flipped vertically or horizontally. Optional for Windows Display Driver Model (WDDM) 2.0, or later, drivers.

## Parameters

### `hDevice`

A handle to the display device (graphics context). The Direct3D runtime passed the user-mode driver this handle as the **hDevice** member of the [D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice) structure at device creation.

### `hVideoProcessor`

Handle to the video processor object.

### `StreamIndex`

Indicates the input stream.

### `Enable`

Indicates whether mirroring support is enabled or disabled.

### `FlipHorizontal`

Indicates whether the input stream should be flipped horizontally.

**Note** This should be ignored when **Enable** is **FALSE**.

### `FlipVertical`

Indicates whether the input stream should be flipped vertically.

**Note** This should be ignored when **Enable** is **FALSE**.

## Remarks

Operations are conceptually applied in the following order:

## See also

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)