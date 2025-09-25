# IMsmMerge::Connect

## Description

The
**Connect** method connects a module that has been, or will be, merged into the database to an additional feature. For more information, see the
[Connect](https://learn.microsoft.com/windows/desktop/Msi/merge-connect) method of the
[Merge](https://learn.microsoft.com/windows/desktop/Msi/merge-object) object.

**IMsmMerge2::Connect** Mergemod.dll version 2.0 or later.**IMsmMerge::Connect** All Mergemod.dll versions.

## Parameters

### `Feature` [in]

The name of a feature in the database. A **LPCWSTR** may be used in place of a **BSTR**.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **E_FAIL** | The connect failed. |
| **S_OK** | The function succeeded. |

## Remarks

The feature must exist before this function is called. Errors may be retrieved using
[get_Errors](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmmerge-get_errors). Errors and informational messages are posted to the current log file.

Changes made to the database are not be saved to disk unless
[CloseDatabase](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmmerge-closedatabase) function is called with *bCommit* set to **TRUE**.

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)