## Description

Holds the data returned to the client when the [**FWEnumDynamicKeywordAddressById0**](https://learn.microsoft.com/windows/win32/api/netfw/nc-netfw-pfn_fwenumdynamickeywordaddressbyid0) or [**FWEnumDynamicKeywordAddressesByType0**](https://learn.microsoft.com/windows/win32/api/netfw/nc-netfw-pfn_fwenumdynamickeywordaddressesbytype0) APIs are called. This structure holds the dynamic keyword address object, as well as additional metadata.

For more info, and code examples, see [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords).

## Members

### `dynamicKeywordAddress`

Type: **[FW_DYNAMIC_KEYWORD_ADDRESS0](https://learn.microsoft.com/windows/win32/api/netfw/ns-netfw-fw_dynamic_keyword_address0)**

A dynamic keyword address (the dynamic keyword address object).

### `next`

Type: **[FW_DYNAMIC_KEYWORD_ADDRESS0](https://learn.microsoft.com/windows/win32/api/netfw/ns-netfw-fw_dynamic_keyword_address0)\***

A pointer to the next dynamic keyword address object in a linked list.

### `schemaVersion`

Type: **[WORD](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

The schema version of the object. This is used by the [**FWFreeDynamicKeywordAddressData0**](https://learn.microsoft.com/windows/win32/api/netfw/nc-netfw-pfn_fwfreedynamickeywordaddressdata0) API.

### `originType`

Type: **[FW_DYNAMIC_KEYWORD_ORIGIN_TYPE](https://learn.microsoft.com/windows/win32/api/netfw/ne-netfw-fw_dynamic_keyword_origin_type)**

Indicates the origin of this object. It can be either **FW_DYNAMIC_KEYWORD_ORIGIN_LOCAL**, which represents a locally created object, or **FW_DYNAMIC_KEYWORD_ORIGIN_MDM**, which represents an MDM managed object.

## Remarks

## See also

* [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords)
* [FWEnumDynamicKeywordAddressById0](https://learn.microsoft.com/windows/win32/api/netfw/nc-netfw-pfn_fwenumdynamickeywordaddressbyid0)
* [FWEnumDynamicKeywordAddressesByType0](https://learn.microsoft.com/windows/win32/api/netfw/nc-netfw-pfn_fwenumdynamickeywordaddressesbytype0)
* [FWFreeDynamicKeywordAddressData0](https://learn.microsoft.com/windows/win32/api/netfw/nc-netfw-pfn_fwfreedynamickeywordaddressdata0)