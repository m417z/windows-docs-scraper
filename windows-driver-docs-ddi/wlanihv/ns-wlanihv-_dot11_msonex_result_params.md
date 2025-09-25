# _DOT11_MSONEX_RESULT_PARAMS structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_MSONEX_RESULT_PARAMS structure is used to exchange result parameters with an IHV module.

## Members

### `Dot11OnexAuthStatus`

A
[ONEX_AUTH_STATUS](https://learn.microsoft.com/windows/win32/api/dot1x/ne-dot1x-onex_auth_status) type that specifies the
authorization status of the 802.1X exchange.

### `Dot11OneXReasonCode`

A
[ONEX_REASON_CODE](https://learn.microsoft.com/windows/win32/api/dot1x/ne-dot1x-onex_reason_code) type that specifies the
reason code of the 802.1X exchange.

### `pbMPPESendKey`

A pointer to a Microsoft Point-to-Point Encryption (MPPE) Send-Key. This key is encrypted and
should be decrypted by calling the
**CryptUnprotectData** function that is documented in the Windows SDK.

### `dwMPPESendKeyLen`

The size, in bytes, of the MPPE Send-Key.

### `pbMPPERecvKey`

A pointer to a Microsoft Point-to-Point Encryption (MPPE) Receive-Key. This key is encrypted and
should be decrypted by calling the
**CryptUnprotectData** function that is documented in the Windows SDK.

### `dwMPPERecvKeyLen`

The size, in bytes, of the MPPE Receive-Key.

### `pDot11EapResult`

A pointer to a
[DOT11_EAP_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11_eap_result) structure that contains
results from an EAP method.

## Syntax

```cpp
typedef struct _DOT11_MSONEX_RESULT_PARAMS {
  ONEX_AUTH_STATUS  Dot11OnexAuthStatus;
  ONEX_REASON_CODE  Dot11OneXReasonCode;
  PBYTE             pbMPPESendKey;
  DWORD             dwMPPESendKeyLen;
  PBYTE             pbMPPERecvKey;
  DWORD             dwMPPERecvKeyLen;
  PDOT11_EAP_RESULT pDot11EapResult;
} DOT11_MSONEX_RESULT_PARAMS, *PDOT11_MSONEX_RESULT_PARAMS;
```

## See also

[ONEX_REASON_CODE](https://learn.microsoft.com/windows/win32/api/dot1x/ne-dot1x-onex_reason_code)

[DOT11_EAP_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11_eap_result)

[ONEX_AUTH_STATUS](https://learn.microsoft.com/windows/win32/api/dot1x/ne-dot1x-onex_auth_status)