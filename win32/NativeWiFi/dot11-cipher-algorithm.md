# DOT11\_CIPHER\_ALGORITHM enumeration

The **DOT11\_CIPHER\_ALGORITHM** enumerated type defines a cipher algorithm for data encryption and decryption.

## Constants

**DOT11\_CIPHER\_ALGO\_NONE**

Specifies that no cipher algorithm is enabled or supported.

**DOT11\_CIPHER\_ALGO\_WEP40**

Specifies a Wired Equivalent Privacy (WEP) algorithm, which is the RC4-based algorithm that is specified in the 802.11-1999 standard. This enumerator specifies the WEP cipher algorithm with a 40-bit cipher key.

**DOT11\_CIPHER\_ALGO\_TKIP**

Specifies a Temporal Key Integrity Protocol (TKIP) algorithm, which is the RC4-based cipher suite that is based on the algorithms that are defined in the WPA specification and IEEE 802.11i-2004 standard. This cipher also uses the Michael Message Integrity Code (MIC) algorithm for forgery protection.

**DOT11\_CIPHER\_ALGO\_CCMP**

Specifies an AES-CCMP algorithm, as specified in the IEEE 802.11i-2004 standard and RFC 3610. Advanced Encryption Standard (AES) is the encryption algorithm defined in FIPS PUB 197.

**DOT11\_CIPHER\_ALGO\_WEP104**

Specifies a WEP cipher algorithm with a 104-bit cipher key.

**DOT11\_CIPHER\_ALGO\_WPA\_USE\_GROUP**

Specifies a Wi-Fi Protected Access (WPA) Use Group Key cipher suite. For more information about the Use Group Key cipher suite, refer to Clause 7.3.2.25.1 of the IEEE 802.11i-2004 standard.

**DOT11\_CIPHER\_ALGO\_RSN\_USE\_GROUP**

Specifies a Robust Security Network (RSN) Use Group Key cipher suite. For more information about the Use Group Key cipher suite, refer to Clause 7.3.2.25.1 of the IEEE 802.11i-2004 standard.

**DOT11\_CIPHER\_ALGO\_WEP**

Specifies a WEP cipher algorithm with a cipher key of any length.

**DOT11\_CIPHER\_ALGO\_IHV\_START**

Specifies the start of the range that is used to define proprietary cipher algorithms that are developed by an independent hardware vendor (IHV).

**DOT11\_CIPHER\_ALGO\_IHV\_END**

Specifies the end of the range that is used to define proprietary cipher algorithms that are developed by an IHV.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista, Windows XP with SP3 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Redistributable<br> | Wireless LAN API for Windows XP with SP2<br> |
| Header<br> | Wlantypes.h (include Windot11.h) |

## See also

[**DOT11\_AUTH\_CIPHER\_PAIR**](https://learn.microsoft.com/windows/win32/nativewifi/dot11-auth-cipher-pair)

[**WLAN\_AVAILABLE\_NETWORK**](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_available_network)

[**WLAN\_SECURITY\_ATTRIBUTES**](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_security_attributes)

