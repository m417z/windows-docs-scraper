# CompareFrameDestAddress function

The **CompareFrameDestAddress** function compares an address to the destination address of a frame.

## Parameters

*hFrame* \[in\]

Handle to a frame.

*lpAddress* \[in\]

Pointer to an address.

## Return value

If the addresses are the same, the return value is **TRUE**.

If the addresses are not the same, the return value is **FALSE**.

## Remarks

For the **CompareFrameDestAddress** function to return successfully, the destination address type must match the type of address specified in the *lpAddress* parameter.

Network Monitor provides two other functions, [CompareFrameSourceAddress](https://learn.microsoft.com/windows/win32/netmon2/compareframesourceaddress) and [CompareAddresses](https://learn.microsoft.com/windows/win32/netmon2/compareaddresses), which you can use to compare addresses. The **CompareFrameSourceAddress** function compares a given address to the frame's source address, and the **CompareAddress** function compares two given addresses.

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **CompareFrameDestAddress** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[CompareAddresses](https://learn.microsoft.com/windows/win32/netmon2/compareaddresses)

[CompareFrameSourceAddress](https://learn.microsoft.com/windows/win32/netmon2/compareframesourceaddress)

