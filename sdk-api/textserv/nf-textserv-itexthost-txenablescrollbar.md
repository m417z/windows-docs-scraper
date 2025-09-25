# ITextHost::TxEnableScrollBar

## Description

Enables or disables one or both scroll bar arrows in the text host window.

## Parameters

### `fuSBFlags` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies which scroll bar is affected. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SB_BOTH** | Affects both the horizontal and vertical scroll bars. |
| **SB_HORZ** | Affects the horizontal scroll bar. |
| **SB_VERT** | Affects the vertical scroll bar. |

### `fuArrowflags` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies which scroll bar arrows are enabled or disabled. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ESB_DISABLE_BOTH** | Disables both arrows on a scroll bar. |
| **ESB_DISABLE_DOWN** | Disables the down arrow on a vertical scroll bar. |
| **ESB_DISABLE_LEFT** | Disables the left arrow on a horizontal scroll bar. |
| **ESB_DISABLE_LTUP** | Disables the left arrow on a horizontal scroll bar or the up arrow of a vertical scroll bar. |
| **ESB_DISABLE_RIGHT** | Disables the right arrow on a horizontal scroll bar. |
| **ESB_DISABLE_RTDN** | Disables the right arrow on a horizontal scroll bar or the down arrow of a vertical scroll bar. |
| **ESB_DISABLE_UP** | Disables the up arrow on a vertical scroll bar. |
| **ESB_ENABLE_BOTH** | Enables both arrows on a scroll bar. |

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return nonzero if the arrows are enabled or disabled as specified.

Return zero if the arrows are already in the requested state or an error occurs.

## Remarks

This method is only valid when the control is in-place active; calls while the control is inactive may fail.

## See also

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[Windowless Rich Edit Controls Overview](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)