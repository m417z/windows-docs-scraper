## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_SAE_STATUS** enumeration defines SAE authentication failure error status codes. This enumeration is used to provide failure codes from the OS to the WiFiCx driver, or from the driver to the OS.

## Constants

### `WDI_SAE_STATUS_SUCCESS:0`

The operation completed successfully.

### `WDI_SAE_STATUS_FAILURE:1`

The operation completed with failure and none of the other status codes apply.

### `WDI_SAE_STATUS_RESOURCES:2`

The driver encountered a resource allocation error.

### `WDI_SAE_STATUS_INTERNAL_AUTH_FAILURE:3`

WDI encountered an internal authentication-related failure.

### `WDI_SAE_STATUS_INVALID_PEER:4`

The Commit or Confirm response was received from an AP for which WDI did not provide SAE parameters.

### `WDI_SAE_STATUS_INITIALIZATION_NO_KEY:5`

WDI doesn't have the password for this association request.

### `WDI_SAE_STATUS_INITIALIZATION_H2E_NOT_SUPPORTED:6`

AP requires Hash-To-Element support but the driver doesn't support Hash-To-Element.

### `WDI_SAE_STATUS_INITIALIZATION_PWD_ID_NOT_SUPPORTED:7`

AP requires Password-Identifier, but no Password-Identifier is available.

### `WDI_SAE_STATUS_COMMIT_MESSAGE_RECEIVED_IN_NOTHING_STATE:10`

Commit message was received in Nothing state.

### `WDI_SAE_STATUS_COMMIT_MESSAGE_MALFORMED_AUTH_FRAME:11`

A bad Commit frame was received.

### `WDI_SAE_STATUS_COMMIT_MESSAGE_FAILURE_FROM_PEER:12`

The commit frame from the peer contained an error code.

### `WDI_SAE_STATUS_COMMIT_MESSAGE_FINITE_GROUP_NOT_PRESENT:13`

The Finite Group was not present in the Commit frame.

### `WDI_SAE_STATUS_COMMIT_MESSAGE_UNSUPPORTED_FINITE_GROUP:14`

The Finite Group specified in the Commit frame is not supported.

### `WDI_SAE_STATUS_COMMIT_MESSAGE_ANTICLOGGING_TOKEN_REQUIRED_BUT_NO_TOKEN:15`

The Commit frame contained the error code requiring the anti-clogging token, but the frame did not contain the anti-clogging token.

### `WDI_SAE_STATUS_COMMIT_MESSAGE_INVALID_SCALAR_ELEMENT_SIZE:16`

The Commit frame did not contain enough space for the Scalar or Element fields.

### `WDI_SAE_STATUS_COMMIT_MESSAGE_REFLECTION_ATTACK_DETECTED:17`

WDI detected a reflection attack.

### `WDI_SAE_STATUS_COMMIT_MESSAGE_INTERNAL_COMPUTATION_ERROR:18`

WDI encountered an internal computation error.

### `WDI_SAE_STATUS_COMMIT_MESSAGE_INVALID_REJECTED_GROUP:` 19

WDI rejected the commit frame because it included a group in the Rejected Groups field that the OS actually supports.

### `WDI_SAE_STATUS_CONFIRM_MESSAGE_RECEIVED_IN_INVALID_STATE:30`

WDI received a Confirm frame when it was not expected.

### `WDI_SAE_STATUS_CONFIRM_MESSAGE_MALFORMED_AUTH_FRAME:31`

A bad Confirm frame was received.

### `WDI_SAE_STATUS_CONFIRM_MESSAGE_FAILURE_FROM_PEER:32`

An error was received in the Confirm frame.

### `WDI_SAE_STATUS_CONFIRM_MESSAGE_BSS_TRANSITION_REQUESTED:33`

WDI doesn't handle the Bss transition request.

### `WDI_SAE_STATUS_CONFIRM_MESSAGE_INTERNAL_COMPUTATION_ERROR:34`

WDI encountered an internal error.

### `WDI_SAE_STATUS_CONFIRM_MESSAGE_VERIFICATION_FAILED:35`

WDI failed to match the Verifier from the Confirm frame.

### `WDI_SAE_STATUS_CONFIRM_MESSAGE_RESEND_REQUEST:50`

The driver requests a new set of Confirm frame parameters to resend the Confirm request to the AP.

### `WDI_SAE_STATUS_TIMEOUT_WAITING_FOR_COMMIT_REQUEST:51`

The driver timed out waiting for a Commit Request from the OS.

### `WDI_SAE_STATUS_TIMEOUT_WAITING_FOR_CONFIRM_REQUEST:52`

The driver timed out waiting for a Confirm Request from the OS.

### `WDI_SAE_STATUS_TIMEOUT_WAITING_FOR_STATUS:53`

The driver timed out waiting for a Status from the OS.

### `WDI_SAE_STATUS_CONNECTION_CLEANED_UP:70`

Internal handling code.

### `WDI_SAE_STATUS_CLEAN_UP_CONTEXT:71`

Internal handling code.

## Remarks

This enumeration is a value in both the [OID_WDI_SET_SAE_AUTH_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/netcx/oid-wdi-set-sae-auth-params) command and the [NDIS_STATUS_WDI_INDICATION_SAE_AUTH_PARAMS_NEEDED](https://learn.microsoft.com/windows-hardware/drivers/netcx/ndis-status-wdi-indication-sae-auth-params-needed) indication.

## See also

[WPA3-SAE Authentication](https://learn.microsoft.com/windows-hardware/drivers/netcx/wificx-wpa3-sae-authentication)

[OID_WDI_SET_SAE_AUTH_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/netcx/oid-wdi-set-sae-auth-params)

[NDIS_STATUS_WDI_INDICATION_SAE_AUTH_PARAMS_NEEDED](https://learn.microsoft.com/windows-hardware/drivers/netcx/ndis-status-wdi-indication-sae-auth-params-needed)