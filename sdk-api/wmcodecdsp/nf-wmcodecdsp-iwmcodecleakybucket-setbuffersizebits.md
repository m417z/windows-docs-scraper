# IWMCodecLeakyBucket::SetBufferSizeBits

## Description

Sets the buffer size in bits.

## Parameters

### `ulBufferSize` [in]

The buffer size, in bits.

## Return value

This method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is not implemented on the audio encoder objects. If you call this method from the [IWMCodecLeakyBucket](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmcodecleakybucket) interface it returns E_NOTIMPL.

The buffer size is equal to the bit rate of the stream multiplied by the buffer window. For example, a stream with a bit rate of 28 kilobits per second with a buffer window of 3 seconds would have a buffer of 28000 bits per second x 3 seconds = 84000 bits.

This method is an alternative to setting the MFPKEY_VIDEOWINDOW property. Using this method does not alter the bit rate of the stream, but does alter the buffer window. Using the stream with a bit rate of 28000 bits per second from the previous example, setting the buffer size to 84000 using this method would have exactly the same effect as setting [MFPKEY_VIDEOWINDOW](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-videowindowproperty) to 3000 milliseconds (3 seconds).

## See also

[IWMCodecLeakyBucket Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmcodecleakybucket)

[IWMCodecLeakyBucket::GetBufferSizeBits](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-iwmcodecleakybucket-getbuffersizebits)