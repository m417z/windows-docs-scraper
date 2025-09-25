# ITfLangBarItem::Show

## Description

Called to show or hide the language bar item.

## Parameters

### `fShow` [in]

Contains a **BOOL** that indicates if the item should be shown or hidden. Contains a nonzero value if the item should be shown or zero otherwise.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The language bar item does not support this method. |

## Remarks

The language bar item implementation should update its visible status by modifying the value returned from [ITfLangBarItem::GetStatus](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritem-getstatus) to include or exclude the TF_LBI_STATUS_HIDDEN status flag. The implementation then prompts language bar to obtain the new status value by calling [ITfLangBarItemSink::OnUpdate](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemsink-onupdate) with TF_LBI_STATUS.

This method is only useful when the item has the TF_LBI_STYLE_HIDDENSTATUSCONTROL style. Without this style, only the language bar can show or hide the item.

## See also

[ITfLangBarItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritem)

[ITfLangBarItem::GetStatus](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritem-getstatus)

[ITfLangBarItemSink::OnUpdate](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemsink-onupdate)