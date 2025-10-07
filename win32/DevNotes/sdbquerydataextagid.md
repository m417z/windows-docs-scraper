# SdbQueryDataExTagID function

Retrieves data from the specified entries belonging to an EXE entry.

## Parameters

*pdb* \[in\]

A handle to the shim database.

*tiExe* \[in\]

The [**TAGID**](https://learn.microsoft.com/windows/win32/devnotes/tagid) of the EXE entry.

*lpszDataName* \[in, optional\]

The name of the data entry to be retrieved. To specify multiple entries, separate the names with the backslash character ("\\"). If this parameter is **NULL**, the function attempts to return all data entries.

*lpdwDataType* \[out, optional\]

The data type of the returned entries. This parameter can be one of the following values:

**REG\_BINARY**

**REG\_DWORD**

**REG\_MULTI\_SZ**

**REG\_NONE**

**REG\_QWORD**

**REG\_SZ**

*lpBuffer* \[out\]

The buffer that receives the data. If buffer is not large enough to contain the data, the function fails and returns **ERROR\_INSUFFICIENT\_BUFFER**.

*lpcbBufferSize* \[in, out, optional\]

The size of the *lpBuffer* buffer, in bytes.

*ptiData* \[out\]

The [**TAGID**](https://learn.microsoft.com/windows/win32/devnotes/tagid) of the data entry.

## Return value

This function returns one of the following values.

| Return code | Description |
|----------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------|
| **ERROR\_INVALID\_PARAMETER** | One or more input parameters is incorrect.<br> |
| **ERROR\_INTERNAL\_DB\_CORRUPTION** | No data entries were found for the EXE entry.<br> |
| **ERROR\_INSUFFICIENT\_BUFFER** | The buffer is not large enough to contain the data entries.<br> |
| **ERROR\_NOT\_ENOUGH\_MEMORY** | The memory allocation failed.<br> |
| **ERROR\_NOT\_FOUND** | A data entry with the name *lpszDataName* was not found.<br> |
| **ERROR\_SUCCESS** | The function completed successfully.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

