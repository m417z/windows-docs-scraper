## Description

Defines constants that specify the kind(s) of objects to include in an enumeration operation.

For more info, and code examples, see [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords).

## Constants

### `FW_DYNAMIC_KEYWORD_ADDRESS_ENUM_FLAGS_AUTO_RESOLVE:0x0001`

Specifies that enumeration should include all objects that have the [FW_DYNAMIC_KEYWORD_ADDRESS_FLAGS_AUTO_RESOLVE](https://learn.microsoft.com/windows/win32/api/netfw/ne-netfw-fw_dynamic_keyword_address_flags) flag set.

### `FW_DYNAMIC_KEYWORD_ADDRESS_ENUM_FLAGS_NON_AUTO_RESOLVE:0x0002`

Specifies that enumeration should include all objects that have the [FW_DYNAMIC_KEYWORD_ADDRESS_FLAGS_AUTO_RESOLVE](https://learn.microsoft.com/windows/win32/api/netfw/ne-netfw-fw_dynamic_keyword_address_flags) flag *not* set.

### `FW_DYNAMIC_KEYWORD_ADDRESS_ENUM_FLAGS_ALL`

Specifies that enumeration should include *all* objects.

## Remarks

## See also

* [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords)