## Description

Function pointer type of the entry point in the service that you call to add the specified dynamic keyword address.

> [!NOTE]
> A pointer type for this free function is published via `NetFw.h`, but a static-link library isn't published. Use the [LoadLibraryExW](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw)/[GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) pattern for calling this function.

When you call [GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress), pass a handle to the *firewallapi.dll* module, and pass *FWAddDynamicKeywordAddress0* as the *lpProcName* argument.

For more info, and code examples, see [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords).

## Parameters

### `dynamicKeywordAddress`

Type: **const [PFW_DYNAMIC_KEYWORD_ADDRESS0](https://learn.microsoft.com/windows/win32/api/netfw/ns-netfw-fw_dynamic_keyword_address0)**

A pointer to a constant (populated) dynamic keyword address object.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If the function succeeds (the object was successfully created and added), then it returns **ERROR_SUCCESS**. Otherwise, it returns one of the following values.

|Return value|Description|
|-|-|
|ERROR_ACCESS_DENIED|The caller doesn't have proper permissions to create this object.|
|ERROR_ALREADY_EXISTS|An object with the specified ID already exists on the system.|
|ERROR_INVALID_PARAMETER|Invalid [FW_DYNAMIC_KEYWORD_ADDRESS0](https://learn.microsoft.com/windows/win32/api/netfw/ns-netfw-fw_dynamic_keyword_address0). See [**Remarks**](https://learn.microsoft.com/windows/win32/api/netfw/nc-netfw-pfn_fwadddynamickeywordaddress0#remarks) for valid usage.|

## Remarks

* If the **FW_DYNAMIC_KEYWORD_ADDRESS_FLAGS_AUTO_RESOLVE** flag is set, then:
  * the *addresses* must be NULL, and
  * the *keyword* field should be a string that can be resolved; that is, a FQDN or hostname.
* If the **FW_DYNAMIC_KEYWORD_ADDRESS_FLAGS_AUTO_RESOLVE** flag is *not* set, then the *addresses* field must be a comma-separated list of IP address tokens. Tokens can be individual IP addresses, ranges, or subnets. Valid token formats include:
  * A valid IPv4 address (for example, 10.0.0.10)
  * A valid IPv6 address (for example, 2620:1ec:c11::200)
  * An IPv4 address range in the format \<start address\>-\<end address\>, with no spaces included (for example, 10.0.0.0-10.0.0.255)
  * An IPv6 address range in the format \<start address\>-\<end address\>, with no spaces included (for example, 2001:db8:abcd:12::-2001:db8:abcd:12:ffff:ffff:ffff:ffff)
  * A valid IPv4 subnet specified using the network prefix notation (for example, 10.0.0.0/24)
  * A valid IPv6 subnet specified using the prefix length notation (for example, 2001:db8:abcd:0012::0/64)
* A dynamic keyword address persists across reboots. For the *AutoResolved* objects, the addresses are *not* persisted across boot cycles, and must be re-evaluated during the following boot cycle.

## See also

* [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords)