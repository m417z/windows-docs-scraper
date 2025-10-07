# GetNPPAddressFilterFromBlob function

The **GetNPPAddressFilterFromBlob** function fills in the given address filter with information stored in the BLOB.

## Parameters

*hBlob* \[in\]

Handle to a BLOB.

*pAddressTable* \[in, out\]

Pointer to the user-allocated address table.

*hErrorBlob* \[out\]

Handle to an error BLOB that specifies where in the original BLOB the error (if any) occurred.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is a NMERR value that describes the error.

## Remarks

The address information is stored in the **Config** section of the BLOB NPP **Owner** category.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Npptools.lib |
| DLL<br> | Npptools.dll |

## See also

[SetNPPAddressFilterInBlob](https://learn.microsoft.com/windows/win32/netmon2/setnppaddressfilterinblob)

[GetBoolFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getboolfromblob)

[GetClassIDFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getclassidfromblob)

[GetDwordFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getdwordfromblob)

[GetMacAddressFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getmacaddressfromblob)

[GetNetworkInfoFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getnetworkinfofromblob)

[GetNPPPatternFilterFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getnpppatternfilterfromblob)

[GetNPPTriggerFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getnpptriggerfromblob)

[GetStringFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getstringfromblob)

[GetStringsFromBlob](https://learn.microsoft.com/windows/win32/netmon2/getstringsfromblob)

