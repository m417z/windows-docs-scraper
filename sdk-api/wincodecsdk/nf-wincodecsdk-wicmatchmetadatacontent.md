# WICMatchMetadataContent function

## Description

Obtains a metadata format GUID for a specified container format and vendor that best matches the content within a given stream.

## Parameters

### `guidContainerFormat` [in]

Type: **REFGUID**

The container format GUID.

### `pguidVendor` [in]

Type: **const GUID***

The vendor GUID.

### `pIStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The content stream in which to match a metadata format.

### `pguidMetadataFormat` [out]

Type: **GUID***

A pointer that receives a metadata format GUID for the given parameters.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.