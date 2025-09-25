# ITfLangBarItem::GetStatus

## Description

Obtains the status of a language bar item.

## Parameters

### `pdwStatus` [out]

Pointer to a **DWORD** that receives zero or a combination of one or more of the [TF_LBI_STATUS_*](https://learn.microsoft.com/windows/desktop/TSF/tf-lbi-status--constants) values that indicate the current status of the item.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pdwStatus* is invalid. |

## See also

[ITfLangBarItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritem)

[TF_LBI_STATUS_*](https://learn.microsoft.com/windows/desktop/TSF/tf-lbi-status--constants)