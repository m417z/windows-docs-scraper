# CompareAddresses function

The **CompareAddresses** function compares two addresses, indicating that one of the addresses is greater than, less than, or equal to the other address.

## Parameters

*lpAddress1* \[in\]

Pointer to the first address.

*lpAddress2* \[in\]

Pointer to the second address.

## Return value

If the addresses are the same, the function returns zero.

If the *lpAddress1* parameter specifies an address that is less than the address that the *lpAddress2* parameter specifies, the return value is a negative number.

If the *lpAddress1* parameter specifies an address that is greater than the address that the *lpAddress2* parameter specifies, the return value is a positive number.

## Remarks

An address that is less than another address indicates a previous frame. An address that is greater than another address indicates a later frame.

Network Monitor provides two other functions, [CompareFrameDestAddress](https://learn.microsoft.com/windows/win32/netmon2/compareframedestaddress) and [CompareFrameSourceAddress](https://learn.microsoft.com/windows/win32/netmon2/compareframesourceaddress), which you can use to compare addresses. The **CompareFrameDestAddress** function compares a given address to the frame's destination address, and the **CompareFrameSourceAddress** function compares a given address to the frame's source address.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[CompareFrameDestAddress](https://learn.microsoft.com/windows/win32/netmon2/compareframedestaddress)

[CompareFrameSourceAddress](https://learn.microsoft.com/windows/win32/netmon2/compareframesourceaddress)

