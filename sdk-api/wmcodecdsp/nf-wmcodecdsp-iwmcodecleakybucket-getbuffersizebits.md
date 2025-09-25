# IWMCodecLeakyBucket::GetBufferSizeBits

## Description

Retrieves the current size of the buffer in bits.

## Parameters

### `pulBufferSize` [out]

Pointer to a variable containing the buffer size, in bits.

## Return value

This method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The buffer size is equal to the bit rate of the stream multiplied by the buffer window. For example, a stream with a bit rate of 28 kilobits per second with a buffer window of 3 seconds would have a buffer of 28000 bits per second x 3 seconds = 84000 bits.

## See also

[IWMCodecLeakyBucket Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmcodecleakybucket)

[IWMCodecLeakyBucket::SetBufferSizeBits](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-iwmcodecleakybucket-setbuffersizebits)