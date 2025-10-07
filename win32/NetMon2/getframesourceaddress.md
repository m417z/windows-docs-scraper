# GetFrameSourceAddress function

The **GetFrameSourceAddress** function retrieves the source address of a frame.

## Parameters

*hFrame*

A handle to the frame for which to get a pointer to.

*lpAddress*

A return buffer that stores the frame source address.

*AddressType*

The type of address searched for, such as ADDRESS\_TYPE\_ETHERNET or ADDRESS\_TYPE\_IP.

*Flags*

The flags used to modify returned source address data.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------|
| **ADDRESSTYPE\_FLAGS\_NORMALIZE** | Cancels the routing and group BITs.<br> |
| **ADDRESSTYPE\_FLAGS\_BIT\_REVERSE** | Converts token ring network addresses back to normal.<br> |

## Return value

If the function is successful, the *lpAddress* value is valid, and the return value is BHERR\_SUCCESS.

If the function is unsuccessful, the return value is an error code.

| Return code | Description |
|------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------|
| **BHERR\_PROTOCOL\_NOT\_FOUND** | The protocol specified by the *AddressType* parameter is invalid for the frame.<br> |
| **BHERR\_INVALID\_HFRAME** | The *hFrame* parameter value is invalid.<br> |

## Remarks

An address type of **ADDRESS\_TYPE\_FIND\_HIGHEST** is allowed. When this address type is used, the function searches for the IPX, XNS, IP, or VINES IP address before returning the ETHERNET, TOKENRING, or FDDI address. This approach is useful for protocols and environments in which two NICs can be multiplexed under a single server address.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

