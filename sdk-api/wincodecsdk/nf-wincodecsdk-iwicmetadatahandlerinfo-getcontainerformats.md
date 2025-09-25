# IWICMetadataHandlerInfo::GetContainerFormats

## Description

Retrieves the container formats supported by the metadata handler.

## Parameters

### `cContainerFormats` [in]

Type: **UINT**

The size of the *pguidContainerFormats* array.

### `pguidContainerFormats` [in, out]

Type: **GUID***

Pointer to an array that receives the container formats supported by the metadata handler.

### `pcchActual` [out]

Type: **UINT***

The actual number of GUIDs added to the array.

To obtain the number of supported container formats, pass `NULL` to *pguidContainerFormats*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.