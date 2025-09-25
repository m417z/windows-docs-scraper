# IMsmMerge::CloseLog

## Description

The
**CloseLog** function method closes the current log. For more information, see the
[CloseLog](https://learn.microsoft.com/windows/desktop/Msi/merge-closelog) method of the
[Merge](https://learn.microsoft.com/windows/desktop/Msi/merge-object) object.

**IMsmMerge2::CloseLog** Mergemod.dll version 2.0 or later.**IMsmMerge::CloseLog** All Mergemod.dll versions.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_FAIL** | There was an error closing the log file. |
| **S_FALSE** | No log file was open. |
| **S_OK** | The function succeeded. |

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)