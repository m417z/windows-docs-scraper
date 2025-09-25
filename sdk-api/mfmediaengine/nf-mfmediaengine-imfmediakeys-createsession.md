# IMFMediaKeys::CreateSession

## Description

Creates a media key session object using the specified initialization data and custom data.
.

## Parameters

### `mimeType`

The MIME type of the media container used for the content.

### `initData`

The initialization data for the key system.

### `cb`

The count in bytes of *initData*.

### `customData`

Custom data sent to the key system.

### `cbCustomData`

The count in bytes of *cbCustomData*.

### `notify`

notify

### `ppSession`

The media key session.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaKeys](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediakeys)