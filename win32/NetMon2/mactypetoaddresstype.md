# MacTypeToAddressType function

The **MacTypeToAddressType** function converts a given MAC type to an address type.

## Parameters

*MacType* \[in\]

MAC type to be converted. Specify one of the following values:

MAC\_TYPE\_ETHERNET MAC\_TYPE\_TOKENRING MAC\_TYPE\_FDDI

## Return value

If the function is successful, the return value is one of the following address types.

ADDRESS\_TYPE\_ETHERNET ADDRESS\_TYPE\_TOKENRING ADDRESS\_TYPE\_FDDI

If the function is unsuccessful, the MAC type is unknown, the return value is -1.

## Remarks

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **MacTypeToAddressType** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

