# IInkOverlay::HitTestSelection

## Description

Determines what portion of the selection was hit during a hit test.

## Parameters

### `x` [in]

The x-position, in pixels, of the hit test.

### `y` [in]

The y-position, in pixels, of the hit test.

### `SelArea` [out]

The value from the [SelectionHitResult](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-selectionhitresult) enumeration,which specifies which part of a selection, if any, was hit during a hit test.

## Return value

| Return code | Description |
| --- | --- |
| **East** | The east side sizing handle was hit. |
| **None** | No part of the selection was hit. |
| **North** | The north side sizing handle was hit. |
| **Northeast** | The northeast corner sizing handle was hit. |
| **Northwest** | The northwest corner sizing handle was hit. |
| **Selection** | The selection itself was hit (no selection handle was hit). |
| **South** | The south side sizing handle was hit. |
| **Southeast** | The southeast corner sizing handle was hit. |
| **Southwest** | The southwest corner sizing handle was hit. |
| **West** | The west side sizing handle was hit. |

## See also

[IInkOverlay](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkoverlay)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)

[SelectionHitResult Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-selectionhitresult)