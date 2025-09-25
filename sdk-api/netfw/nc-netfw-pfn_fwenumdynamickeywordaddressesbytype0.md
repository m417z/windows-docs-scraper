## Description

Function pointer type of the entry point in the service that you call to enumerate dynamic keyword addresses by type. You can request a particular subset of objects based on the enumeration flags passed in.

> [!NOTE]
> A pointer type for this free function is published via `NetFw.h`, but a static-link library isn't published. Use the [LoadLibraryExW](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw)/[GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) pattern for calling this function.

When you call [GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress), pass a handle to the *firewallapi.dll* module, and pass *FWEnumDynamicKeywordAddressesByType0* as the *lpProcName* argument.

For more info, and code examples, see [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords).

## Parameters

### `flags`

Type: **[DWORD](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

Using the value [FW_DYNAMIC_KEYWORD_ADDRESS_ENUM_FLAGS_AUTO_RESOLVE](https://learn.microsoft.com/windows/win32/api/netfw/ne-netfw-fw_dynamic_keyword_address_enum_flags) will enumerate all objects that have the [FW_DYNAMIC_KEYWORD_ADDRESS_FLAGS_AUTO_RESOLVE](https://learn.microsoft.com/windows/win32/api/netfw/ne-netfw-fw_dynamic_keyword_address_flags) flag set.

Using the value [FW_DYNAMIC_KEYWORD_ADDRESS_ENUM_FLAGS_NON_AUTO_RESOLVE](https://learn.microsoft.com/windows/win32/api/netfw/ne-netfw-fw_dynamic_keyword_address_enum_flags) will enumerate all objects that have the [FW_DYNAMIC_KEYWORD_ADDRESS_FLAGS_AUTO_RESOLVE](https://learn.microsoft.com/windows/win32/api/netfw/ne-netfw-fw_dynamic_keyword_address_flags) flag *not* set.

Using the value [FW_DYNAMIC_KEYWORD_ADDRESS_ENUM_FLAGS_NON_AUTO_RESOLVE](https://learn.microsoft.com/windows/win32/api/netfw/ne-netfw-fw_dynamic_keyword_address_enum_flags) will enumerate *all* objects.

### `dynamicKeywordAddressData`

Type: \_Out\_ **[PFW_DYNAMIC_KEYWORD_ADDRESS0](https://learn.microsoft.com/windows/win32/api/netfw/ns-netfw-fw_dynamic_keyword_address0)\***

The address of a pointer to a dynamic keyword address object, which will hold a linked list of objects returned. You must free this address by calling [FWFreeDynamicKeywordAddressData0](https://learn.microsoft.com/windows/win32/api/netfw/nc-netfw-pfn_fwfreedynamickeywordaddressdata0).

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If the function succeeds, then it returns **ERROR_SUCCESS**. Otherwise, it returns one of the following values.

|Return value|Description|
|-|-|
|ERROR_INVALID_PARAMETER|A zero value was passed in for the *flags* parameter.|

## Remarks

You must free the address of the first returned object in the list (the head of the list) by calling [FWFreeDynamicKeywordAddressData0](https://learn.microsoft.com/windows/win32/api/netfw/nc-netfw-pfn_fwfreedynamickeywordaddressdata0).

## See also

* [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords)