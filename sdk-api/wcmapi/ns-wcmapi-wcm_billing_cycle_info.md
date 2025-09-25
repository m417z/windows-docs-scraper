# WCM_BILLING_CYCLE_INFO structure

## Description

The **WCM_BILLING_CYCLE_INFO** structure specifies information about the billing cycle.

## Members

### `StartDate`

Type: **FILETIME**

Specifies the start date of the cycle.

### `Duration`

Type: **[WCM_TIME_INTERVAL](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_time_interval)**

Specifies the billing cycle duration.

### `Reset`

Type: **BOOL**

True if at the end of the billing cycle, a new billing cycle of the same duration will start. False if the service will terminate at the end of the billing cycle.

## See also

[WCM_TIME_INTERVAL](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_time_interval)