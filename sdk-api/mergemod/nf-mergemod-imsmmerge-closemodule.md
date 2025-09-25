# IMsmMerge::CloseModule

## Description

The
**CloseModule** method closes the currently open Windows Installer merge module. For more information, see the
[CloseModule](https://learn.microsoft.com/windows/desktop/Msi/merge-closemodule) method of the
[Merge object](https://learn.microsoft.com/windows/desktop/Msi/merge-object).

**IMsmMerge2::CloseDatabase** Mergemod.dll version 2.0 or later.[IMsmMerge::CloseDatabase](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmmerge-closedatabase) All Mergemod.dll versions.

## Return value

The **CloseModule** function returns the following values.

| Value | Meaning |
| --- | --- |
| **E_FAIL** | There was an error closing the module. The state of the [IMsmMerge](https://learn.microsoft.com/windows/desktop/api/mergemod/nn-mergemod-imsmmerge) or [IMsmMerge2](https://learn.microsoft.com/windows/desktop/api/mergemod/nn-mergemod-imsmmerge2) interface is now undefined. |
| **S_FALSE** | No module was open. |
| **S_OK** | The function succeeded. |

## Remarks

Closing a merge module does not affect any errors that have not been retrieved.

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)