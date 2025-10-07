# GetStringFromBlob function

The **GetStringFromBlob** function returns a string located at a given position within a BLOB.

## Parameters

*hBlob* \[in\]

A handle to the BLOB.

*pOwnerName* \[in\]

A BLOB **Owner** section where the string is located.

*pCategoryName* \[in\]

A BLOB **Category** section where the string is located.

*pTagName* \[in\]

The **Tag** of the requested string.

*ppString* \[out\]

A pointer to a variable that points to the returned string.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is a NMERR value that indicates the error.

If the specified **Owner**, **Category**, or **Tag** data does not exist, the function returns **NMERR\_BLOB\_ENTRY\_DOES\_NOT\_EXIST**.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Npptools.lib |
| DLL<br> | Npptools.dll |

## See also

[SetStringInBlob](https://learn.microsoft.com/windows/win32/netmon2/setstringinblob)

[GetBoolFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getboolfromblob)

[GetClassIDFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getclassidfromblob)

[GetDwordFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getdwordfromblob)

[GetMacAddressFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getmacaddressfromblob)

[GetNetworkInfoFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getnetworkinfofromblob)

[GetNPPAddressFilterFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getnppaddressfilterfromblob)

[GetNPPPatternFilterFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getnpppatternfilterfromblob)

[GetNPPTriggerFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getnpptriggerfromblob)

[GetStringsFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getstringsfromblob)

