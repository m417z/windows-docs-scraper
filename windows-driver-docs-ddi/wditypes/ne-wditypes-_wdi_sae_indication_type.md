# WDI_SAE_INDICATION_TYPE enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The **WDI_SAE_INDICATION_TYPE** enumeration defines the type of information needed to continue SAE authentication with the BSSID, or notification that authentication cannot continue.

## Constants

### `WDI_SAE_INDICATION_TYPE_COMMIT_REQUEST_PARAMS_NEEDED`

The initial request for parameters to send a Commit request.

### `WDI_SAE_INDICATION_TYPE_COMMIT_RESPONSE`

Commit response received. The Commit response must be included in the indication.

### `WDI_SAE_INDICATION_TYPE_CONFIRM_RESPONSE`

Confirm response received. The Confirm response must be included in the indication.

### `WDI_SAE_INDICATION_TYPE_ERROR`

SAE authentication failed with this BSSID. The SAE status must be included in the indication.

### `WDI_SAE_INDICATION_TYPE_CONFIRM_REQUEST_RESEND_REQUEST`

Resending the Confirm request to the AP.

## Remarks

This enumeration is a value in the [NDIS_STATUS_WDI_INDICATION_SAE_AUTH_PARAMS_NEEDED](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wdi-indication-sae-auth-params-needed) indication.

## See also

[WPA3-SAE Authentication](https://learn.microsoft.com/windows-hardware/drivers/network/wpa3-sae-authentication)

[NDIS_STATUS_WDI_INDICATION_SAE_AUTH_PARAMS_NEEDED](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wdi-indication-sae-auth-params-needed)