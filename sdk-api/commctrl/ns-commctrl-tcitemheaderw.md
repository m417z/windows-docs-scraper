# TCITEMHEADERW structure

## Description

Specifies or receives the attributes of a tab. It is used with the [TCM_INSERTITEM](https://learn.microsoft.com/windows/desktop/Controls/tcm-insertitem), [TCM_GETITEM](https://learn.microsoft.com/windows/desktop/Controls/tcm-getitem), and [TCM_SETITEM](https://learn.microsoft.com/windows/desktop/Controls/tcm-setitem) messages. This structure supersedes the
**TC_ITEMHEADER** structure.

## Members

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value that specifies which members to retrieve or set. This member can be a combination of the following values:

| Value | Meaning |
| --- | --- |
| **TCIF_IMAGE** | The **iImage** member is valid. |
| **TCIF_RTLREADING** | The string pointed to by **pszText** will be displayed in the direction opposite to the text in the parent window. |
| **TCIF_TEXT** | The **pszText** member is valid. |

### `lpReserved1`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved member. Do not use.

### `lpReserved2`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved member. Do not use.

### `pszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Address of a null-terminated string that contains the tab text if item information is being set. If item information is being retrieved, this member specifies the address of the buffer that receives the tab text.

### `cchTextMax`

Type: **int**

Size of the buffer pointed to by the pszText member. If the structure is not receiving information, this member is ignored.

### `iImage`

Type: **int**

Index into the tab control's image list, or -1 if there is no image for the tab.

## Remarks

Typically, windows display text left-to-right (LTR). Windows can be
*mirrored* to display languages such as Hebrew or Arabic that read right-to-left (RTL). Ordinarily,
**pszText** will be displayed in the same direction as the text in its parent window. If TCIF_RTLREADING is set,
**pszText** will read in the opposite direction from the text in the parent window.

> [!NOTE]
> The commctrl.h header defines TCITEMHEADER as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).