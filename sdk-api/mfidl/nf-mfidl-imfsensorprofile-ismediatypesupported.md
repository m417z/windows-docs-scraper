# IMFSensorProfile::IsMediaTypeSupported

## Description

Determines if a media stream supports the specified media type.

## Parameters

### `StreamId` [in]

The ID of the stream to check.

### `pMediaType` [in]

Pointer to an [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) describing the media type to check.

### `pfSupported` [out]

Returns **true** if the media type is supported; otherwise, **false**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSensorProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorprofile)