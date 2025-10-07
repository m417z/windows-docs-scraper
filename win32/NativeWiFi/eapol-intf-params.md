# EAPOL\_INTF\_PARAMS structure

\[**EAPOL\_INTF\_PARAMS** is no longer supported as of Windows Vista and Windows Server 2008. Instead, use the [Native Wifi API](https://learn.microsoft.com/windows/win32/nativewifi/native-wifi-reference), which provides similar functionality. For more information, see [About the Native Wifi API](https://learn.microsoft.com/windows/win32/nativewifi/about-the-native-wifi-api).\]

Contains EAPOL configuration parameters.

## Members

**dwVersion**

Version of the caller. Default is 0.

**dwReserved2**

Reserved for future use.

**dwEapFlags**

Not used.

**dwEapType**

The EAP extension type to be used. Set to 0x00000013 for EAP-TLS and 0x00000026 for PEAP.

**dwSizeOfSSID**

Size of network identifier.

**bSSID**

Network identifier.

## Remarks

The header file wzcsapi.h is not available in the Windows SDK.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| End of client support<br> | Windows XP with SP3<br> |
| End of server support<br> | Windows Server 2003<br> |
| Header<br> | Wzcsapi.h |

