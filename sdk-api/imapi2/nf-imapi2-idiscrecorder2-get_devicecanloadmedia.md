# IDiscRecorder2::get_DeviceCanLoadMedia

## Description

Determines if the device can eject and subsequently reload media.

## Parameters

### `value` [out]

Is VARIANT_TRUE if the device can eject and subsequently reload media. If VARIANT_FALSE, loading media must be done manually.

**Note** For slim drives or laptop drives, which utilize a manual tray-loading mechanism, this parameter can indicate an incorrect value of VARIANT_TRUE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |

## See also

[IDiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2)

[IDiscRecorder2::EjectMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-ejectmedia)