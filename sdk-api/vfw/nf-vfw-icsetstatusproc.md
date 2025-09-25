# ICSetStatusProc function

## Description

The **ICSetStatusProc** function sends the address of a status callback function to a compressor. The compressor calls this function during lengthy operations.

## Parameters

### `hic`

Handle to the compressor.

### `dwFlags`

Applicable flags. Set to zero.

### `lParam`

Constant specified with the status callback address.

### `fpfnStatus`

Pointer to the status callback function. Specify **NULL** to indicate no status callbacks should be sent.

## Return value

Returns ICERR_OK if successful or **FALSE** otherwise.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)