# GetDwordFromBlob function

The **GetDwordFromBlob** function retrieves the named **DWORD** value from a BLOB.

## Parameters

*hBlob* \[in\]

Handle to a BLOB.

*pOwnerName* \[in\]

Pointer to the BLOB owner name.

*pCategoryName* \[in\]

Pointer to the BLOB category name.

*pTagName* \[in\]

Pointer to the BLOB tag name.

*pDword* \[out\]

Pointer to the **DWORD** value of the BLOB.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is a NMERR value that describes the error.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Npptools.lib |
| DLL<br> | Npptools.dll |

## See also

[SetDwordInBlob](https://learn.microsoft.com/windows/win32/netmon2/setdwordinblob)

[GetBoolFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getboolfromblob)

[GetClassIDFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getclassidfromblob)

[GetMacAddressFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getmacaddressfromblob)

[GetNetworkInfoFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getnetworkinfofromblob)

[GetNPPAddressFilterFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getnppaddressfilterfromblob)

[GetNPPPatternFilterFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getnpppatternfilterfromblob)

[GetNPPTriggerFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getnpptriggerfromblob)

[GetStringFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getstringfromblob)

[GetStringsFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getstringsfromblob)

