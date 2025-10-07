# GetStringsFromBlob function

The **GetStringsFromBlob** function uses sequential calls to retrieve all of the strings within specified ranges.

## Parameters

*hBlob* \[in\]

A handle to the BLOB.

*pRequestedOwnerName* \[in\]

A pointer to the Owner section to get the string from.

*pRequestedCategoryName* \[in\]

A pointer to the Category section to get the string from.

*pRequestedTagName* \[in\]

A pointer to the tag for the requested string.

*ppReturnedOwnerName* \[out\]

A pointer to the variable that points to where the **Owner** name will be returned.

*ppReturnedCategoryName* \[out\]

A pointer to the variable that points to where the **Category** name will be returned.

*ppReturnedTagName* \[out\]

A pointer to the variable that points to where the **Tag** name will be returned.

*ppReturnedString* \[out\]

A pointer to the variable that points to where the string name will be returned.

*pRestartKey* \[out\]

A pointer to the variable where the restart key will be specified and returned.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is a NMERR value that indicates the problem.

If a specified combination of **Owner**, **Category**, and **Tag** information does not exist, the return value is **NMERR\_BLOB\_ENTRY\_DOES\_NOT\_EXIST**.

When the BLOB is traversed completely within the bounds initially specified, the function returns **NMERR\_BLOB\_ENTRY\_DOES\_NOT\_EXIST**, and the *pRestartKey* parameter points to zero.

## Remarks

On the initial call to the **GetStringsFromBlob** function, the *pRestartKey* parameter points to a variable that contains the value zero. The *pRequested* parameters can be used only when the restart key is zero. In subsequent calls, when *pRestartKey* has nonzero values, the *pRequested* parameters are ignored. On the initial call, all may point to **NULL**, which sets up the query to return every entry in the BLOB, one per subsequent call.

Specifying an owner limits the strings returned to just that owner. A similar limitation is true for categories and tags, with the additional caveat that if a category is specified, an owner must also be specified and if a tag is specified, a category (and therefore an owner) must be specified.

When the initial call to **GetStringsFromBlob** returns, *pRestartKey* points to a new value, which should be specified on the next call to the function to get the next value.

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

[GetStringFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getstringfromblob)

