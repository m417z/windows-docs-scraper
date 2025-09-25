# TBBUTTONINFOA structure

## Description

Contains or receives information for a specific button in a toolbar.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the structure, in bytes. This member must be filled in prior to sending the associated message.

### `dwMask`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Set of flags that indicate which members contain valid information. This member must be filled in prior to sending the associated message. This can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **TBIF_BYINDEX** | [Version 5.80.](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) The *wParam* sent with a [TB_GETBUTTONINFO](https://learn.microsoft.com/windows/desktop/Controls/tb-getbuttoninfo) or [TB_SETBUTTONINFO](https://learn.microsoft.com/windows/desktop/Controls/tb-setbuttoninfo) message is an index, not an identifier. |
| **TBIF_COMMAND** | The **idCommand** member contains valid information or is being requested. |
| **TBIF_IMAGE** | The **iImage** member contains valid information or is being requested. |
| **TBIF_LPARAM** | The **lParam** member contains valid information or is being requested. |
| **TBIF_SIZE** | The **cx** member contains valid information or is being requested. |
| **TBIF_STATE** | The **fsState** member contains valid information or is being requested. |
| **TBIF_STYLE** | The **fsStyle** member contains valid information or is being requested. |
| **TBIF_TEXT** | The **pszText** member contains valid information or is being requested. |

### `idCommand`

Type: **int**

Command identifier of the button.

### `iImage`

Type: **int**

Image index of the button. Set this member to I_IMAGECALLBACK, and the toolbar will send the [TBN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/tbn-getdispinfo) notification code to retrieve the image index when it is needed.

[Version 5.81](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Set this member to I_IMAGENONE to indicate that the button does not have an image. The button layout will not include any space for a bitmap, only text.

### `fsState`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

State flags of the button. This can be one or more of the values listed in [Toolbar Button States](https://learn.microsoft.com/windows/desktop/Controls/toolbar-button-states).

### `fsStyle`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Style flags of the button. This can be one or more of the values listed in [Toolbar Control and Button Styles](https://learn.microsoft.com/windows/desktop/Controls/toolbar-control-and-button-styles).

### `cx`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Width of the button, in pixels.

### `lParam`

Type: **[DWORD_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined value associated with the button.

### `pszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Address of a character buffer that contains or receives the button text.

### `cchText`

Type: **int**

Size of the buffer at **pszText**. If the button information is being set, this member is ignored.

## Remarks

> [!NOTE]
> The commctrl.h header defines TBBUTTONINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).