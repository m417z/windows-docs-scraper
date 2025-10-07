# GetFrameDstAddressOffset function

The **GetFrameDstAddressOffset** function returns the offset to the destination address of a given frame.

## Parameters

*hFrame* \[in\]

Handle to the frame.

*AddressType* \[in\]

Type of the destination address. Specify one of the following values:

ADDRESS\_TYPE\_ETHERNET ADDRESS\_TYPE\_IP ADDRESS\_TYPE\_IPX ADDRESS\_TYPE\_TOKENRING ADDRESS\_TYPE\_FDDI ADDRESS\_TYPE\_XNS ADDRESS\_TYPE\_VINES\_IP ADDRESS\_TYPE\_ATM.

*AddressLength* \[in\]

Length of the destination address, in bytes.

## Return value

If the function is successful, the return value is the offset (measured in bytes) to the requested address type.

If the function is unsuccessful, the return value is minus one (-1).

## Remarks

If the *AddressType* parameter is set to ADDRESS\_TYPE\_ETHERNET, the return value of the **GetFrameDstAddressOffset** function is always zero. The offset of an Ethernet address is always zero.

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetFrameDstAddressOffset** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

