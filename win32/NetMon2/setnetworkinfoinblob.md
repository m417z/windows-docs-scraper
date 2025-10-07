# SetNetworkInfoInBlob function

The **SetNetworkInfoInBlob** function fills in the **NETWORKINFO** structure in the BLOB.

## Parameters

*hBlob* \[in\]

Handle to a BLOB.

*lpNetworkInfo* \[in\]

Pointer to the user-allocated [NETWORKINFO](https://learn.microsoft.com/windows/win32/netmon2/networkinfo) structure that the function fills in.

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

[GetNetworkInfoFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getnetworkinfofromblob)

[SetBoolInBlob](https://learn.microsoft.com/windows/win32/netmon2/setboolinblob)

[SetClassIDInBlob](https://learn.microsoft.com/windows/win32/netmon2/setclassidinblob)

[SetDwordInBlob](https://learn.microsoft.com/windows/win32/netmon2/setdwordinblob)

[SetMacAddressInBlob](https://learn.microsoft.com/windows/win32/netmon2/setmacaddressinblob)

[SetNPPAddressFilterInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnppaddressfilterinblob)

[SetNPPPatternFilterInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnpppatternfilterinblob)

[SetNPPTriggerInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnpptriggerinblob)

[SetStringInBlob](https://learn.microsoft.com/windows/win32/netmon2/setstringinblob)

