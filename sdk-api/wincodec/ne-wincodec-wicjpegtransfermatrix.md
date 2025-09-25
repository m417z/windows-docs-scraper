# WICJpegTransferMatrix enumeration

## Description

Specifies conversion matrix from Y'Cb'Cr' to R'G'B'.

## Constants

### `WICJpegTransferMatrixIdentity:0`

Specifies the identity transfer matrix.

### `WICJpegTransferMatrixBT601:0x1`

Specifies the BT601 transfer matrix.

### `WICJpegTransferMatrix_FORCE_DWORD:0x7fffffff`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## See also

[WICJpegFrameHeader](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicjpegframeheader)