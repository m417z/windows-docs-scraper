# ITfContextOwnerServices::ForceLoadProperty

## Description

Forces a property load.

## Parameters

### `pProp` [in]

Pointer to an [ITfProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfproperty) object that specifies the property to load.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_OUTOFMEMORY** | A memory allocation error occurred. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

The application must be able to grant a synchronous read-only lock before calling this method.

## See also

[ITfContextOwnerServices interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontextownerservices), [ITfContextOwnerServices::Unserialize](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcontextownerservices-unserialize), [ITfProperty interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfproperty)