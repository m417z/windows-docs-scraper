# ValidateLog function

## Description

Validates the consistency of the log metadata and data before log archive and after log restore.

## Parameters

### `pszLogFileName` [in]

The name of the log.

The name is specified when creating the log by using [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile). The following example identifies the format to use:

*Log***:<***LogName***>[::<***LogStreamName***>]**

**<***LogName***>** corresponds to a valid file path in the file system.

**<***LogStreamName***>** is the unique name of a log stream in the dedicated log.

For more information, see [Log Types](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/log-types).

### `psaLogFile` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that specifies the security attributes of a log.

This parameter can be **NULL**.

### `pinfoBuffer` [out, optional]

A pointer to a [CLFS_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_information) structure that receives log metadata.

### `pcbBuffer` [in, out]

A pointer to a variable that, on input, specifies the size of the *pinfoBuffer* metadata buffer, in bytes.

On output, it receives the amount of information that is copied to the buffer, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following list identifies the possible error codes:

## See also

[CLFS_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_information)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)