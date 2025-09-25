# WINTRUST_FILE_INFO structure

## Description

The **WINTRUST_FILE_INFO** structure is used when calling
[WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) to verify an individual file.

## Members

### `cbStruct`

Count of bytes in this structure.

### `pcwszFilePath`

Full path and file name of the file to be verified. This parameter cannot be **NULL**.

### `hFile`

Optional. File handle to the open file to be verified. This handle must be to a file that has at least read permission. This member can be set to **NULL**.

### `pgKnownSubject`

Optional. Pointer to a [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that specifies the subject type. This member can be set to **NULL**.