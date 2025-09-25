# IEnumTfProperties::Next

## Description

Obtains, from the current position, the specified number of elements in the enumeration sequence.

## Parameters

### `ulCount` [in]

Specifies the number of elements to obtain.

### `ppProp` [out]

Pointer to an array of [ITfProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfproperty) interface pointers that receives the requested objects. This array must be at least *ulCount* elements in size.

### `pcFetched` [out]

Pointer to a ULONG that receives the number of elements obtained. This value can be less than the number of items requested. This parameter can be **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method reached the end of the enumeration before the specified number of elements could be obtained. |
| **E_INVALIDARG** | *ppProp* is invalid. |

## See also

[IEnumTfProperties interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-ienumtfproperties), [ITfProperty interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfproperty)