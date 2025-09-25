# SetupGetFileQueueCount function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupGetFileQueueCount** function gets the count from a setup file queue.

## Parameters

### `FileQueue` [in]

Handle to an open setup file queue.

### `SubQueueFileOp` [in]

Flag that specifies which subqueue count to be returned.

| Flag | Meaning |
| --- | --- |
| **FILEOP_COPY** | Return the number of entries in the copy subqueue. |
| **FILEOP_RENAME** | Return the number of entries in the rename subqueue. |
| **FILEOP_DELETE** | Return the number of entries in the delete subqueue. |
| **FILEOP_BACKUP** | Return the number of entries in the backup subqueue. |

### `NumOperations` [out]

Count from the setup file queue.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)