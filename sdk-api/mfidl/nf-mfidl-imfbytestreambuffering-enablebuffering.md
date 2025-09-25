# IMFByteStreamBuffering::EnableBuffering

## Description

Enables or disables buffering.

## Parameters

### `fEnable` [in]

Specifies whether the byte stream buffers data. If **TRUE**, buffering is enabled. If **FALSE**, buffering is disabled.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Before calling this method, call [IMFByteStreamBuffering::SetBufferingParams](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfbytestreambuffering-setbufferingparams) to set the buffering parameters on the byte stream.

## See also

[IMFByteStreamBuffering](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfbytestreambuffering)