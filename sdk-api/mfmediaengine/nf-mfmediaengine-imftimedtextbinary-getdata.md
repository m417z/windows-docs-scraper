# IMFTimedTextBinary::GetData

## Description

Gets the data content of the timed-text object.

## Parameters

### `data` [out]

Type: **const BYTE****

A pointer to a memory block that receives a pointer to the data content of the timed-text object.

### `length` [out]

Type: **DWORD***

A pointer to a variable that receives the length in bytes of the data content.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTimedTextBinary](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextbinary)