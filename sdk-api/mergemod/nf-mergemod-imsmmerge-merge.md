# IMsmMerge::Merge

## Description

The
**Merge** method executes a merge of the current database and current module. The merge attaches the components in the module to the feature identified by *Feature*. The root of the module's directory tree is redirected to the location given by *RedirectDir*. For more information, see the
**Merge** method of the [Merge](https://learn.microsoft.com/windows/desktop/Msi/merge-object) object.

**IMsmMerge2::Merge** Mergemod.dll version 2.0 or later.**IMsmMerge::Merge** All Mergemod.dll versions.

## Parameters

### `Feature` [in]

The name of a feature in the database. A **LPCWSTR** can be used in place of a **BSTR**.

### `RedirectDir` [in]

The key of an entry in the Directory table of the database. A **LPCWSTR** can be used in place of a **BSTR**. This parameter can be null or an empty string.

## Return value

The **Merge** function returns the following values.

| Value | Meaning |
| --- | --- |
| **E_FAIL** | The merge failed catastrophically. This indicates an operational error, and is not the normal error return for a failed merge. |
| **S_FALSE** | The function succeeded, but there were errors and the merge itself may not be valid. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **E_OUTOFMEMORY** | The system ran out of memory and could not complete the operation. |
| **S_OK** | The function succeeded. |

## Remarks

This function executes a merge of the current database and current module. The root of the module's directory tree is redirected to the location given by *RedirectDir*. If any merge conflicts occur, including exclusions, they are placed in the error enumerator for later retrieval, but does not cause the merge to fail. Errors can be retrieved using the [get_Errors](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmmerge-get_errors) function. Errors and informational messages are posted to the current log file.

Note that the
**Merge** function gets all the feature references in the module and substitutes the feature reference for all occurrences of the null GUID in the module database. For more information, see
[Referencing Features in Merge Modules](https://learn.microsoft.com/windows/desktop/Msi/referencing-features-in-merge-modules).

Once the merge is complete, components in the module are attached to the feature identified by *Feature*. This feature must already exist and is not created.

The module can be attached to additional features using the
[Connect](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmmerge-connect) function. Note that calling the
**Connect** function only creates feature-component associations. It does not modify the rows that have already been merged in to the database.

Changes made to the database are not saved to disk unless
the [CloseDatabase](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmmerge-closedatabase) function is called with *bCommit* set to **TRUE**.

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)