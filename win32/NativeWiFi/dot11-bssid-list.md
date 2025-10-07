# DOT11\_BSSID\_LIST structure

The **DOT11\_BSSID\_LIST** structure contains a list of basic service set (BSS) identifiers.

## Members

**Header**

An [**NDIS\_OBJECT\_HEADER**](https://learn.microsoft.com/windows/win32/nativewifi/ndis-object-header) structure that contains the type, version, and, size information of an NDIS structure. For most **DOT11\_BSSID\_LIST** structures, set the **Type** member to **NDIS\_OBJECT\_TYPE\_DEFAULT**, set the **Revision** member to **DOT11\_BSSID\_LIST\_REVISION\_1**, and set the **Size** member to **sizeof(DOT11\_BSSID\_LIST)**.

**uNumOfEntries**

The number of entries in this structure.

**uTotalNumOfEntries**

The total number of entries supported.

**BSSIDs**

A list of BSS identifiers. A BSS identifier is stored as a [**DOT11\_MAC\_ADDRESS**](https://learn.microsoft.com/windows/win32/nativewifi/dot11-mac-address-type) type.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista, Windows XP with SP3 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Redistributable<br> | Wireless LAN API for Windows XP with SP2<br> |
| Header<br> | Windot11.h (include Windot11.h) |

## See also

[**WLAN\_CONNECTION\_PARAMETERS**](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_parameters)

