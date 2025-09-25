# NMHDDISPINFOA structure

## Description

Contains information used in handling [HDN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/hdn-getdispinfo) notification codes.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure containing information about this notification code.

### `iItem`

Type: **int**

The zero-based index of the item in the header control.

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A set of bit flags specifying which members of the structure must be filled in by the owner of the header control. This value can be a combination of the following values:

| Value | Meaning |
| --- | --- |
| **HDI_TEXT** | The **pszText** field must be filled in. |
| **HDI_IMAGE** | [Version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **iImage** field must be filled in. |
| **HDI_LPARAM** | The **lParam** field must be filled in. |
| **HDI_DI_SETITEM** | [Version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). A return value. Indicates that the header control should store the item information and not ask for it again. |

### `pszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a null-terminated string containing the text that will be displayed for the header item.

### `cchTextMax`

Type: **int**

The size of the buffer that
**pszText** points to.

### `iImage`

Type: **int**

The zero-based index of an image within the image list. The specified image will be displayed with the header item, but it does not take the place of the item's bitmap. If
**iImage** is set to I_IMAGECALLBACK, the control requests image information for this item by using an [HDN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/hdn-getdispinfo) notification code.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An application-defined value to associate with the item.

## Remarks

> [!NOTE]
> The commctrl.h header defines NMHDDISPINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).