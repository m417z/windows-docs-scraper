# SdbDeclareIndex function

Declares a new index in the specified database.

## Parameters

*pdb* \[in\]

A handle to the shim database.

*tWhich* \[in\]

This parameter must be **TAG\_TYPE\_LIST**.

*tKey* \[in\]

The TAG that specifies the type to be used as the key. This parameter cannot be **TAG\_TYPE\_LIST**.

*dwEntries* \[in\]

The number of entries to allocate in the index.

*bUniqueKey* \[in\]

If this parameter is **TRUE**, the index is a unique-key index.

*piiIndex* \[out\]

The resulting **INDEXID** of the newly declared index.

## Return value

The function returns **TRUE** on success or **FALSE** on failure.

## Remarks

Call this function before writing tags to the new index.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**INDEXID**](https://learn.microsoft.com/windows/win32/devnotes/indexid)

[**SdbCommitIndexes**](https://learn.microsoft.com/windows/win32/devnotes/sdbcommitindexes)

[**SdbStartIndexing**](https://learn.microsoft.com/windows/win32/devnotes/sdbstartindexing)

[**SdbStopIndexing**](https://learn.microsoft.com/windows/win32/devnotes/sdbstopindexing)

