# ITfLangBarItemMgr::GetItems

## Description

Obtains the interface, information and status for one or more items in the language bar.

## Parameters

### `ulCount` [in]

Specifies the number of items to obtain the status for.

### `ppItem` [out]

Pointer to an array of [ITfLangBarItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritem) interface pointers that receive the item interfaces. This array must be at least *ulCount* elements in length.

### `pInfo`

[in, out] Pointer to an array of [TF_LANGBARITEMINFO](https://learn.microsoft.com/windows/desktop/api/ctfutb/ns-ctfutb-tf_langbariteminfo) structures that receive the information for each item. This array must be at least *ulCount* elements in length.

### `pdwStatus`

[in, out] Pointer to an array of **DWORD** values that receive the status of each item. Each element in this array receives zero or a combination of one or more of the [TF_LBI_STATUS_*](https://learn.microsoft.com/windows/desktop/TSF/tf-lbi-status--constants) values. This array must be at least *ulCount* elements in length.

### `pcFetched`

[in, out] Pointer to a ULONG that receives the number of items obtained by this method. This parameter can be **NULL** if this information is not required.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The number of items obtained is less than the number of items requested. If *pcFetched* is not **NULL**, *pcFetched* receives the number of items obtained. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfLangBarItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritem)

[ITfLangBarItemMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemmgr)

[TF_LANGBARITEMINFO](https://learn.microsoft.com/windows/desktop/api/ctfutb/ns-ctfutb-tf_langbariteminfo)

[TF_LBI_STATUS_* Constants](https://learn.microsoft.com/windows/desktop/TSF/tf-lbi-status--constants)