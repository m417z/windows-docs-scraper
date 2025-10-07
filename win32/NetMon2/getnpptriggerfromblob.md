# GetNPPTriggerFromBlob function

The **GetNPPTriggerFromBlob** function retrieves the trigger from the given BLOB.

## Parameters

*hBlob* \[in\]

Handle to the BLOB.

*pTrigger* \[out\]

Pointer to the trigger value.

*hErrorBlob* \[out\]

Handle to an error BLOB that specifies where in the original BLOB the error (if any) occurred.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is a NMERR value that indicates the error.

## Remarks

The trigger information is stored in the **Trigger** category of the BLOB.

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

[GetClassIDFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getclassidfromblob)

[GetDwordFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getdwordfromblob)

[GetMacAddressFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getmacaddressfromblob)

[GetNetworkInfoFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getnetworkinfofromblob)

[GetNPPAddressFilterFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getnppaddressfilterfromblob)

[GetNPPPatternFilterFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getnpppatternfilterfromblob)

[GetStringFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getstringfromblob)

[GetStringsFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getstringsfromblob)

