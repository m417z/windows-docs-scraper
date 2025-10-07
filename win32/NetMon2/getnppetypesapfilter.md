# GetNPPEtypeSapFilter function

The **GetNPPEtypeSapFilter** function retrieves the Etype/Sap filter from a given BLOB.

## Parameters

*hBlob* \[in\]

Handle to the BLOB.

*pnSaps* \[out\]

Pointer to the returned number of protocols in the SAP table.

*pnEtypes* \[out\]

Pointer to the returned number of Etypes in the Etype table.

*ppSapTable* \[out\]

Pointer to the returned SAP table.

*ppEtypeTable* \[out\]

Pointer to the returned Etype table.

*pFilterFlags* \[out\]

Pointer to the returned filter flags.

*hErrorBlob* \[out\]

Handle to an error BLOB, which specifies the location in the original BLOB where the error (if any) occurred.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is a NMERR value that indicates the error.

## Remarks

The Etype/Sap information is stored in the **Config** category of the NPP **Owner** section.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Npptools.lib |
| DLL<br> | Npptools.dll |

## See also

[SetNPPEtypeSapFilter](https://learn.microsoft.com/windows/win32/netmon2/setnppetypesapfilter)

