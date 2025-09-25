# ITfSystemLangBarItem::SetTooltipString

## Description

Modifies the tooltip text displayed for the system language bar menu.

## Parameters

### `pchToolTip` [in]

A string that appears as a tooltip.

### `cch` [in]

Size, in characters, of the string.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The tooltip string for the system language bar menu cannot be modified. |

## Remarks

In response to this method, the system language bar menu should call [ITfLangBarItemSink::OnUpdate](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemsink-onupdate) with TF_LBI_TOOLTIP to force the language bar to obtain the new tooltip text.