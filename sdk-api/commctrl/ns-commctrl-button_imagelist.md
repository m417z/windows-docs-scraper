# BUTTON_IMAGELIST structure

## Description

Contains information about an image list that is used with a button control.

## Members

### `himl`

Type: **HIMAGELIST**

A handle to the image list. The provider retains ownership of the image list and is ultimately responsible for its disposal. Under Windows Vista, you can pass BCCL_NOGLYPH in this parameter to indicate that no glyph should be displayed.

### `margin`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) that specifies the margin around the icon.

### `uAlign`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A **UINT** that specifies the alignment to use. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BUTTON_IMAGELIST_ALIGN_LEFT** | Align the image with the left margin. |
| **BUTTON_IMAGELIST_ALIGN_RIGHT** | Align the image with the right margin. |
| **BUTTON_IMAGELIST_ALIGN_TOP** | Align the image with the top margin |
| **BUTTON_IMAGELIST_ALIGN_BOTTOM** | Align the image with the bottom margin |
| **BUTTON_IMAGELIST_ALIGN_CENTER** | Center the image. |

## See also

[BCM_GETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/bcm-getimagelist)

[BCM_SETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/bcm-setimagelist)

[Button_GetImageList](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-button_getimagelist)

[Button_SetImageList](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-button_setimagelist)

[Buttons](https://learn.microsoft.com/windows/desktop/Controls/buttons)

**Conceptual**

**Reference**