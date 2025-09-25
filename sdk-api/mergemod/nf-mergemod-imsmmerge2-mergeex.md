# IMsmMerge2::MergeEx

## Description

The
**MergeEx** method executes a merge of the current database and current module. The merge attaches the components in the module to the feature identified by *Feature*. The root of the module's directory tree is redirected to the location given by *RedirectDir*. For more information, see the
[MergeEx](https://learn.microsoft.com/windows/desktop/Msi/merge-mergeex) method of the [Merge](https://learn.microsoft.com/windows/desktop/Msi/merge-object) object.

## Parameters

### `Feature` [in]

The name of a feature in the database. A **LPCWSTR** may be used in place of a **BSTR**.

### `RedirectDir` [in]

The key of an entry in the Directory table of the database. A **LPCWSTR** may be used in place of a **BSTR**. This parameter may be **NULL** or an empty string.

### `pConfiguration` [in]

The *pConfiguration* argument is an interface implemented by the client. The argument may be **NULL**. The presence of this argument indicates that the client tool is capable of modifying configurable merge modules. The presence of this argument does not require the client to provide configuration data for any specific configurable item.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_OUTOFMEMORY** | The system ran out of memory and could not complete the operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **E_FAIL** | The merge was stopped due to an error. Some tables may not have been merged. See the Remarks section for more information. |
| **S_FALSE** | The function succeeded, but there were errors and the merge itself may not be valid. |
| **S_OK** | The function succeeded. |

## Remarks

This function executes a merge of the current database and current module. The root of the module's directory tree is redirected to the location given by *RedirectDir*. If any merge conflicts occur, including exclusions, they are placed in the error enumerator for later retrieval, but does not cause the merge to fail. Errors may be retrieved using
[get_Errors](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmmerge-get_errors) function. Errors and informational messages will be posted to the current log file.

Once the merge is complete, components in the module are attached to the feature identified by *Feature*. This feature must already exist and is not created. The module may be attached to additional features using
[Connect](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmmerge-connect) function.

Changes made to the database will not be saved to disk unless
[CloseDatabase](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmmerge-closedatabase) function is called with *bCommit* set to **TRUE**.

When the merge fails because of an incorrect module configuration the function returns E_FAIL. This includes these msmErrorType errors: msmErrorBadNullSubstitution, msmErrorBadSubstitutionType, msmErrorBadNullResponse, msmErrorMissingConfigItem, and msmErrorDataRequestFailed. These errors cause the merge to stop immediately when the error is encountered. The error object is still added to the enumerator when
**MergeEx** returns E_FAIL. For more information about msmErrorType errors, see
[get_Type Function (Error Object)](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmerror-get_type). All other errors cause
**MergeEx** to return S_FALSE and cause the merge to continue.

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)