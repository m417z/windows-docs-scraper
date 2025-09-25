# ICredentialProviderCredential::ReportResult

## Description

Translates a received error status code into the appropriate user-readable message. The Credential UI does not call this method.

## Parameters

### `ntsStatus` [in]

Type: **NTSTATUS**

The [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value that reflects the return value of the [Winlogon](https://learn.microsoft.com/windows/desktop/SecAuthN/winlogon) call to [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser).

### `ntsSubstatus` [in]

Type: **NTSTATUS**

The [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value that reflects the value pointed to by the *SubStatus* parameter of [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) when that function returns after being called by [Winlogon](https://learn.microsoft.com/windows/desktop/SecAuthN/winlogon).

### `ppszOptionalStatusText` [out]

Type: **LPWSTR***

A pointer to the error message that will be displayed to the user. May be **NULL**.

### `pcpsiOptionalStatusIcon` [out]

Type: **[CREDENTIAL_PROVIDER_STATUS_ICON](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_status_icon)***

A pointer to an icon that will shown on the credential. May be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is required for Logon UI.

This method is used to report the outcome of a logon attempt back to a credential. The information in *ntsStatus* and *ntsSubstatus* can also be used when credential providers want to generate custom error messages. That status text from this call will be displayed on the selected credential.