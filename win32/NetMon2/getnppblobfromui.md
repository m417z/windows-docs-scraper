# GetNPPBlobFromUI function

The **GetNPPBlobFromUI** function selects a register NIC.

## Parameters

*hwnd* \[in\]

A handle to a window that displays the **Select a network** dialog box.

*hFilterBlob* \[in\]

A handle to a [*filter BLOB*](https://learn.microsoft.com/windows/win32/netmon2/f) used to limit which NICs are displayed.

*phBlob* \[out\]

A pointer to the handle of the BLOB that represents the selected NIC.

## Return value

If the function is successful (the user selects a NIC), the return value is NMERR\_SUCCESS, and the BLOB that *phBlob* points to is filled in.

If the user does not select an NIC, the return value is **NMERR\_NO\_NPP\_SELECTED**.

If the function is unsuccessful, the return value is another NMERR value.

## Remarks

When called, Network Monitor displays the **Select a network** dialog box, which you can use to select a NIC. The NPP BLOB that represents the NIC is returned to the calling application.

If the BLOB named by *hFilterBlob* is a [*special BLOB*](https://learn.microsoft.com/windows/win32/netmon2/s), the finder will attempt to process it. An example would be a call that had previously returned a special BLOB from the remote NPP. The application inserted the required tag, MACHINE\_NAME. In this situation, the finder would pass this BLOB to the remote NPP, which would then return a table of NPP BLOBs representing the machine requested. These remote NPP BLOBs would appear in the dialog box.

The caller must call the [DestroyBlob](https://learn.microsoft.com/windows/win32/netmon2/destroyblob) function, which destroys the returned BLOB when it is no longer required.

| For more information about | See |
|----------------------------|------------------------------------------------------------------------------|
| Three ways to select NICs | [Selecting a Network Interface Card](https://learn.microsoft.com/windows/win32/netmon2/selecting-a-network-interface-card) |
| Specifying a filter BLOB | [Specifying a Filter BLOB](https://learn.microsoft.com/windows/win32/netmon2/specifying-a-filter-blob) |

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Npptools.lib |
| DLL<br> | Npptools.dll |

## See also

[GetNPPBlobTable](https://learn.microsoft.com/windows/win32/netmon2/getnppblobtable)

[SelectNPPBlobFromTable](https://learn.microsoft.com/windows/win32/netmon2/selectnppblobfromtable)

