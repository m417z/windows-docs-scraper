# IMsmMerge::CloseDatabase

## Description

The
**CloseDatabase** method closes the currently open Windows Installer database. For more information, see the
[CloseDatabase](https://learn.microsoft.com/windows/desktop/Msi/merge-closedatabase) method of the
[Merge object](https://learn.microsoft.com/windows/desktop/Msi/merge-object).

**IMsmMerge2::CloseDatabase** Mergemod.dll version 2.0 or later.**IMsmMerge::CloseDatabase** All Mergemod.dll versions.

## Parameters

### `Commit`

**TRUE** if changes should be saved, **FALSE** otherwise.

## Return value

The **CloseDatabase** function returns the following values.

| Value | Meaning |
| --- | --- |
| **E_FAIL** | There was an error closing the database. The state of the [IMsmMerge](https://learn.microsoft.com/windows/desktop/api/mergemod/nn-mergemod-imsmmerge) or [IMsmMerge2](https://learn.microsoft.com/windows/desktop/api/mergemod/nn-mergemod-imsmmerge2) interface is now in an undefined state. |
| **S_FALSE** | No database was open. |
| **S_OK** | The function succeeded. |
| **STG_E_CANTSAVE as HRESULT** | Unable to save database. This error is not generated if *bCommit* is **FALSE**. |

## Remarks

This function closes the currently open database. Closing a database clears all dependency information but does not affect any errors that have not been retrieved.

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)