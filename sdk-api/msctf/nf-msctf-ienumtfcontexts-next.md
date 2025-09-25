# IEnumTfContexts::Next

## Description

Obtains, from the current position, the specified number of elements in the enumeration sequence.

## Parameters

### `ulCount` [in]

Specifies the number of elements to obtain.

### `rgContext` [out]

Pointer to an array of [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) interface pointers that receives the requested objects. This array must be at least *ulCount* elements in size.

### `pcFetched` [out]

Pointer to a ULONG value that receives the number of elements actually obtained. This value can be less than the number of items requested. This parameter can be **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method reached the end of the enumeration before the specified number of elements could be obtained. |
| **E_INVALIDARG** | *rgContext* is invalid. |

## See also

[IEnumTfContexts interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-ienumtfcontexts), [ITfContext interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontext)