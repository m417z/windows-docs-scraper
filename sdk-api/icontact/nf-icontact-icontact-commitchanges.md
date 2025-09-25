# IContact::CommitChanges

## Description

Saves changes made to this contact to the contact file.

## Parameters

### `dwCommitFlags` [in]

Type: **DWORD**

Reserved parameter. Must be 0.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Changes written to disk successfully. |
| **E_UNEXPECTED** | Contact not loaded from a file path. |
| **ERROR_SHARING_VIOLATION** | Another process modified the file in a way incompatible with changes to this contact. |

## Remarks

If the contact changes between creation and **IContact::CommitChanges**
and an incompatible change was made on disk, may return ERROR_SHARING_VIOLATION.