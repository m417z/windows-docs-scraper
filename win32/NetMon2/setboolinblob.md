# SetBoolInBlob function

The **SetBoolInBlob** function sets a Boolean value at a given location within a BLOB.

## Parameters

*hBlob* \[in\]

Handle to a BLOB.

*pOwnerName* \[in\]

Pointer to the BLOB **Owner** name.

*pCategoryName* \[in\]

Pointer to the BLOB **Category** name.

*pTagName* \[in\]

Pointer to the BLOB **Tag** name.

*Bool* \[in\]

Boolean value that is set at the given location.

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

[GetBoolFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getboolfromblob)

[SetClassIDInBlob](https://learn.microsoft.com/windows/win32/netmon2/setclassidinblob)

[SetDwordInBlob](https://learn.microsoft.com/windows/win32/netmon2/setdwordinblob)

[SetMacAddressInBlob](https://learn.microsoft.com/windows/win32/netmon2/setmacaddressinblob)

[SetNetworkInfoInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnetworkinfoinblob)

[SetNPPAddressFilterInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnppaddressfilterinblob)

[SetNPPPatternFilterInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnpppatternfilterinblob)

[SetNPPTriggerInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnpptriggerinblob)

[SetStringInBlob](https://learn.microsoft.com/windows/win32/netmon2/setstringinblob)

