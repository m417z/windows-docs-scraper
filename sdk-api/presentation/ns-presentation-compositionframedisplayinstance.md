## Description

Represents a single instance of the content shown on a single output.

## Members

### `outputAdapterLUID`

Type: **LUID**

A locally unique ID (LUID) that refers to the display adapter (or output) that this instance corresponds to.

### `outputVidPnSourceId`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

An integer that identifies a video present source on the display adapter (or output).

### `outputUniqueId`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The unique ID of the display adapter (or output).

### `instanceKind`

Type: **[CompositionFrameInstanceKind](https://learn.microsoft.com/windows/win32/api/presentation/ne-presentation-compositionframeinstancekind)**

The kind of instance.

### `finalTransform`

Type: **[PresentationTransform](https://learn.microsoft.com/windows/win32/api/presentationtypes/ns-presentationtypes-presentationtransform)**

The accumulated transform on screen of displayed content, including all transforms of ancestor visuals, if applicable.

### `requiredCrossAdapterCopy`

Type: **[BOOLEAN](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

`TRUE` if a copy took place to display this instance due to the destination being a different adapter than the allocation's adapter; otherwise, `FALSE`.

### `colorSpace`

Type: **[DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/win32/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type)**

The color space type of the output this instance was shown on.

## Remarks

## See also