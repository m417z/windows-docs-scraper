# BUTTON_SPLITINFO structure

## Description

Contains information that defines a split button ([BS_SPLITBUTTON](https://learn.microsoft.com/windows/desktop/Controls/button-styles) and [BS_DEFSPLITBUTTON](https://learn.microsoft.com/windows/desktop/Controls/button-styles) styles). Used with the [BCM_GETSPLITINFO](https://learn.microsoft.com/windows/desktop/Controls/bcm-getsplitinfo) and [BCM_SETSPLITINFO](https://learn.microsoft.com/windows/desktop/Controls/bcm-setsplitinfo) messages.

## Members

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A set of flags that specify which members of this structure contain data to be set or which members are being requested. Set this member to one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **BCSIF_GLYPH** | **himlGlyph** is valid. |
| **BCSIF_IMAGE** | **himlGlyph** is valid. Use when **uSplitStyle** is set to BCSS_IMAGE. |
| **BCSIF_SIZE** | **size** is valid. |
| **BCSIF_STYLE** | **uSplitStyle** is valid. |

### `himlGlyph`

Type: **HIMAGELIST**

A handle to the image list. The provider retains ownership of the image list and is ultimately responsible for its disposal.

### `uSplitStyle`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The split button style. Value must be one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **BCSS_ALIGNLEFT** | Align the image or glyph horizontally with the left margin. |
| **BCSS_IMAGE** | Draw an icon image as the glyph. |
| **BCSS_NOSPLIT** | No split. |
| **BCSS_STRETCH** | Stretch glyph, but try to retain aspect ratio. |

### `size`

Type: **[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)**

A [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that specifies the size of the glyph in **himlGlyph**.

## Remarks

The glyph is the image that appears on the part of the button that activates the dropdown list. By default, this is an inverted triangle. Multiple images can be added to the image list to provide different glyphs for different states of the button, such as hot and pressed.

## See also

[Buttons Overview](https://learn.microsoft.com/windows/desktop/Controls/buttons)