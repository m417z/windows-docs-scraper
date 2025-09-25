# IMFByteStreamHandler::GetMaxNumberOfBytesRequiredForResolution

## Description

Retrieves the maximum number of bytes needed to create the media source or determine that the byte stream handler cannot parse this stream.

## Parameters

### `pqwBytes` [out]

Receives the maximum number of bytes that are required.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFByteStreamHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfbytestreamhandler)

[Scheme Handlers and Byte-Stream Handlers](https://learn.microsoft.com/windows/desktop/medfound/scheme-handlers-and-byte-stream-handlers)