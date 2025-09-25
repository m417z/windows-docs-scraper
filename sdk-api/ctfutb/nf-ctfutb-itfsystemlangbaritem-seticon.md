# ITfSystemLangBarItem::SetIcon

## Description

Modifies the icon displayed for the system language bar menu.

## Parameters

### `hIcon` [in]

Contains the handle to the new icon.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The system language bar menu does not allow its icon to be modified. |

## Remarks

In response to this method, the system language bar menu should call [ITfLangBarItemSink::OnUpdate](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemsink-onupdate) with TF_LBI_ICON to force the language bar to obtain the new icon.