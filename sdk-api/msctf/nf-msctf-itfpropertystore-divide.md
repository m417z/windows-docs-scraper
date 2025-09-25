# ITfPropertyStore::Divide

## Description

Called when the text covered by the property is split into two ranges.

## Parameters

### `pRangeThis` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that contains the range that the property store now covers. This will be the range of text closest to the beginning of the context.

### `pRangeNew` [in]

Pointer to an *ITfRange* object that contains the range that the new property store will cover. This will be the range of text closest to the end of the context.

### `ppPropStore` [out]

Pointer to an [ITfPropertyStore](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfpropertystore) interface pointer that receives a new property store object that will cover the range specified by *pRangeNew*.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method creates a new property store object to cover *pRangeNew* and returns the pointer to this object in *ppPropStore*. If no new property store is returned, the original property store is discarded and the property store for both ranges is set to empty.

If this method returns any value other than S_OK, the original property store is discarded.

## See also

[ITfPropertyStore](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfpropertystore)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)