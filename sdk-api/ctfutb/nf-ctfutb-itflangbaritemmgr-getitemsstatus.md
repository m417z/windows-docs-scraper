# ITfLangBarItemMgr::GetItemsStatus

## Description

Obtains the status of one or more items on the language bar.

## Parameters

### `ulCount` [in]

Specifies the number of items to obtain the status for.

### `prgguid` [in]

Pointer to an array of **GUID**s that identify the items obtain the status for. These are the item **GUID**s that the item supplies in [ITfLangBarItem::GetInfo](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritem-getinfo). This array must be at least *ulCount* elements in length.

### `pdwStatus` [out]

Pointer to an array of **DWORD** values that receive the status of each item. Each element in this array receives zero or a combination of one or more of the [TF_LBI_STATUS_*](https://learn.microsoft.com/windows/desktop/TSF/tf-lbi-status--constants) values. This array must be at least *ulCount* elements in length.

The index of each status value corresponds to the index of the item identifier in *prgguid*. For example, the element 0 in *pdwStatus* receives the for the item identified by element 0 of *prgguid*.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

This method causes the [ITfLangBarItem::GetStatus](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritem-getstatus) method of each language bar item identified by *prgguid* to be called.

## See also

[ITfLangBarItem::GetStatus](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritem-getstatus)

[ITfLangBarItemMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemmgr)

[TF_LBI_STATUS_* Constants](https://learn.microsoft.com/windows/desktop/TSF/tf-lbi-status--constants)