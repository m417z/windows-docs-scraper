# DOT11\_AUTH\_CIPHER\_PAIR structure

The **DOT11\_AUTH\_CIPHER\_PAIR** structure defines a pair of 802.11 authentication and cipher algorithms that can be enabled at the same time on the 802.11 station.

## Members

**AuthAlgoId**

An authentication algorithm that uses a [**DOT11\_AUTH\_ALGORITHM**](https://learn.microsoft.com/windows/win32/nativewifi/dot11-auth-algorithm) enumerated type.

**CipherAlgoId**

A cipher algorithm that uses a [**DOT11\_CIPHER\_ALGORITHM**](https://learn.microsoft.com/windows/win32/nativewifi/dot11-cipher-algorithm) enumerated type.

## Remarks

The DOT11\_AUTH\_CIPHER\_PAIR structure defines an authentication and cipher algorithm that can be enabled together for basic service set (BSS) network connections.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista, Windows XP with SP3 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Redistributable<br> | Wireless LAN API for Windows XP with SP2<br> |
| Header<br> | Wlantypes.h (include Windot11.h) |

## See also

[**DOT11\_AUTH\_ALGORITHM**](https://learn.microsoft.com/windows/win32/nativewifi/dot11-auth-algorithm)

[**DOT11\_CIPHER\_ALGORITHM**](https://learn.microsoft.com/windows/win32/nativewifi/dot11-cipher-algorithm)

