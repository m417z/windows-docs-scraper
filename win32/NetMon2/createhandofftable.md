# CreateHandoffTable function

The **CreateHandoffTable** function creates a [*handoff table*](https://learn.microsoft.com/windows/win32/netmon2/h) that includes the handoff set information stored in the INI file of the parser.

## Parameters

*secName* \[in\]

String that indicates the section of the INI file where the handoff set information is located.

*iniFile* \[in\]

String that includes the name of the parser INI file.

*hTable* \[out\]

Handle to a **HANDOFFTABLE** structure created and maintained by Network Monitor.

*nMaxProtocolEntries* \[in\]

Number that specifies the maximum number of entries that the handoff table can process.

*base* \[in\]

Numerical base of handoff set numbers stored in the INI file.

## Return value

If the function is successful, the return value is the number of entries in the handoff table.

If the function is unsuccessful, the return value is zero.

## Remarks

The handoff table created by Network Monitor is based on information provided in the parser INI. The returned handle to the handoff table can then be used to obtain a handle to one of the protocols included in the table. To obtain a handle of one of these protocols, call [GetProtocolFromTable](https://learn.microsoft.com/windows/win32/netmon2/getprotocolfromtable).

Notice that the parser application never accesses the **HANDOFFTABLE** structure directly. This structure is created and maintained by Network Monitor.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[GetProtocolFromTable](https://learn.microsoft.com/windows/win32/netmon2/getprotocolfromtable)

[HANDOFFTABLE](https://learn.microsoft.com/windows/win32/netmon2/handofftable)

