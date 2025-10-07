# NDIS\_OBJECT\_HEADER structure

The **NDIS\_OBJECT\_HEADER** structure packages the object type, version, and size information that is required in many NDIS 6.0 structures.

## Members

**Type**

Specifies the type of NDIS object that a structure describes.

**Revision**

Specifies the revision number of this structure.

**Size**

Specifies the total size, in bytes, of the NDIS structure that contains the **NDIS\_OBJECT\_HEADER**. This size includes the size of the **NDIS\_OBJECT\_HEADER** member and all other members of the structure.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista, Windows XP with SP3 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Redistributable<br> | Wireless LAN API for Windows XP with SP2<br> |
| Header<br> | Ntddndis.h (include Windot11.h) |

## See also

[**DOT11\_BSSID\_LIST**](https://learn.microsoft.com/windows/win32/nativewifi/dot11-bssid-list)

