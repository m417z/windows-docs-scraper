# ICertificateEnrollmentPolicyServerSetup::InitializeInstallDefaults

## Description

The **InitializeInstallDefaults** method initializes the [ICertificateEnrollmentPolicyServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentpolicyserversetup) object with a default configuration.

## Return value

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | A user must be an administrator of the domain root or the enterprise. A computer must be joined to the domain.<br><br>If the user is not a domain root or enterprise administrator, the [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-get_errorstring) property is set to:<br><br>"You must be a member of the Enterprise Admins group to run Setup."<br><br>If the computer is not joined to the domain, the [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-get_errorstring) property is set to:<br><br>"The Certificate Enrollment Web Service or Certificate Enrollment Policy Web Service cannot be installed on a computer that is not a member of a domain." |
| **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)** | The [ICertificateEnrollmentPolicyServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentpolicyserversetup) object has already been initialized. The [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-get_errorstring) property is set to:<br><br>"The setup object has already been initialized. This object cannot be initialized more than once." |

## Remarks

This method performs the following actions:

* Sets the default authentication procedure to Kerberos. You can call [SetProperty](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-setproperty) to change the authentication method.
* Sets the default URL to https://*computerDNSname*/ADPolicyProvider_CEP_Kerberos/service.svc/CEP.
* Checks to determine whether the CEP service is installed on a computer running Windows Server 2008 R2.

  **Note** If this check fails, the method sets the [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property to "The Certificate Enrollment Web Service or Certificate Enrollment Policy Web Service must be installed on a member server in an Active Directory forest in which the Windows Server 2008 R2 version of ADPrep /forestprep has been successfully run."

You must call the **InitializeInstallDefaults** method before calling any method other than [UnInstall](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-uninstall). Call the [Install](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-install) method to install the configured CEP service. Call the **UnInstall** method on a new [ICertificateEnrollmentPolicyServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentpolicyserversetup) object to remove the service.

## See also

[CEPSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-cepsetupproperty)

[ICertificateEnrollmentPolicyServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentpolicyserversetup)

[SetProperty](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-setproperty)