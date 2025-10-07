# SetStringInBlob function

The **SetStringInBlob** function sets a string at a given location within a BLOB.

## Parameters

*hBlob* \[in\]

A handle to the BLOB.

*pOwnerName* \[in\]

A pointer to the **Owner** section of the BLOB, where the string is set.

*pCategoryName* \[in\]

A pointer to the **Category** section of the BLOB, where the string is set.

*pTagName* \[in\]

A pointer to the **Tag** of the requested string.

*pString* \[in\]

A pointer to the variable where a pointer to the string will be returned.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is a NMERR value that indicates the problem.

If the specified **Owner**, **Category**, or **Tag** information does not exist, the return value is NMERR\_BLOB\_ENTRY\_DOES\_NOT\_EXIST.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Npptools.lib |
| DLL<br> | Npptools.dll |

## See also

[GetStringFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getstringfromblob)

[SetBoolInBlob](https://learn.microsoft.com/windows/win32/netmon2/setboolinblob)

[SetClassIDInBlob](https://learn.microsoft.com/windows/win32/netmon2/setclassidinblob)

[SetDwordInBlob](https://learn.microsoft.com/windows/win32/netmon2/setdwordinblob)

[SetMacAddressInBlob](https://learn.microsoft.com/windows/win32/netmon2/setmacaddressinblob)

[SetNetworkInfoInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnetworkinfoinblob)

[SetNPPAddressFilterInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnppaddressfilterinblob)

[SetNPPPatternFilterInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnpppatternfilterinblob)

[SetNPPTriggerInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnpptriggerinblob)

