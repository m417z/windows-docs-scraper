# IMFByteStream::GetCapabilities

## Description

Retrieves the characteristics of the byte stream.

## Parameters

### `pdwCapabilities` [out]

Receives a bitwise **OR** of zero or more flags. The following flags are defined.

| Value | Meaning |
| --- | --- |
| **MFBYTESTREAM_IS_READABLE**<br><br>0x00000001 | The byte stream can be read. |
| **MFBYTESTREAM_IS_WRITABLE**<br><br>0x00000002 | The byte stream can be written to. |
| **MFBYTESTREAM_IS_SEEKABLE**<br><br>0x00000004 | The byte stream can be seeked. |
| **MFBYTESTREAM_IS_REMOTE**<br><br>0x00000008 | The byte stream is from a remote source, such as a network. |
| **MFBYTESTREAM_IS_DIRECTORY**<br><br>0x00000080 | The byte stream represents a file directory. |
| **MFBYTESTREAM_HAS_SLOW_SEEK**<br><br>0x00000100 | Seeking within this stream might be slow. For example, the byte stream might download from a network. |
| **MFBYTESTREAM_IS_PARTIALLY_DOWNLOADED**<br><br>0x00000200 | The byte stream is currently downloading data to a local cache. Read operations on the byte stream might take longer until the data is completely downloaded.<br><br>This flag is cleared after all of the data has been downloaded.<br><br>If the **MFBYTESTREAM_HAS_SLOW_SEEK** flag is also set, it means the byte stream must download the entire file sequentially. Otherwise, the byte stream can respond to seek requests by restarting the download from a new point in the stream. |
| **MFBYTESTREAM_SHARE_WRITE**<br><br>0x00000400 | Another thread or process can open this byte stream for writing. If this flag is present, the length of the byte stream could change while it is being read. <br><br>This flag can affect the behavior of byte-stream handlers. For more information, see [MF_BYTESTREAMHANDLER_ACCEPTS_SHARE_WRITE](https://learn.microsoft.com/windows/desktop/medfound/mf-bytestreamhandler-accepts-share-write).<br><br>**Note** Requires Windows 7 or later. |
| **MFBYTESTREAM_DOES_NOT_USE_NETWORK**<br><br>0x00000800 | The byte stream is not currently using the network to receive the content. Networking hardware may enter a power saving state when this bit is set.<br><br>**Note** Requires Windows 8 or later. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream)