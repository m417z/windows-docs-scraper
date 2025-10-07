# SetMacAddressInBlob function

The **SetMacAddressInBlob** function sets the requested MAC address of a BLOB.

## Parameters

*hBlob* \[in\]

Handle to the BLOB being set.

*pOwnerName* \[in\]

Pointer to the BLOB **Owner** name being set.

*pCategoryName* \[in\]

Pointer to the BLOB **Category** name being set.

*pTagName* \[in\]

Pointer to the BLOB **Tag** name being set.

*pMacAddress* \[in\]

Pointer to the MAC address of the BLOB being set.

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

[GetMacAddressFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getmacaddressfromblob)

[SetBoolInBlob](https://learn.microsoft.com/windows/win32/netmon2/setboolinblob)

[SetClassIDInBlob](https://learn.microsoft.com/windows/win32/netmon2/setclassidinblob)

[SetDwordInBlob](https://learn.microsoft.com/windows/win32/netmon2/setdwordinblob)

[SetNetworkInfoInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnetworkinfoinblob)

[SetNPPAddressFilterInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnppaddressfilterinblob)

[SetNPPPatternFilterInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnpppatternfilterinblob)

[SetNPPTriggerInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnpptriggerinblob)

[SetStringInBlob](https://learn.microsoft.com/windows/win32/netmon2/setstringinblob)

