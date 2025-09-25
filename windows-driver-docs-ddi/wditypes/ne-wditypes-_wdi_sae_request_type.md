# WDI_SAE_REQUEST_TYPE enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The **WDI_SAE_REQUEST_TYPE** enumeration defines the type of Simultaneous Authentication of Equals (SAE) request frame to send to the BSSID.

## Constants

### `WDI_SAE_REQUEST_TYPE_COMMIT_REQUEST:0`

Send a Commit request. SAECommitRequest will be included.

### `WDI_SAE_REQUEST_TYPE_CONFIRM_REQUEST:1`

Send a Confirm request. SAEConfirmRequest will be included.

### `WDI_SAE_REQUEST_TYPE_FAILURE:2`

Request SAE authentication parameters failed. SAEStatus will be included.

### `WDI_SAE_REQUEST_TYPE_SUCCESS:3`

Request SAE authentication parameters succeeded.

### `WDI_SAE_REQUEST_TYPE_COMMIT_REQUEST_H2E:4`

Send a Commit Request using H2E. When Anti-Clogging token is specified, it will be encoded as Anti-Clogging Element instead of a field.

## Remarks

This enumeration is a value in the [OID_WDI_SET_SAE_AUTH_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wdi-set-sae-auth-params) command.

## See also

[WPA3-SAE Authentication](https://learn.microsoft.com/windows-hardware/drivers/network/wpa3-sae-authentication)

[OID_WDI_SET_SAE_AUTH_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wdi-set-sae-auth-params)