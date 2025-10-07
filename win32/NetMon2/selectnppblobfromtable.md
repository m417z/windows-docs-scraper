# SelectNPPBlobFromTable function

The **SelectNPPBlobFromTable** function selects a NIC from a supplied NPP BLOB table.

## Parameters

*hwnd* \[in\]

Handle to the window that displays the **Select a network** dialog box.

*pBlobTable* \[in\]

Pointer to the supplied BLOB table. Network Monitor uses this table to populate the **Select a network** dialog box.

*hBlob* \[out\]

Handle to the BLOB that represents the selected NIC.

## Return value

If the function is successful and the user selects a NIC, the return value is NMERR\_SUCCESS; the BLOB pointed to by *hBlob* is filled in.

If the user does not select a NIC, the return value is NMERR\_NO\_NPP\_SELECTED.

If the function is unsuccessful, the return value is another NMERR value.

## Remarks

When called, Network Monitor displays the **Select a network** dialog box, which you can use to select a NIC. The NPP BLOB that represents the selected NIC returns to the calling application.

To learn the various ways you can select NICs, see [Selecting a Network Interface Card](https://learn.microsoft.com/windows/win32/netmon2/selecting-a-network-interface-card)

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Npptools.lib |
| DLL<br> | Npptools.dll |

## See also

[GetNPPBlobFromUI](https://learn.microsoft.com/windows/win32/netmon2/getnppblobfromui)

[GetNPPBlobTable](https://learn.microsoft.com/windows/win32/netmon2/getnppblobtable)

[Special BLOB Entries](https://learn.microsoft.com/windows/win32/netmon2/special-blob-entries)

