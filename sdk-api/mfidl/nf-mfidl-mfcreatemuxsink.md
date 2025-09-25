# MFCreateMuxSink function

## Description

Creates a generic media sink that wraps a multiplexer Microsoft Media Foundation transform (MFT).

## Parameters

### `guidOutputSubType` [in]

The subtype GUID of the output type for the MFT.

### `pOutputAttributes` [in]

A list of format attributes for the MFT output type. This parameter is optional and can be **NULL**.

### `pOutputByteStream` [in]

A pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of a byte stream. The output from the MFT is written to this byte stream. This parameter can be **NULL**.

### `ppMuxSink` [out]

Receives a pointer to the [IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink) interface of the media sink. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function attempts to find a multiplexer MFT that supports an output type with the following definition:

* Major type: **MFMediaType_Stream**
* Subtype: *guidOutputSubType*
* Additional format attributes (optional)

To provide a list of additional format attributes:

1. Call [MFCreateAttributes](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreateattributes) to get an [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) pointer.
2. Use the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface to set the attributes. (See [Media Type Attributes](https://learn.microsoft.com/windows/desktop/medfound/media-type-attributes).)
3. Pass the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) pointer in the *pOutputAttributes* parameter.

The multiplexer MFT must be registered in the [MFT_CATEGORY_MULTIPLEXER](https://learn.microsoft.com/windows/desktop/medfound/mft-category) category.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)