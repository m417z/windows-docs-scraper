# IMFByteStreamBuffering::SetBufferingParams

## Description

Sets the buffering parameters.

## Parameters

### `pParams` [in]

Pointer to an [MFBYTESTREAM_BUFFERING_PARAMS](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mfbytestream_buffering_params) structure that contains the buffering parameters. The byte stream uses this information to calculate how much data to buffer from the network.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFByteStreamBuffering](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfbytestreambuffering)