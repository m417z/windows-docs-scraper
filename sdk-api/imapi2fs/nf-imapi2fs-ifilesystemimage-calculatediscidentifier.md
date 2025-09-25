# IFileSystemImage::CalculateDiscIdentifier

## Description

Retrieves a string that identifies a disc and the sessions recorded on the disc.

## Parameters

### `discIdentifier` [out]

String that contains a signature that identifies the disc and the sessions on it. This string is not guaranteed to be unique between discs.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **IMAPI_E_MULTISESSION_NOT_SET** | MultisessionInterfaces property must be set prior calling this method.<br><br>Value: 0xC0AAB15D |

## Remarks

When layering sessions on a disc, the signature acts as a key that the client can use to ensure the session order, and to distinguish sessions on disc from session images that will be laid on the disc.

You must call [IFileSystemImage::put_MultisessionInterfaces](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_multisessioninterfaces) prior to calling **CalculateDiscIdentifier**.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)