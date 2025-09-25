# ICertificateEnrollmentPolicyServerSetup::UnInstall

## Description

The **UnInstall** method removes the Certificate Enrollment Policy (CEP) Web Service.

## Parameters

### `pAuthKeyBasedRenewal` [in, optional]

A pointer to a **VARIANT** array that contains the authentication type and the optional KeyBasedRenewal values.

You can set the following values for authentication type in the first element of the array.

* X509AuthKerberos
* X509AuthUserName
* X509AuthCertificate

The second (optional) element in the array value is **VARIANT_TRUE** for a KeyBasedRenewal CEP.

## Return value

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The user must be a local administrator.<br><br>The [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-get_errorstring) property value is set to "You have to be the local machine administrator in order to run this setup." |
| **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)** | The [ICertificateEnrollmentPolicyServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentpolicyserversetup) object has been initialized. An object is initialized when you successfully call [InitializeInstallDefaults](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-initializeinstalldefaults).<br><br>The [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-get_errorstring) property value is set to "The object has been initialized. You cannot call UnInstall on an initialized object." |

## Remarks

You can call this method to remove the CEP service. However, because you cannot call the **UnInstall** method on an [ICertificateEnrollmentPolicyServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentpolicyserversetup) object that has already been initialized, you must create a new **ICertificateEnrollmentPolicyServerSetup** before calling **UnInstall**.

When the *pAuthKeyBasedRenewal* parameter is NULL, this function performs the following actions:

* Initializes Windows Management Instrumentation (WMI).
* Attempts to delete the %Windir%\Systemdata\Cep directory and all application subdirectories that may exist. For more information, see the [Install](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-install) Remarks section.
* Attempts to delete the application pool and all applications in the pool.
* Attempts to update the security descriptor of the Deleted Objects container in Active Directory to deny access by the computer. For more information, see the [Install](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-install) Remarks section.

When the *pAuthKeyBasedRenewal* parameter contains values for the authentication type and KeyBasedRenewal, this function performs the actions in the previous list but it only deletes the application that corresponds to the values set in *pAuthKeyBasedRenewal* and leaves other applications in place.

## See also

[ICertificateEnrollmentPolicyServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentpolicyserversetup)

[InitializeInstallDefaults](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-initializeinstalldefaults)

[Install](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-install)