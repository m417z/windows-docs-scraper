## Description

Specifies or receives the attributes of a tab item. It is used with the [TCM_INSERTITEM](https://learn.microsoft.com/windows/desktop/Controls/tcm-insertitem), [TCM_GETITEM](https://learn.microsoft.com/windows/desktop/Controls/tcm-getitem), and [TCM_SETITEM](https://learn.microsoft.com/windows/desktop/Controls/tcm-setitem) messages. This structure supersedes the
**TC_ITEM** structure.

## Members

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value that specifies which members to retrieve or set. This member can be a combination of the following values:

| Value | Meaning |
| --- | --- |
| **TCIF_IMAGE** | The **iImage** member is valid. |
| **TCIF_PARAM** | The **lParam** member is valid. |
| **TCIF_RTLREADING** | The string pointed to by **pszText** will be displayed in the direction opposite to the text in the parent window. |
| **TCIF_STATE** | [Version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). The **dwState** member is valid. |
| **TCIF_TEXT** | The **pszText** member is valid. |

### `dwState`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Specifies the item's current state if information is being retrieved. If item information is being set, this member contains the state value to be set for the item. For a list of valid tab control item states, see [Tab Control Item States](https://learn.microsoft.com/windows/desktop/Controls/tab-control-item-states). This member is ignored in the [TCM_INSERTITEM](https://learn.microsoft.com/windows/desktop/Controls/tcm-insertitem) message.

### `dwStateMask`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Specifies which bits of the **dwState** member contain valid information. This member is ignored in the [TCM_INSERTITEM](https://learn.microsoft.com/windows/desktop/Controls/tcm-insertitem) message.

### `pszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a null-terminated string that contains the tab text when item information is being set. If item information is being retrieved, this member specifies the address of the buffer that receives the tab text.

### `cchTextMax`

Type: **int**

Size in **TCHAR****s** of the buffer pointed to by the
**pszText** member. If the structure is not receiving information, this member is ignored.

### `iImage`

Type: **int**

Index in the tab control's image list, or -1 if there is no image for the tab.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined data associated with the tab control item. If more or less than 4 bytes of application-defined data exist per tab, an application must define a structure and use it instead of the **TCITEM** structure. The first member of the application-defined structure must be a [TCITEMHEADER](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tcitemheadera) structure.

Typically, windows display text left-to-right (LTR). Windows can be
*mirrored* to display languages such as Hebrew or Arabic that read right-to-left (RTL). Ordinarily, **pszText** will be displayed in the same direction as the text in its parent window. If TCIF_RTLREADING is set, **pszText** will read in the opposite direction from the text in the parent window.

> [!NOTE]
> The commctrl.h header defines TCITEM as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).