# SetNPPEtypeSapFilter function

The **SetNPPEtypeSapFilter** function sets the BLOB Etype/Sap filter.

## Parameters

*hBlob* \[in\]

A handle to the BLOB.

*nSaps* \[in\]

The number of SAPs.

*nEtypes* \[in\]

The number of Etypes in the Etype table being set.

*lpSapTable* \[in\]

A pointer to the SAP table that is set.

*lpEtypeTable* \[in\]

A pointer to the Etype table that is set.

*FilterFlags* \[in\]

The filter flags that are set.

*hErrorBlob* \[out\]

The handle to an error BLOB that specifies where in the original BLOB the error (if any) occurred.

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

## See also

[GetNPPEtypeSapFilter](https://learn.microsoft.com/windows/win32/netmon2/getnppetypesapfilter)

