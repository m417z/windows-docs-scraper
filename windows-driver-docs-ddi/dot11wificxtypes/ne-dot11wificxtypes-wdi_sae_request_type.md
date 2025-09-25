## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_SAE_REQUEST_TYPE** enumeration defines the type of Simultaneous Authentication of Equals (SAE) request frame to send to the BSSID.

## Constants

### `WDI_SAE_REQUEST_TYPE_COMMIT_PARAMS:0`

Send a Commit request. SAECommitRequest will be included.

### `WDI_SAE_REQUEST_TYPE_CONFIRM_PARAMS:1`

Send a Confirm request. SAEConfirmRequest will be included.

### `WDI_SAE_REQUEST_TYPE_FAILURE:2`

Request SAE authentication parameters failed. SAEStatus will be included.

### `WDI_SAE_REQUEST_TYPE_SUCCESS:3`

Request SAE authentication parameters succeeded.

### `WDI_SAE_REQUEST_TYPE_COMMIT_H2E_PARAMS:4`

Send a Commit Request using H2E. When Anti-Clogging token is specified, it will be encoded as Anti-Clogging Element instead of a field.

## Remarks

This enumeration is a value in the [OID_WDI_SET_SAE_AUTH_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/netcx/oid-wdi-set-sae-auth-params) command.

## See also

[WPA3-SAE Authentication](https://learn.microsoft.com/windows-hardware/drivers/netcx/wificx-wpa3-sae-authentication)

[OID_WDI_SET_SAE_AUTH_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wdi-set-sae-auth-params)