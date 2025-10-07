# GetFrameSrcAddressOffset function

The **GetFrameSrcAddressOffset** function returns the offset of the frame's source address.

## Parameters

*hFrame*

Handle to the frame.

*AddressType*

Source address type. The parameter value can be one of the following:

- ADDRESS\_TYPE\_ETHERNET
- ADDRESS\_TYPE\_IP
- ADDRESS\_TYPE\_IPX
- ADDRESS\_TYPE\_TOKENRING
- ADDRESS\_TYPE\_FDDI
- ADDRESS\_TYPE\_XNS
- ADDRESS\_TYPE\_VINES\_IP
- ADDRESS\_TYPE\_ATM

*AddressLength*

Pointer to a **DWORD**, which on return, contains the length of the address, in bytes.

## Return value

If the function is successful, the return value is the offset to the source address.

If the function is unsuccessful, the return value is minus one (-1).

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

