# CREDENTIAL_PROVIDER_STATUS_ICON enumeration

## Description

Indicates which status icon should be displayed.

## Constants

### `CPSI_NONE:0`

No icon indicated.

### `CPSI_ERROR`

Display the error icon.

### `CPSI_WARNING`

Display the warning icon.

### `CPSI_SUCCESS`

Reserved.

## Remarks

**CREDENTIAL_PROVIDER_STATUS_ICON** is not used starting in Windows 10.

As part of [ReportResult](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredential-reportresult), a credential provider may specify a status icon to display. It is important to note that only Logon UI calls **ReportResult**, Credential UI does not.