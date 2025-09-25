# _DOT11_EAP_RESULT structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_EAP_RESULT structure indicates results from an EAP method.

## Members

### `dwFailureReasonCode`

The reason code returned by the EAP method. The meaning of the code is specific to the EAP
method.

### `pAttribArray`

A pointer to an EAP_ATTRIBUTES array structure that contains the EAP attributes returned by the
authentication session. For more information about EAP_ATTRIBUTES, see the Microsoft Windows SDK
documentation.

## Syntax

```cpp
typedef struct _DOT11_EAP_RESULT {
  UINT32         dwFailureReasonCode;
  EAP_ATTRIBUTES *pAttribArray;
} DOT11_EAP_RESULT, *PDOT11_EAP_RESULT;
```