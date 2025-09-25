# IMsmMerge::OpenLog

## Description

The
**OpenLog** method opens a log file that receives progress and error messages. If the log file already exists, the installer appends new messages. If the log file does not exist, the installer creates a log file. For more information, see the
[OpenLog](https://learn.microsoft.com/windows/desktop/Msi/merge-openlog) method of the
[Merge](https://learn.microsoft.com/windows/desktop/Msi/merge-object) object.

**IMsmMerge2::OpenLog** Mergemod.dll version 2.0 or later.**IMsmMerge::OpenLog** All Mergemod.dll versions.

## Parameters

### `Path` [in]

Fully qualified file name pointing to a file to open or create. A **LPCWSTR** may be used in place of a **BSTR**.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **ERROR_TOO_MANY_OPEN_FILES as HRESULT** | There is already a log file open. |
| **ERROR_OPEN_FAILED as HRESULT** | The file could not be opened or created. |
| **S_OK** | The function succeeded. |

## Remarks

This function opens a log file to receive progress and error messages. If the log file already exists, new messages get appended to the log. If the log file does not exist it is created.

Clients may send their own messages to this log file using [Log](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmmerge-log).

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)