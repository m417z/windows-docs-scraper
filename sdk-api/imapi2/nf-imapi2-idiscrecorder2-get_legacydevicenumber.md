# IDiscRecorder2::get_LegacyDeviceNumber

## Description

Retrieves the legacy device number for a CD or DVD device.

## Parameters

### `legacyDeviceNumber` [out]

Zero-based index number of the device, based on the order the device was installed on the computer.

This value can change during PNP activity when devices are added or removed from the computer, or across boot sessions and should not be considered a unique identifier for the device.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |

## See also

[IDiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2)

[IDiscRecorder2::get_VolumePathNames](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-get_volumepathnames)