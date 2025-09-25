# ITfRange::Clone

## Description

The **ITfRange::Clone** method duplicates this range of text.

## Parameters

### `ppClone` [out]

Pointer to a new range object that references this range.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_OUTOFMEMORY** | The method was unable to generate a pointer to the new range. |

## Remarks

The resulting new range object can be modified without affecting the original. However, modifying the document that contains the new range might cause the original range's anchors to be repositioned.

The gravity of the original is preserved in the new range.

## See also

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[Ranges](https://learn.microsoft.com/windows/desktop/TSF/ranges)

[Text Stores](https://learn.microsoft.com/windows/desktop/TSF/text-stores)