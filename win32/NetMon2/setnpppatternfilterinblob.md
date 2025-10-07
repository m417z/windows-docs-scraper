# SetNPPPatternFilterInBlob function

The **SetNPPPatternFilterInBlob** function sets the BLOB pattern match filter.

## Parameters

*hBlob* \[in\]

The handle to the BLOB.

*pExpression* \[in\]

A pointer to an [EXPRESSION](https://learn.microsoft.com/windows/win32/netmon2/expression) structure that defines the filter expression being set.

*hErrorBlob* \[out\]

The handle to an error BLOB that specifies where in the original BLOB the error (if any) occurred.

## Return value

If the **SetNPPPatternFilterInBlob** function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is a NMERR value that indicates the error.

## Remarks

The pattern match filter data stored in the **Config** category of the BLOB.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Npptools.lib |
| DLL<br> | Npptools.dll |

## See also

[GetNPPAddressFilterFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getnppaddressfilterfromblob)

[SetBoolInBlob](https://learn.microsoft.com/windows/win32/netmon2/setboolinblob)

[SetClassIDInBlob](https://learn.microsoft.com/windows/win32/netmon2/setclassidinblob)

[SetDwordInBlob](https://learn.microsoft.com/windows/win32/netmon2/setdwordinblob)

[SetMacAddressInBlob](https://learn.microsoft.com/windows/win32/netmon2/setmacaddressinblob)

[SetNetworkInfoInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnetworkinfoinblob)

[SetNPPAddressFilterInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnppaddressfilterinblob)

[SetNPPTriggerInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnpptriggerinblob)

[SetStringInBlob](https://learn.microsoft.com/windows/win32/netmon2/setstringinblob)

