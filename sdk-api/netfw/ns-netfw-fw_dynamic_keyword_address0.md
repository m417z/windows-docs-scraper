## Description

Allows the client to create a dynamic keyword address, which holds a list of IP addresses. This object can also be marked as *AutoResolve*, which indicates that the IP addresses are not populated upon creation, but instead populated by a component outside of the firewall service.

For more info, and code examples, see [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords).

## Members

### `id`

Type: **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

A unique **GUID** identifier for this object. It must be a non-empty **GUID**.

### `keyword`

Type: **[PCWSTR](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

Either a string (for management convenience), or a resolvable string (that is, a FQDN or hostname) when the **FW_DYNAMIC_KEYWORD_ADDRESS_FLAGS_AUTO_RESOLVE** flag is set.

### `flags`

Type: **[DWORD](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

Set to the value [**FW_DYNAMIC_KEYWORD_ADDRESS_FLAGS_AUTO_RESOLVE**](https://learn.microsoft.com/windows/win32/api/netfw/ne-netfw-fw_dynamic_keyword_address_flags) to indicate that the *keyword* field will be resolved, and that the *addresses* field will be populated by another component outside the firewall service.

### `addresses`

Type: **[PCWSTR](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

The list of IP addresses for this keyword. If the **FW_DYNAMIC_KEYWORD_ADDRESS_FLAGS_AUTO_RESOLVE** flag is set, then this indicates that the *addresses* field was populated outside the firewall service.

## Remarks

## See also

* [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords)