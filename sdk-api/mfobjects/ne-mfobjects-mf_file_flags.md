# MF_FILE_FLAGS enumeration

## Description

Specifies the behavior when opening a file.

## Constants

### `MF_FILEFLAGS_NONE:0`

Use the default behavior.

### `MF_FILEFLAGS_NOBUFFERING:0x1`

Open the file with no system caching.

### `MF_FILEFLAGS_ALLOW_WRITE_SHARING:0x2`

Subsequent open operations can have write access to the file.

**Note** Requires Windows 7 or later.

## See also

[MFBeginCreateFile](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfbegincreatefile)

[MFCreateFile](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatefile)

[MFCreateTempFile](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatetempfile)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)