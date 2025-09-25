# WSC_SECURITY_PROVIDER enumeration

## Description

Defines all the services that are monitored by Windows Security Center (WSC).

## Constants

### `WSC_SECURITY_PROVIDER_FIREWALL:0x1`

The aggregation of all firewalls for this computer.

### `WSC_SECURITY_PROVIDER_AUTOUPDATE_SETTINGS:0x2`

The automatic update settings for this computer.

### `WSC_SECURITY_PROVIDER_ANTIVIRUS:0x4`

The aggregation of all antivirus products for this computer.

### `WSC_SECURITY_PROVIDER_ANTISPYWARE:0x8`

The aggregation of all anti-spyware products for this computer.

### `WSC_SECURITY_PROVIDER_INTERNET_SETTINGS:0x10`

The settings that restrict the access of web sites in each of the Internet zones for this computer.

### `WSC_SECURITY_PROVIDER_USER_ACCOUNT_CONTROL:0x20`

The User Account Control (UAC) settings for this computer.

### `WSC_SECURITY_PROVIDER_SERVICE:0x40`

The running state of the WSC service on this computer.

### `WSC_SECURITY_PROVIDER_NONE:0`

None of the items that WSC monitors.

### `WSC_SECURITY_PROVIDER_ALL`

All of the items that the WSC monitors.

## Remarks

> [!NOTE]
> [WSC_SECURITY_PROVIDER::WSC_SECURITY_PROVIDER_ANTISPYWARE](https://learn.microsoft.com/windows/desktop/api/wscapi/ne-wscapi-wsc_security_provider) should be used only in operating systems prior to Windows 10, version 1607. As of Windows 10, version 1607, WSC continues to track the status for antivirus, but not for anti-spyware.

## See also

[WscGetSecurityProviderHealth](https://learn.microsoft.com/windows/desktop/api/wscapi/nf-wscapi-wscgetsecurityproviderhealth)