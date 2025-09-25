# IMultisession::get_ImportRecorder

## Description

Retrieves the disc recorder to use to import one or more previous sessions.

## Parameters

### `value` [out]

An [IDiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2) interface that identifies the device that contains one or more session images to import.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

The import recorder reads session content from the optical media and provides it to [IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage).

## See also

[IMultisession](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisession)