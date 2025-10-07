# GetNPPBlobTable function

The **GetNPPBlobTable** function retrieves an NPP BLOB table that represents the register NICs on the local computer.

## Parameters

*hFilterBlob* \[in\]

Handle to a filter BLOB that limits the NPP BLOBs returned in the table.

*ppBlobTable* \[out\]

Pointer to a [BLOB\_TABLE](https://learn.microsoft.com/windows/win32/netmon2/blob-table) structure that contains at least one BLOB pointer.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is one of the following error codes:

| Return code | Description |
|------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------|
| **NMERR\_NO\_NPP\_DLL** | No DLLs were found in the NPP directory.<br> |
| **NMERR\_NO\_VALID\_NPP\_DLLS** | None of the DLLs in the NPP directory were valid NPP DLLs.<br> |
| **NMERR\_NO\_MATCHING\_NPPS** | NPP BLOBs were discovered, but none passed the filter test.<br> |
| **NMERR\_OUT\_OF\_MEMOR** | Network Monitor was not able to allocate memory.<br> |

## Remarks

The BLOB named by *hFilterBlob* can also be a special BLOB.

If you set the flag in the filter BLOB to **TRUE**, the returned BLOB table can also include special BLOBs .

If the BLOB named by *hFilterBlob* is a special BLOB, the Network Monitor UI will attempt to process it. For example, suppose that a previous call returns a special BLOB from the remote NPP. The application inserts the required tag, MACHINE\_NAME. The finder then passes this BLOB to the remote NPP, which then returns a table of the NPP BLOBs associated with the machine name.

To destroy all returned BLOBs and the BLOB table, the caller is responsible for calling the **DestroyBlob** function.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Npptools.lib |
| DLL<br> | Npptools.dll |

