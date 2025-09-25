## Description

Function pointer type of the entry point in the service that you call to enumerate the specific dynamic keyword addresses by ID.

> [!NOTE]
> A pointer type for this free function is published via `NetFw.h`, but a static-link library isn't published. Use the [LoadLibraryExW](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw)/[GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) pattern for calling this function.

When you call [GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress), pass a handle to the *firewallapi.dll* module, and pass *FWEnumDynamicKeywordAddressById0* as the *lpProcName* argument.

For more info, and code examples, see [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords).

## Parameters

### `dynamicKeywordAddressId`

Type: **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

The id of the dynamic keyword address object to enumerate.

### `dynamicKeywordAddressData`

Type: \_Out\_ **[PFW_DYNAMIC_KEYWORD_ADDRESS0](https://learn.microsoft.com/windows/win32/api/netfw/ns-netfw-fw_dynamic_keyword_address0)\***

The address of a pointer to a dynamic keyword address object, which will hold the object returned. You must free this object by calling [FWFreeDynamicKeywordAddressData0](https://learn.microsoft.com/windows/win32/api/netfw/nc-netfw-pfn_fwfreedynamickeywordaddressdata0).

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If the function succeeds, then it returns **ERROR_SUCCESS**.

## Remarks

If the object returned via *dynamicKeywordAddressData* is non-NULL, then its *pNext* field is always null.

You must free the returned addresses object by calling [FWFreeDynamicKeywordAddressData0](https://learn.microsoft.com/windows/win32/api/netfw/nc-netfw-pfn_fwfreedynamickeywordaddressdata0).

## See also

* [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords)