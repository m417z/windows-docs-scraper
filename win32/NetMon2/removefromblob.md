# RemoveFromBlob function

The **RemoveFromBlob** function deletes any level of BLOB entry (**Owner**, **Category**, or **Tag**).

## Parameters

*hBlob* \[in\]

Handle to the BLOB from which an entry is deleted.

*pOwnerName* \[in\]

Pointer to the **Owner** name.

*pCategoryName* \[in\]

Pointer to the **Category** name. A **NULL** parameter value indicates the caller is attempting to delete the given **Owner** information and all of its child entries. Note that if the *pCategoryName* parameter value is **NULL**, the *pTagName* parameter must also be **NULL**.

*pTagName* \[in\]

Pointer to the **Tag** name. A **NULL***pTagName* value indicates the caller is attempting to delete the given **Category** and all of its child entries. If the parameter value is not **NULL**, the caller is asking that only that the specified **Tag** entries be deleted.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is a NMERR value that indicates the error.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Npptools.lib |
| DLL<br> | Npptools.dll |

