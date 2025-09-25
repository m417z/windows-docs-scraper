# ITfPersistentPropertyLoaderACP::LoadProperty

## Description

Called to load a property.

## Parameters

### `pHdr` [in]

Pointer to a [TF_PERSISTENT_PROPERTY_HEADER_ACP](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_persistent_property_header_acp) structure that identifies the property to load. This structure contains the same data as the structure passed to [ITextStoreACPServices::Unserialize](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itextstoreacpservices-unserialize).

### `ppStream` [out]

Pointer to an **IStream** interface pointer that receives the stream object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## Remarks

Only property data is written to the stream. The header data is not written to the stream.

Obtain the original position of the stream before writing to the stream. The original position should be restored in the stream before returning from this method.

## See also

[ITextStoreACPServices::Unserialize](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itextstoreacpservices-unserialize)

[ITfPersistentPropertyLoaderACP](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfpersistentpropertyloaderacp)

[TF_PERSISTENT_PROPERTY_HEADER_ACP](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_persistent_property_header_acp)