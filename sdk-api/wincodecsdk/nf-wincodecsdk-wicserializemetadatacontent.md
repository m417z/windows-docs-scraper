# WICSerializeMetadataContent function

## Description

Writes metadata into a given stream.

## Parameters

### `guidContainerFormat` [in]

Type: **REFGUID**

The container format GUID.

### `pIWriter` [in]

Type: **[IWICMetadataWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatawriter)***

The metadata writer to write metadata to the stream.

### `dwPersistOptions` [in]

Type: **DWORD**

The [WICPersistOptions](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/ne-wincodecsdk-wicpersistoptions) options to use when writing the metadata.

### `pIStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

A pointer to the stream in which to write the metadata.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.