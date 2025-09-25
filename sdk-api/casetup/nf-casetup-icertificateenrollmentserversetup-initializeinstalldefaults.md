# ICertificateEnrollmentServerSetup::InitializeInstallDefaults

## Description

The **InitializeInstallDefaults** method initializes the [ICertificateEnrollmentServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentserversetup) object with a default configuration.

## Return value

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | A user must be an administrator of the domain root or the enterprise. A computer must be joined to the domain.<br><br>If the user is not a domain root or enterprise administrator, the [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property is set to:<br><br>"You must be a member of the Enterprise Admins group to run Setup."<br><br>If the computer is not joined to the domain, the [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property is set to:<br><br>"The Certificate Enrollment Web Service or Certificate Enrollment Policy Web Service cannot be installed on a computer that is not a member of a domain." |
| **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)** | The [ICertificateEnrollmentServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentserversetup) object has already been initialized. The [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property is set to:<br><br>"The setup object has already been initialized. This object cannot be initialized more than once." |

## Remarks

This method performs the following actions:

* Determines whether the [ICertificateEnrollmentServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentserversetup) object has already been initialized.

  **Note** If this check fails, the method sets the [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property to "The setup object has already been initialized. This object cannot be initialized more than once."
* Determines whether the user is an administrator of the domain root or the enterprise.

  **Note** If this check fails, the method sets the [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property to "You must be a member of the Enterprise Admins group to run Setup."
* Determines whether the computer is joined to the domain.

  **Note** If this check fails, the method sets the [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property to "The Certificate Enrollment Web Service or Certificate Enrollment Policy Web Service cannot be installed on a computer that is not a member of a domain."
* Sets the default authentication procedure to Kerberos. You can call [SetProperty](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-setproperty) to change the authentication method.
* Determines whether CES is installed on a computer running Windows Server 2008 R2.

  **Note** If this check fails, the method sets the [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property to "The Certificate Enrollment Web Service or Certificate Enrollment Policy Web Service must be installed on a member server in an Active Directory forest in which the Windows Server 2008 R2 version of ADPrep /forestprep has been successfully run."
* Sets the default server context to the **ApplicationPoolIdentity** built-in account.
* Sets the ENUM_CESSETUPPROP_RENEWALONLY property to **FALSE**.
* Sets the ENUM_CESSETUPPROP_URL property is to "https://*computerDNSname*/*SanitizedCAShortName*_CES_Kerberos/service.svc/ces" if a valid certification authority (CA) configuration exists. If a valid configuration does not exist, the ENUM_CESSETUPPROP_URL property is not set. The *SanitizedCAShortName* is the sanitized short name of the CA. For more information about sanitized names, see [GetConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertgetconfig-getconfig).

  **Note** If the certification authority is a standalone CA, the [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property is set to "The Certificate Enrollment Web Service cannot be used with a standalone certification authority (CA). It can only be used with an enterprise CA."

You must call the **InitializeInstallDefaults** method before calling any method other than [UnInstall](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-uninstall). Call the [Install](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-install) method to install the configured service. Call **UnInstall** on a new [ICertificateEnrollmentServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentserversetup) object to remove the service.

## See also

[CESSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-cessetupproperty)

[ICertificateEnrollmentServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentserversetup)