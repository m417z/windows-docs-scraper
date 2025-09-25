# PathCleanupSpec function

## Description

[**PathCleanupSpec** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Removes illegal characters from a file or directory name. Enforces the 8.3 filename format on drives that do not support long file names.

## Parameters

### `pszDir` [in, optional]

Type: **PCWSTR**

A pointer to a null-terminated buffer that contains the fully qualified path of the directory that will contain the file or directory named at *pszSpec*. The path must not exceed MAX_PATH characters in length, including the terminating null character. This path is not altered.

This value can be **NULL**.

### `pszSpec` [in, out]

Type: **PWSTR**

A pointer to a null-terminated buffer that contains the file or directory name to be cleaned. In the case of a file, include the file's extension. Note that because '\' is considered an invalid character and will be removed, this buffer cannot contain a path more than one directory deep.

On exit, the buffer contains a null-terminated string that includes the cleaned name.

This buffer should be at least MAX_PATH characters in length to avoid the possibility of a buffer overrun.

## Return value

Type: **int**

Returns one or more of the following values.

| Return code | Description |
| --- | --- |
| **PCS_REPLACEDCHAR** | Replaced one or more invalid characters. |
| **PCS_REMOVEDCHAR** | Removed one or more invalid characters. |
| **PCS_TRUNCATED** | The returned path is truncated. |
| **PCS_PATHTOOLONG** | The function failed because the input path specified at *pszDir* is too long to allow the formation of a valid file name from *pszSpec*. When this flag is returned, it is always accompanied by the PCS_FATAL flag. |
| **PCS_FATAL** | The cleaned path is not a valid file name. This flag is always returned in conjunction with PCS_PATHTOOLONG. |

## Remarks

The following are considered invalid characters in all names.

```
\ / : * ? " < > |
```

Control characters are also considered invalid. If long file names are not supported, the semi-colon (;) and comma (,) characters are also invalid.

The drive named in *pszDir* is checked to determine
whether its file system supports long file names. If it does not, the name at *pszSpec* is truncated to the 8.3 format and the PCS_TRUNCATED value returned. If *pszDir* is **NULL**, the drive on which Windows is installed is used to determine long file name support.

If the full path—the number of characters in the path at *pszDir* plus the number of characters in the cleaned name at *pszSpec*—exceeds MAX_PATH – 1 (to account for the terminating null character), the function returns PCS_PATHTOOLONG.