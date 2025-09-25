# ITfContextOwnerServices::Serialize

## Description

The **ITfContextOwnerServices::Serialize** method obtains a property from a range of text and writes the property data into a stream object. This enables an application to store property data, for example, when writing the data to a file.

## Parameters

### `pProp` [in]

Pointer to an [ITfProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfproperty) interface that identifies the property to serialize.

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) interface that identifies the range that the property is obtained from.

### `pHdr` [out]

Pointer to a [TF_PERSISTENT_PROPERTY_HEADER_ACP](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_persistent_property_header_acp) structure that receives the header data for the property.

### `pStream` [in]

Pointer to an **IStream** object that the TSF manager will write the property data to.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The property cannot be serialized. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

The property header data placed in *pHdr* is common to all properties and must be preserved with the data written into *pStream*. This same data pair must be passed to [ITfContextOwnerServices::Unserialize](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itextstoreacpservices-unserialize) to restore the property data.

An application can save all of the properties for the entire document by performing the following steps.

* Enumerate all properties using [ITfContext::EnumProperties](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-enumproperties).
* Within each property, enumerate the ranges using [ITfReadOnlyProperty::EnumRanges](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfreadonlyproperty-enumranges).
* Pass the current property and range to this method.
* Write the data placed in *pHdr* to the file.
* Write the data added to *pStream* to the file.

When calling this method, the application must be able to grant a synchronous read-only lock.

## See also

[ITfContextOwnerServices](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontextownerservices)

[ITfProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfproperty)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[TF_PERSISTENT_PROPERTY_HEADER_ACP](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_persistent_property_header_acp)