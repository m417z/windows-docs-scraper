# IFileSystemImage::SetMaxMediaBlocksFromDevice

## Description

Set maximum number of blocks available based on the capabilities of the recorder.

## Parameters

### `discRecorder` [in]

An [IDiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2) interface that identifies the recording device from which you want to set the maximum number of blocks available.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **IMAPI_E_FSI_INTERNAL_ERROR** | Internal error occurred: *%1!ls!*. |

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)