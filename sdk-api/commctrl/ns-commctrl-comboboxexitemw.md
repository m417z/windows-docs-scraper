# COMBOBOXEXITEMW structure

## Description

Contains information about an item in a ComboBoxEx control.

## Members

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A set of bit flags that specify attributes of this structure or of an operation that is using this structure. The flags specify members that are valid or must be filled in. This member can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **CBEIF_DI_SETITEM** | Set this flag when processing [CBEN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/cben-getdispinfo); the ComboBoxEx control will retain the supplied information and will not request it again. |
| **CBEIF_IMAGE** | The **iImage** member is valid or must be filled in. |
| **CBEIF_INDENT** | The **iIndent** member is valid or must be filled in. |
| **CBEIF_LPARAM** | The **lParam** member is valid or must be filled in. |
| **CBEIF_OVERLAY** | The **iOverlay** member is valid or must be filled in. |
| **CBEIF_SELECTEDIMAGE** | The **iSelectedImage** member is valid or must be filled in. |
| **CBEIF_TEXT** | The **pszText** member is valid or must be filled in. |

### `iItem`

Type: **[INT_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based index of the item.

### `pszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a character buffer that contains or receives the item's text. If text information is being retrieved, this member must be set to the address of a character buffer that will receive the text. The size of this buffer must also be indicated in
**cchTextMax**. If this member is set to LPSTR_TEXTCALLBACK, the control will request the information by using the [CBEN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/cben-getdispinfo) notification codes.

### `cchTextMax`

Type: **int**

The length of **pszText**, in **TCHAR****s**. If text information is being set, this member is ignored.

### `iImage`

Type: **int**

The zero-based index of an image within the image list. The specified image will be displayed for the item when it is not selected. If this member is set to I_IMAGECALLBACK, the control will request the information by using [CBEN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/cben-getdispinfo) notification codes.

### `iSelectedImage`

Type: **int**

The zero-based index of an image within the image list. The specified image will be displayed for the item when it is selected. If this member is set to I_IMAGECALLBACK, the control will request the information by using [CBEN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/cben-getdispinfo) notification codes.

### `iOverlay`

Type: **int**

The one-based index of an overlay image within the image list. If this member is set to I_IMAGECALLBACK, the control will request the information by using [CBEN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/cben-getdispinfo) notification codes.

### `iIndent`

Type: **int**

The number of indent spaces to display for the item. Each indentation equals 10 pixels. If this member is set to I_INDENTCALLBACK, the control will request the information by using [CBEN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/cben-getdispinfo) notification codes.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value specific to the item.

## Remarks

> [!NOTE]
> The commctrl.h header defines COMBOBOXEXITEM as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).