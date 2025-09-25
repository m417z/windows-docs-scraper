# ITextStoreACPServices::Unserialize

## Description

Takes previously serialized property data and applies it to a property object.

## Parameters

### `pProp` [in]

Pointer to an [ITfProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfproperty) object that receives the property data.

### `pHdr` [in]

Pointer to a [TF_PERSISTENT_PROPERTY_HEADER_ACP](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_persistent_property_header_acp) structure that contains the header data for the property.

### `pStream` [in]

Pointer to an **IStream** object that contains the property data. This parameter can be **NULL** if *pLoader* is not **NULL**. This parameter is ignored if *pLoader* is not **NULL**.

### `pLoader` [in]

Pointer to an [ITfPersistentPropertyLoaderACP](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfpersistentpropertyloaderacp) object that the TSF manager will use to obtain the property data. This parameter can be **NULL** if *pStream* is not **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_S_ASYNC** | The property data will be obtained asynchronously. |
| **TF_E_SYNCHRONOUS** | A synchronous read-only lock cannot be obtained. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

If *pStream* is specified rather than *pLoader*, the property data will be read from *pStream* during the call to **Unserialize** . If *pLoader* is specified rather than *pStream*, the property data will be read from *pLoader* asynchronously. Using *pStream* can cause long delays if the property data is large.

While calling this method, the application must be able to grant a synchronous read-only lock.

## See also

[ITextStoreACPServices interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itextstoreacpservices), [ITextStoreACPServices::Serialize](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itextstoreacpservices-serialize), [ITfContext::EnumProperties](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcontext-enumproperties), [ITfProperty interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfproperty), [ITfRange interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfrange), [ITfReadOnlyProperty::EnumRanges](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfreadonlyproperty-enumranges), [TF_PERSISTENT_PROPERTY_HEADER_ACP structure](https://learn.microsoft.com/windows/win32/api/msctf/ns-msctf-tf_persistent_property_header_acp)