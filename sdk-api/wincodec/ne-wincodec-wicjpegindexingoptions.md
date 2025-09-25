# WICJpegIndexingOptions enumeration

## Description

Specifies the options for indexing a JPEG image.

## Constants

### `WICJpegIndexingOptionsGenerateOnDemand:0`

Index generation is deferred until [IWICBitmapSource::CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapsource-copypixels) is called on the image.

### `WICJpegIndexingOptionsGenerateOnLoad:0x1`

Index generation is performed when the when the image is initially loaded.

### `WICJpegIndexingOptions_FORCE_DWORD:0x7fffffff`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## See also

[IWICJpegFrameDecode::SetIndexing](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicjpegframedecode-setindexing)