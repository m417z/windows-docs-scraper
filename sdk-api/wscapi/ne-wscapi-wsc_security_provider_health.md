# WSC_SECURITY_PROVIDER_HEALTH enumeration

## Description

Defines the possible states for any service monitored by Windows Security Center (WSC).

## Constants

### `WSC_SECURITY_PROVIDER_HEALTH_GOOD`

The status of the security provider category is good and does not need user attention.

### `WSC_SECURITY_PROVIDER_HEALTH_NOTMONITORED`

The status of the security provider category is not monitored by WSC.

### `WSC_SECURITY_PROVIDER_HEALTH_POOR`

The status of the security provider category is poor and the computer may be at risk.

### `WSC_SECURITY_PROVIDER_HEALTH_SNOOZE`

The security provider category is in snooze state. Snooze indicates that WSC is not actively protecting the computer.

## See also

[WscGetSecurityProviderHealth](https://learn.microsoft.com/windows/desktop/api/wscapi/nf-wscapi-wscgetsecurityproviderhealth)