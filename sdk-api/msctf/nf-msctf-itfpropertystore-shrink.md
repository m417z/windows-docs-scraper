# ITfPropertyStore::Shrink

## Description

Called when the text that the property store applies to is truncated.

## Parameters

### `pRangeNew` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) interface that contains the truncated range.

### `pfFree` [out]

Pointer to a **BOOL** variable that receives a value that indicates if the property store should be retained. Receives a nonzero value if the property store should be retained or zero if the property store should be discarded. If the property store is discarded, the TSF manager will set the property value to VT_EMPTY and release the property store.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

If this method returns a value other than S_OK, the property store is discarded.

## See also

[ITfPropertyStore](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfpropertystore)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)