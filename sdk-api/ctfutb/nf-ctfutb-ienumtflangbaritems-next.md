# IEnumTfLangBarItems::Next

## Description

Obtains the specified number of elements in the enumeration sequence from the current position.

## Parameters

### `ulCount` [in]

Specifies the number of elements to obtain.

### `ppItem` [out]

Pointer to an array of [ITfLangBarItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritem) interface pointers that receives the requested objects. This array must be at least *ulCount* elements in size.

### `pcFetched`

[in, out] Pointer to a ULONG value that receives the number of elements obtained. This value can be less than the number of items requested. This parameter can be **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method reached the end of the enumeration before the specified number of elements could be obtained. |
| **E_INVALIDARG** | *ppItem* is invalid. |

## See also

[IEnumTfLangBarItems](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-ienumtflangbaritems)

[ITfLangBarItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritem)