# INTF\_ENTRY structure

\[**INTF\_ENTRY** is no longer supported as of Windows Vista and Windows Server 2008. Instead, use the [Native Wifi API](https://learn.microsoft.com/windows/win32/nativewifi/native-wifi-reference), which provides similar functionality. For more information, see [About the Native Wifi API](https://learn.microsoft.com/windows/win32/nativewifi/about-the-native-wifi-api).\]

Contains detailed information about an interface that is required by an RPC client.

## Members

**wszGuid**

A pointer to the interface GUID represented as a Unicode string in the following format: "{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}".

**wszDescr**

A pointer to a string that contains the interface description that is retrieved by the Wireless Zero Configuration service (WZCSVC).

**dwContext**

Reserved for internal use.

**ulMediaState**

The current NDIS media connect state for the interface. The following table shows the possible values.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------|
|

**MEDIA\_STATE\_CONNECTED**

1

| The media is connected.<br> |
|

**MEDIA\_STATE\_DISCONNECTED**

0

| The media is disconnected.<br> |
|

**MEDIA\_STATE\_UNKNOWN**

-1

| The media state is unknown.<br> |

**ulMediaType**

The NDIS media types that the NIC currently uses. When queried, the value of this member is **NdisMedium802\_3** as defined in the *Ndispnp.h* header file.

**ulPhysicalMediaType**

The NDIS media type for the interface. When queried, the value of this member is **NdisPhysicalMediumWirelessLan** as defined in the *Ndispnp.h* header file.

**nInfraMode**

The current 802.11 Infrastructure Mode set on the interface.

**nAuthMode**

The current 802.11 Authentication Mode set on the interface.

The following table shows the possible values for the parameter based on the **NDIS\_802\_11\_AUTHENTICATION\_MODE** enumeration defined in the *NtDDNdis.h* header file.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**Ndis802\_11AuthModeOpen**

1

| IEEE 802.11 Open System authentication.<br> |
|

**Ndis802\_11AuthModeShared**

2

| IEEE 802.11 shared authentication that uses a pre-shared wired equivalent privacy (WEP) key. <br> |
|

**Ndis802\_11AuthModeAutoSwitch**

3

| Auto-switch mode. When using auto-switch mode, the wireless network interface card (NIC) tries shared authentication mode first. If shared mode fails, the NIC attempts to use open authentication mode. <br> |
|

**Ndis802\_11AuthModeWPA**

4

| Wireless Protected Access(WPA) security. Authentication is performed between the supplicant, authenticator, and authentication server over IEEE 802.1X. Encryption keys are dynamic and are derived through the authentication process. <br> |
|

**Ndis802\_11AuthModeWPAPSK**

5

| WPA security using a pre-shared key. Authentication is performed between the supplicant and authenticator over IEEE 802.1X. Encryption keys are dynamic and are derived through the preshared key used by the supplicant and authenticator. <br> |
|

**Ndis802\_11AuthModeWPANone**

6

| WPA security. Authentication is performed using a preshared key without IEEE 802.1X authentication. Encryption keys are static and are derived through the preshared key. This mode is applicable only to ad hoc network types. <br> |
|

**Ndis802\_11AuthModeWPA2**

7

| WPA2 security. Authentication is performed between the supplicant, authenticator, and authentication server over IEEE 802.1X. Encryption keys are dynamic and are derived through the authentication process. <br> |
|

**Ndis802\_11AuthModeWPA2PSK**

8

| Specifies WPA2 security. Authentication is performed between the supplicant and authenticator over IEEE 802 1X. Encryption keys are dynamic and are derived through the preshared key used by the supplicant and authenticator. <br> |
|

**Ndis802\_11AuthModeMax**

9

| The maximum possible value for the **NDIS\_802\_11\_AUTHENTICATION\_MODE** enumeration value. This is not a legal value for the authentication mode. <br> |

**nWepStatus**

The current 802.11 Encryption Mode set on the interface.

**dwCtlFlags**

A bitmask value of control flags that indicate how WZCSVC is operating on the interface.

The following table shows the possible bit values.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**INTFCTL\_CM\_MASK**

0x0007

| A bitmask for the network filter mode. INTFCTL\_CM\_MASK & dwCtlFlags result in a value of the type NDIS\_802\_11\_NETWORK\_INFRASTRUCTURE. The resulting value indicates whether WZCSVC connects only to infrastructure networks, adhoc networks, or to both types of networks.<br> |
|

**INTFCTL\_ENABLED**

0x8000

| Indicates whether WZCSVC should configure the interface.<br> |
|

**INTFCTL\_FALLBACK**

0x4000

| If a preferred network is not available, this value indicates whether WZCSVC should automatically configure the NIC to associate to any available network.<br> |
|

**INTFCTL\_OIDSSUPP**

0x2000

| Indicates whether the NIC driver supports all the 802.11 OIDs required by WZCSVC to function.<br> |
|

**INTFCTL\_VOLATILE**

0x1000

| Indicates whether the service parameters for this interface should be retained in the registry. <br> If this value is set, then these parameters are volatile and should not be retained in the registry.<br> |
|

**INTFCTL\_POLICY**

0x0800

| Indicates whether the service parameters for this interface are pushed by a group policy.<br> If this value is set, then the service parameters are pushed to the local computer by group policy.<br> |
|

**INTFCTL\_8021XSUPP**

0x1000

| Indicates whether 802.1X support is enabled.<br> |

**dwDynFlags**

A bitmask of dynamic flags that control the dynamic (non-persistent and non-static) behavior on the interface.

These bits are useful to trigger dynamic, temporary changes in the way the WZCSVC acts on the interface. None of these bits are persisted in the registry, so the settings won't survive a system restart or a device disable and enable sequence.

The following table shows the possible bit values.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------|
|

**INTFDYN\_NOSCAN**

0x00000001

| Indicates that the WZCSVC should not request the interface conduct an active scan, but instead use the cached values in the NIC driver.<br> |

**dwCapabilities**

Specifies the driver capabilities.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**INTFCAP\_MAX\_CIPHER\_MASK**

0x000000ff

| The lower order bits of this member are used to indicate the maximum encryption that is supported. The possible values are some of the enumeration values defined in the **NDIS\_802\_11\_WEP\_STATUS** structure in the *NtDDNdis.h* header file included in the Windows SDK.<br> The Ndis802\_11Encryption1Enabled value (2) indicates that WEP is supported. TKIP and AES are not supported, and a transmit key may or may not be available. <br> The Ndis802\_11Encryption2Enabled value (9) indicates that TKIP and WEP are supported. AES is not supported, and a transmit key is available. <br> The Ndis802\_11Encryption3Enabled value (11) indicates that AES, TKIP, and WEP are supported, and a transmit key is available. <br> The Ndis802\_11EncryptionNotSupported (8) indicates Indicates that the WEP key is not supported. <br> |
|

**INTFCAP\_SSN**

0x00000100

| Indicates support for Simple Secure Network (SSN) which is a subset of 802.11i. <br> SSN changes the encryption key periodically, as opposed to the WEP (Wired Equivalent Privacy) standard, which uses a static key. In order for SSN to work, the maximum supported cipher should be at least TKIP. SSN was developed by a consortium of vendors in 2002 as an interim approach to improve wireless LAN security while the IEEE 802.11i standard was being completed.<br> |
|

**INTFCAP\_80211I**

0x00000200

| Indicates support for the IEEE 802.11i standard.<br> |

**rdNicCapabilities**

A set of capabilities for 802.11i.

The [**WZCQueryInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcqueryinterface) function returns **rdNicCapabilities** data when called with the **INTF\_CAPABILITIES** flag passed in the *dwInflags* parameter. If the function call is successful, the **pData** member of the **RAW\_DATA** structure contains an **INTF\_80211\_CAPABILITY** structure.

**rdSSID**

Binary data containing the 802.11 SSID currently configured on the interface.

The [**WZCQueryInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcqueryinterface) function returns **rdSSID** data when called with the **INTF\_SSID** flag passed in the *dwInflags* parameter. If the function call is successful, the **dwDataLen** member of the **RAW\_DATA** structure contains the **SsidLength** member of a **NDIS\_802\_11\_SSID** structure and the **pData** member of the **RAW\_DATA** structure contains the **Ssid** member of a **NDIS\_802\_11\_SSID** structure.

The **NDIS\_802\_11\_SSID** structure is defined in the *Ntddndis.h* header file.

**rdBSSID**

Binary data containing the 802.11 BSSID configured on the interface.

The [**WZCQueryInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcqueryinterface) function returns **rdBSSID** data when called with the **INTF\_BSSID** flag passed in the *dwInflags* parameter. If the function call is successful, the **dwDataLen** member of the **RAW\_DATA** structure contains the size of an **NDIS\_802\_11\_MAC\_ADDRESS** structure and the **pData** member of the **RAW\_DATA** structure contains the **NDIS\_802\_11\_MAC\_ADDRESS** structure.

The **NDIS\_802\_11\_MAC\_ADDRESS** structure is defined in the *Ntddndis.h* header file.

**rdBSSIDList**

Binary data that contains the list of BSSIDs that was last retrieved by WZCSVC.

The [**WZCQueryInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcqueryinterface) function returns **rdBSSIDList** data when called with the **INTF\_BSSIDLIST** flag passed in the *dwInflags* parameter. If the function call is successful, the **dwDataLen** member of the **RAW\_DATA** structure contains the length of the buffer with the returned data and the **pData** member of the **RAW\_DATA** structure contains the **WZC\_802\_11\_CONFIG\_LIST** structure.

**rdStSSIDList**

Binary data that contains the list of preferred networks configured for this interface.

The [**WZCQueryInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcqueryinterface) function returns **rdStSSIDList** data when called with the **INTF\_PREFLIST** flag passed in the *dwInflags* parameter. If the function call is successful, the **dwDataLen** member of the **RAW\_DATA** structure contains the length of the buffer with the returned data and the **pData** member of the **RAW\_DATA** structure contains the **WZC\_802\_11\_CONFIG\_LIST** structure.

If one of the preferred networks is currently connected, the **dwCtlFlags** member of the **WZC\_WLAN\_CONFIG** structure for the network will have the **WZCCTL\_MEDIA\_CONNECTED** (0x0400) bit set.

**rdCtrlData**

Binary data used with other control flags, when setting additional parameters on the interface.

## Remarks

The **INTF\_ENTRY** structure is used by the [**WZCQueryInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcqueryinterface) and [**WZCRefreshInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcrefreshinterface) functions.

The **RAW\_DATA** structure is defined as follows:

```C++
typedef struct
{
    DWORD   dwDataLen;
    LPBYTE  pData;
} RAW_DATA, *PRAW_DATA;
```

The *pData* member points to binary data. The *dwDataLen* indicates the number of bytes pointed by *pData*.

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

[**WZCEnumInterfaces**](https://learn.microsoft.com/windows/win32/nativewifi/wzcenuminterfaces)

[**WZCQueryInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcqueryinterface)

[**WZCRefreshInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcrefreshinterface)

