# TBMETRICS structure

## Description

Defines the metrics of a toolbar that are used to shrink or expand toolbar items.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the **TBMETRICS** structure.

### `dwMask`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Mask that determines the metric to retrieve. It can be any combination of the following:

| Value | Meaning |
| --- | --- |
| TBMF_PAD | Retrieve the **cxPad** and **cyPad** values. |
| TBMF_BARPAD | Retrieve the **cxBarPad** and **cyBarPad** values. |
| TBMF_BUTTONSPACING | Retrieve the **cxButtonSpacing** and **cyButtonSpacing** values. |

### `cxPad`

Type: **int**

Width of the padding inside the toolbar buttons, between the content and the edge of the button.

### `cyPad`

Type: **int**

Height of the padding inside the toolbar buttons, between the content and the edge of the button.

### `cxBarPad`

Type: **int**

Width of the toolbar. Not used.

### `cyBarPad`

Type: **int**

Height of the toolbar. Not used.

### `cxButtonSpacing`

Type: **int**

Width of the space between toolbar buttons.

### `cyButtonSpacing`

Type: **int**

Height of the space between toolbar buttons.

## Remarks

The metrics specified by **TBMETRICS** structure are used to size the non-animating buttons on a toolbar. Button can shrink or expand so that all visible items fit on the window.

The padding values are used to create a blank area between the edge of the button and the button's image and/or text. Where and how much padding is actually applied depends on the type of the button and whether it has an image. The horizontal padding is applied to both the right and left of the button, and the vertical padding is applied to both the top and bottom of the button. Padding is only applied to buttons that have the [TBSTYLE_AUTOSIZE](https://learn.microsoft.com/windows/desktop/Controls/toolbar-control-and-button-styles) style.

Although values for **cxBarPad** and **cyBarPad** can be set and retrieved they currently have no effect and are not used.