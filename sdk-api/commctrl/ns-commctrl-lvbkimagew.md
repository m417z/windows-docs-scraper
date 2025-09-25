# LVBKIMAGEW structure

## Description

Contains information about the background image of a list-view control. This structure is used for both setting and retrieving background image information.

## Members

### `ulFlags`

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This member may be one or more of the following flags. You can use the LVBKIF_SOURCE_MASK value to mask off all but the source flags. You can use the LVBKIF_STYLE_MASK value to mask off all but the style flags.

| Value | Meaning |
| --- | --- |
| **LVBKIF_SOURCE_NONE** | The list-view control has no background image. |
| **LVBKIF_SOURCE_HBITMAP** | A background bitmap is supplied via the **hbm** member of **LVBKIMAGE**. If the message [LVM_SETBKIMAGE](https://learn.microsoft.com/windows/desktop/Controls/lvm-setbkimage) succeeds, then the list-view takes ownership of the bitmap. |
| **LVBKIF_SOURCE_URL** | The **pszImage** member contains the URL of the background image. |
| **LVBKIF_STYLE_NORMAL** | The background image is displayed normally. |
| **LVBKIF_STYLE_TILE** | The background image will be tiled to fill the entire background of the control. |
| **LVBKIF_FLAG_TILEOFFSET** | Specify the coordinates of the first tile. This flag is valid only if the **LVBKIF_STYLE_TILE** flag is also specified. If this flag is not specified, the first tile begins at the upper-left corner of the client area. If you use ComCtl32.dll  [Version 6.0](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions)  the **xOffsetPercent** and **yOffsetPercent** fields contain pixels, not percentage values, to specify the coordinates of the first tile. Comctl32.dll version 6 is not redistributable but it is included in Windows or later. Also, you must specify Comctl32.dll version 6 in a manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview). |
| **LVBKIF_TYPE_WATERMARK** | A watermark background bitmap is supplied via the **hbm** member of **LVBKIMAGE**. If the [LVM_SETBKIMAGE](https://learn.microsoft.com/windows/desktop/Controls/lvm-setbkimage) message succeeds, then the list-view control takes ownership of the bitmap. |
| **LVBKIF_FLAG_ALPHABLEND** | Valid only when LVBKIF_TYPE_WATERMARK is also specified. This flag indicates the bitmap provided via LVBKIF_TYPE_WATERMARK contains a valid alpha channel. |

### `hbm`

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The handle of the background bitmap. This member is valid only if the
**LVBKIF_SOURCE_HBITMAP** flag is set in
**ulFlags**.

### `pszImage`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Address of a NULL-terminated string that contains the URL of the background image. This member is valid only if the
**LVBKIF_SOURCE_URL** flag is set in
**ulFlags**. This member must be initialized to point to the buffer that contains or receives the text before sending the message.

### `cchImageMax`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the buffer at the address in
**pszImage**. If information is being sent to the control, this member is ignored.

### `xOffsetPercent`

Type: **int**

Percentage of the control's client area that the image should be offset horizontally. For example, at 0 percent, the image will be displayed against the left edge of the control's client area. At 50 percent, the image will be displayed horizontally centered in the control's client area. At 100 percent, the image will be displayed against the right edge of the control's client area. This member is valid only when
**LVBKIF_STYLE_NORMAL** is specified in
**ulFlags**. If both **LVBKIF_FLAG_TILEOFFSET** and **LVBKIF_STYLE_TILE** are specified in **ulFlags**, then the value specifies the pixel, not percentage offset, of the first tile. Otherwise, the value is ignored.

### `yOffsetPercent`

Type: **int**

Percentage of the control's client area that the image should be offset vertically. For example, at 0 percent, the image will be displayed against the top edge of the control's client area. At 50 percent, the image will be displayed vertically centered in the control's client area. At 100 percent, the image will be displayed against the bottom edge of the control's client area. This member is valid only when
**LVBKIF_STYLE_NORMAL** is specified in
**ulFlags**. If both **LVBKIF_FLAG_TILEOFFSET** and **LVBKIF_STYLE_TILE** are specified in **ulFlags**, then the value specifies the pixel, not percentage offset, of the first tile. Otherwise, the value is ignored.

## Remarks

This structure is used with the [LVM_GETBKIMAGE](https://learn.microsoft.com/windows/desktop/Controls/lvm-getbkimage) and [LVM_SETBKIMAGE](https://learn.microsoft.com/windows/desktop/Controls/lvm-setbkimage) messages.

> [!NOTE]
> The commctrl.h header defines LVBKIMAGE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).