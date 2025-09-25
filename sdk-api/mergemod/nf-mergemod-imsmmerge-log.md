# IMsmMerge::Log

## Description

The
**Log** method writes a text string to the currently open log file. For more information, see the
[Log](https://learn.microsoft.com/windows/desktop/Msi/merge-log) method of the
[Merge](https://learn.microsoft.com/windows/desktop/Msi/merge-object) object.

**IMsmMerge2::Log** Mergemod.dll version 2.0 or later.**IMsmMerge::Log** All Mergemod.dll versions.

## Parameters

### `Message`

The text string to display. A **LPCWSTR** may be used instead of a **BSTR**.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_FAIL** | There was an error writing to the log file. |
| **E_INVALIDARG** | The argument is invalid. |
| **S_FALSE** | No log file is open. |
| **S_OK** | The function succeeded. |

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)