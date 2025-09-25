# MF_FILE_OPENMODE enumeration

## Description

Specifies how to open or create a file.

## Constants

### `MF_OPENMODE_FAIL_IF_NOT_EXIST:0`

Open an existing file. Fail if the file does not exist.

### `MF_OPENMODE_FAIL_IF_EXIST:1`

Create a new file. Fail if the file already exists.

### `MF_OPENMODE_RESET_IF_EXIST:2`

Open an existing file and truncate it, so that the size is zero bytes. Fail if the file does not already exist.

### `MF_OPENMODE_APPEND_IF_EXIST:3`

If the file does not exist, create a new file. If the file exists, open it.

### `MF_OPENMODE_DELETE_IF_EXIST:4`

Create a new file. If the file exists, overwrite the file.

## See also

[MFBeginCreateFile](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfbegincreatefile)

[MFCreateFile](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatefile)

[MFCreateTempFile](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatetempfile)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)