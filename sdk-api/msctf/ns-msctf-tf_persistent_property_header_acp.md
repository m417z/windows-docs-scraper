# TF_PERSISTENT_PROPERTY_HEADER_ACP structure

## Description

The **TF_PERSISTENT_PROPERTY_HEADER_ACP** structure is used to provide property header data.

## Members

### `guidType`

Contains a GUID that identifies the property.

### `ichStart`

Contains the starting character position of the property.

### `cch`

Contains the number of characters that the property spans.

### `cb`

Contains the size, in bytes, of the property value.

### `dwPrivate`

Contains a **DWORD** value defined by the property owner.

### `clsidTIP`

Contains the CLSID of the property owner.

## See also

[ITextStoreACPServices::Serialize](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itextstoreacpservices-serialize)

[ITextStoreACPServices::Unserialize](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itextstoreacpservices-unserialize)

[ITfContextOwnerServices::Serialize](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextownerservices-serialize)

[ITfContextOwnerServices::Unserialize](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextownerservices-unserialize)

[ITfPersistentPropertyLoaderACP::LoadProperty](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfpersistentpropertyloaderacp-loadproperty)