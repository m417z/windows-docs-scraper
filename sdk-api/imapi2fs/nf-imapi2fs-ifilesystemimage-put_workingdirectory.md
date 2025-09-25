# IFileSystemImage::put_WorkingDirectory

## Description

Sets the temporary directory in which stash files are built.

## Parameters

### `newVal` [in]

String that contains the path to the temporary working directory. The default is the current temp directory.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_INVALID_PARAM** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |
| **IMAPI_E_INVALID_WORKING_DIRECTORY** | The working directory *%1!ls!* is not valid.<br><br>Value: 0xC0AAB140 |
| **IMAPI_E_WORKING_DIRECTORY_SPACE** | Cannot set working directory to *%1!ls!*. Space available is *%2!I64d!* bytes, approximately *%3!I64d!* bytes required. <br><br>Value: 0xC0AAB141 |

## Remarks

Stash files are the temporary files used to build the file-system image.

An exception results if the existing stash files cannot move to the new working directory.

You cannot change the working directory if a result stream exists for the file-system image.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_WorkingDirectory](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_workingdirectory)