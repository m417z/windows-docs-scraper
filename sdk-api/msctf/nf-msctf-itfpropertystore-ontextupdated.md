# ITfPropertyStore::OnTextUpdated

## Description

Called when the text that the property store applies to is modified.

## Parameters

### `dwFlags` [in]

Contains a set of flags that provide additional information about the text change. This can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **TF_TU_CORRECTION** | The text change is the result of a correction. This implies that the semantics of the text have not changed. An example of this is when the spelling checker corrects a misspelled word. |

### `pRangeNew` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) interface that contains the range of text modified.

### `pfAccept` [out]

Pointer to a **BOOL** variable that receives a value that indicates if the property store should be retained. Receives a nonzero value if the property store should be retained or zero if the property store should be discarded. If the property store is discarded, the TSF manager will set the property value to VT_EMPTY and release the property store.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

If this method returns any value other than S_OK, the property store is discarded.

## See also

[ITfPropertyStore](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfpropertystore)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)