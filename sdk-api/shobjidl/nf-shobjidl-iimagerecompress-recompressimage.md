# IImageRecompress::RecompressImage

## Description

Recompresses an image. Implemented in an
[ImageRecompress](https://learn.microsoft.com/windows/desktop/shell/known-folders) object, this method
accepts x and y dimensions with a designation of quality. The method
creates a stream containing the new image that has been recompressed
to the specified size.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the object containing the stream of the image to read.

### `cx` [in]

Type: **int**

The x dimension of the image to return.

### `cy` [in]

Type: **int**

The y dimension of the image to return.

### `iQuality` [in]

Type: **int**

An indication of recompression quality that can range from 0 to 100.

### `pstg` [in]

Type: **[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage)***

A pointer to an [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the
object that contains the stream to be written to.

### `ppstrmOut` [in, out]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)****

The address of an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface pointer
variable that receives the output stream written to.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error code otherwise.
If the image in the input stream is less than the size specified by
*cx* and
*cy*,
then S_FALSE is returned.

## See also

[IImageRecompress](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iimagerecompress)

[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)

[ImageRecompress](https://learn.microsoft.com/windows/desktop/shell/known-folders)