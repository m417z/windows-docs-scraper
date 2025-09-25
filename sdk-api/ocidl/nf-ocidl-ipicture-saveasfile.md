# IPicture::SaveAsFile

## Description

Saves the picture's data into a stream in the same format that it would save itself into a file. Bitmaps use the BMP file format, metafiles the WMF format, and icons the ICO format.

## Parameters

### `pStream` [in]

A pointer to the stream into which the picture writes its data.

### `fSaveMemCopy` [in]

A flag indicating whether to save a copy of the picture in memory.

### `pCbSize` [out]

Pointer to a variable that receives the number of bytes written into the stream. This value can be **NULL**, indicating that the caller does not require this information.

## Return value

This method supports the standard return values E_FAIL, E_INVALIDARG, and S_OK.

## See also

[IPicture](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipicture)