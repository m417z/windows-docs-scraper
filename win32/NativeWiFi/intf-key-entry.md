# INTF\_KEY\_ENTRY structure

\[**INTF\_KEY\_ENTRY** is no longer supported as of Windows Vista and Windows Server 2008. Instead, use the [Native Wifi API](https://learn.microsoft.com/windows/win32/nativewifi/native-wifi-reference), which provides similar functionality. For more information, see [About the Native Wifi API](https://learn.microsoft.com/windows/win32/nativewifi/about-the-native-wifi-api).\]

The **INTF\_KEY\_ENTRY** structure stores the key information about a wireless LAN interface managed by the Wireless Configuration Service.

## Members

**wszGuid**

A pointer to the interface GUID represented as a Unicode string in the following format: "{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}".

## Remarks

> [!Note]
> The *Wzcsapi.h* header file is not available in the Windows SDK.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| End of client support<br> | Windows XP with SP3<br> |
| End of server support<br> | Windows Server 2003<br> |
| Header<br> | Wzcsapi.h |

## See also

[**INTFS\_KEY\_TABLE**](https://learn.microsoft.com/windows/win32/nativewifi/intfs-key-table)

[**WZCEnumInterfaces**](https://learn.microsoft.com/windows/win32/nativewifi/wzcenuminterfaces)

