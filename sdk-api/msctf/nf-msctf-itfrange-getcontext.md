# ITfRange::GetContext

## Description

Obtains the context object to which the range belongs.

## Parameters

### `ppContext` [out]

Pointer to an [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) interface pointer that receives the context object that the range belongs to.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *ppContext* is invalid. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)