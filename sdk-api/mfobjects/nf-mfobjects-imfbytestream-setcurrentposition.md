# IMFByteStream::SetCurrentPosition

## Description

Sets the current read or write position.

## Parameters

### `qwPosition` [in]

New position in the stream, as a byte offset from the start of the stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |

## Remarks

If the new position is larger than the length of the stream, the method returns E_INVALIDARG.

 **Implementation notes:**This method should update the current position in the stream by setting the current position to the value passed in to the *qwPosition* parameter. Other methods that can update the current position are [Read](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-read), [BeginRead](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-beginread), [Write](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-write), [BeginWrite](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-beginwrite), and [Seek](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-seek).

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream)