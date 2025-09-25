# WCM_DATAPLAN_STATUS structure

## Description

The **WCM_DATAPLAN_STATUS** structure specifies subscription information for a network connection.

## Members

### `UsageData`

Type: **[WCM_USAGE_DATA](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_usage_data)**

Contains usage data.

### `DataLimitInMegabytes`

Type: **DWORD**

Specifies the data limit, in megabytes.

### `InboundBandwidthInKbps`

Type: **DWORD**

Specifies the inbound bandwidth, in kilobits per second.

### `OutboundBandwidthInKbps`

Type: **DWORD**

Specifies the outbound bandwidth, in kilobits per second.

### `BillingCycle`

Type: **[WCM_BILLING_CYCLE_INFO](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_billing_cycle_info)**

Contains information about the billing cycle.

### `MaxTransferSizeInMegabytes`

Type: **DWORD**

Specifies the maximum size of a file that can be transferred, in megabytes.

### `Reserved`

Type: **DWORD**

Reserved.

## See also

[WCM_BILLING_CYCLE_INFO](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_billing_cycle_info)

[WCM_USAGE_DATA](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_usage_data)