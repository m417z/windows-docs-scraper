# IMFNetProxyLocator::GetCurrentProxy

## Description

Retrieves the current proxy information including hostname and port.

## Parameters

### `pszStr` [out]

Pointer to a buffer that receives a null-terminated string containing the proxy hostname and port. This parameter can be **NULL**.

### `pcchStr` [in, out]

On input, specifies the number of elements in the *pszStr* array. On output, receives the required size of the buffer.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOT_SUFFICIENT_BUFFER** | The buffer specified in *pszStr* is too small. |

## See also

[IMFNetProxyLocator](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetproxylocator)