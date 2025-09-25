# IMFSinkWriterEx::GetTransformForStream

## Description

Gets a pointer to a Media Foundation transform (MFT) for a specified stream.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of a stream.

### `dwTransformIndex` [in]

The zero-based index of the MFT to retrieve.

### `pGuidCategory` [out]

Receives a pointer to a GUID that specifies the category of the MFT. For a list of possible values, see [MFT_CATEGORY](https://learn.microsoft.com/windows/desktop/medfound/mft-category).

### `ppTransform` [out]

Receives a pointer to the [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform) interface of the MFT. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSinkWriterEx](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriterex)