## Description

Function pointer type of the entry point in the service that you call to free dynamic keyword address data structs allocated by the service.

> [!NOTE]
> A pointer type for this free function is published via `NetFw.h`, but a static-link library isn't published. Use the [LoadLibraryExW](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw)/[GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) pattern for calling this function.

When you call [GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress), pass a handle to the *firewallapi.dll* module, and pass *FWFreeDynamicKeywordAddressData0* as the *lpProcName* argument.

For more info, and code examples, see [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords).

## Parameters

### `dynamicKeywordAddressData`

Type: \_In\_ **[PFW_DYNAMIC_KEYWORD_ADDRESS0](https://learn.microsoft.com/windows/win32/api/netfw/ns-netfw-fw_dynamic_keyword_address0)**

A pointer to either a single dynamic keyword address data object to be freed, or the head of a list of dynamic keyword address data object to be freed.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If the function succeeds, then it returns **ERROR_SUCCESS**.

## Remarks

You should call this function only on values returned by [FWEnumDynamicKeywordAddressById0](https://learn.microsoft.com/windows/win32/api/netfw/nc-netfw-pfn_fwenumdynamickeywordaddressbyid0) or [FWEnumDynamicKeywordAddressesByType0](https://learn.microsoft.com/windows/win32/api/netfw/nc-netfw-pfn_fwenumdynamickeywordaddressesbytype0).

## See also

* [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords)