# IDiscRecorder2Ex::GetByteAlignmentMask

## Description

Retrieves the byte alignment mask for the device.

## Parameters

### `value` [out]

Byte alignment mask that you use to determine if the buffer is aligned to the correct byte boundary for the device. The byte alignment value is always a number that is a power of 2.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |

## Remarks

The data buffer for [IDiscRecorder2Ex::SendCommandSendDataToDevice](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-sendcommandsenddatatodevice) and [IDiscRecorder2Ex::SendCommandGetDataFromDevice](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-sendcommandgetdatafromdevice) must aligned to the correct byte boundary. To determine if the buffer is on the correct byte boundary, perform a bitwise logical AND of the bitmask with the address of the data buffer. For example, if the address of the buffer is 0x3840958, you can test for correct alignment using the following statement:

``` syntax
if (0x3840958 & (value - 1) == 0)
{
    // The alignment is correct
}
```

## See also

[IDiscRecorder2Ex](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2ex)

[IDiscRecorder2Ex::SendCommandGetDataFromDevice](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-sendcommandgetdatafromdevice)

[IDiscRecorder2Ex::SendCommandNoData](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-sendcommandnodata)

[IDiscRecorder2Ex::SendCommandSendDataToDevice](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-sendcommandsenddatatodevice)