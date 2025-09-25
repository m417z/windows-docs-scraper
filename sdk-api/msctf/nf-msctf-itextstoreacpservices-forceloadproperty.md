# ITextStoreACPServices::ForceLoadProperty

## Description

Forces all values of an asynchronously loaded property to be loaded.

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

When calling this method, the application must be able to grant a synchronous read-only lock.

## See also

[ITextStoreACPServices interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itextstoreacpservices), [ITextStoreACPServices::Unserialize](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itextstoreacpservices-unserialize), [ITfPersistentPropertyLoaderACP interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfpersistentpropertyloaderacp), [ITfProperty interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfproperty)