# INTFS\_KEY\_TABLE structure

\[**INTFS\_KEY\_TABLE** is no longer supported as of Windows Vista and Windows Server 2008. Instead, use the [Native Wifi API](https://learn.microsoft.com/windows/win32/nativewifi/native-wifi-reference), which provides similar functionality. For more information, see [About the Native Wifi API](https://learn.microsoft.com/windows/win32/nativewifi/about-the-native-wifi-api).\]

The **INTFS\_KEY\_TABLE** structure contains the table of key information for all wireless LAN interfaces managed by the Wireless Configuration Service.

## Members

**dwNumIntfs**

Total number of interfaces.

**pIntfs**

Pointer to the [**INTF\_KEY\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-key-entry) structure.

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

