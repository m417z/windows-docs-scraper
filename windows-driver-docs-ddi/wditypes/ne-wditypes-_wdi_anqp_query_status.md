# _WDI_ANQP_QUERY_STATUS enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_ANQP_QUERY_STATUS enumeration defines the Access Network Query Protocol (ANQP) query status values.

## Constants

### `WDI_ANQP_QUERY_STATUS_SUCCESS`

Maps to SUCCESS.

### `WDI_ANQP_QUERY_STATUS_FAILURE`

The failure did not map to any of the other status codes.

### `WDI_ANQP_QUERY_STATUS_TIMED_OUT`

 Maps to GAS_QUERY_TIMEOUT. The STA timed out waiting for a GAS response.

### `WDI_ANQP_QUERY_STATUS_RESOURCES`

The operating system is unable to allocate sufficient resources to complete the request.

### `WDI_ANQP_QUERY_STATUS_ADVERTISEMENT_PROTOCOL_NOT_SUPPORTED_ON_REMOTE`

Maps to GAS_ADVERTISEMENT_PROTOCOL_NOT_SUPPORTED. The GAS advertisement protocol is not supported on the remote device.

### `WDI_ANQP_QUERY_STATUS_GAS_PROTOCOL_FAILURE`

Mapped for any of the following errors.

* NO_OUTSTANDING_GAS_REQUEST
* GAS_QUERY_RESPONSE_TOO_LARGE
* TRANSMISSION_FAILURE

### `WDI_ANQP_QUERY_STATUS_ADVERTISEMENT_SERVER_NOT_RESPONDING`

Mapped for any of the following errors.

* GAS_RESPONSE_NOT_RECEIVED_FROM_SERVER
* GAS_QUERY_TIMEOUT
* SERVER_UNREACHABLE

### `WDI_ANQP_QUERY_STATUS_ACCESS_ISSUES`

Mapped for any of the following errors.

* REJECTED_HOME_WITH_SUGGESTED_CHANGES
* REJECTED_FOR_SSP_PERMISSIONS
* AP does not support unauthenticated access