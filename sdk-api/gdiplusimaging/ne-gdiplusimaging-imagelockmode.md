# ImageLockMode enumeration

## Description

The **ImageLockMode** enumeration specifies flags that are passed to the
*flags* parameter of the
[Bitmap::LockBits](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-lockbits) method. The **Bitmap::LockBits** method locks a portion of an image so that you can read or write the pixel data.

## Constants

### `ImageLockModeRead:0x0001`

Specifies that a portion of the image is locked for reading.

### `ImageLockModeWrite:0x0002`

Specifies that a portion of the image is locked for writing.

### `ImageLockModeUserInputBuf:0x0004`

Specifies that the buffer used for reading or writing pixel data is allocated by the user. If this flag is set, then the
*lockedBitmapData* parameter of the
[Bitmap::LockBits](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-lockbits) method serves as an input parameter (and possibly as an output parameter). If this flag is cleared, then the
*lockedBitmapData* parameter serves only as an output parameter.

## See also

[Bitmap::LockBits](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-lockbits)