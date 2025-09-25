# ICertificateEnrollmentPolicyServerSetup::Install

## Description

The **Install** method installs the Certificate Enrollment Policy (CEP) Web Service configured by the [ICertificateEnrollmentPolicyServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentpolicyserversetup) object.

## Return value

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | The name specified for the event tracing directory or the application directory already existed but represented a file rather than a directory. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_EXISTS)** | The CEP application already exists. For more information, see Remarks. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)** | The [ICertificateEnrollmentPolicyServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentpolicyserversetup) object has not been initialized.<br><br>The [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-get_errorstring) property value is set to "The setup object has not been initialized. Please initialize the setup object with the InitializeInstallDefaults method." |

## Remarks

This function performs the following actions:

* Initializes Windows Management Instrumentation (WMI).
* Validates the CEP configuration by verifying that an application with the same name does not already exist. The application name is part of the CEP URL where the URL is of the form "https://*computerDNSname*/ADPolicyProvider_cep_*AuthenticationType*/service.svc/cep". The application name consists of "ADPolicyProvider_cep_*AuthenticationType*" where *AuthenticationType* can be one of the following:
  + kerberos
  + usernamepassword
  + certificate

  **Note** If an application with the same name exists, the [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-get_errorstring) property is set to "Setup could not add this role service because it already exists in the default website. Please remove the existing role service or select a different certification authority (CA) or authentication type."
* Creates the %windir%\systemdata\cep\ADPolicyProvider_cep_*AuthenticationType* application directory.

  **Note** This method does not return an error if the name specified already exists as a directory, but if the specified name exists as a file or if some other error occurred, the method returns a failure **HRESULT** and sets the [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-get_errorstring) property to "Failed to create the directory %1."
* Creates the %windir%\systemdata\cep\ADPolicyProvider_cep_*AuthenticationType*\Traces event tracing directory.
* Creates the Web.config and Service.svc files and writes them to the application directory. If the files already exist, they are overwritten.
* Creates an IIS application pool. By default, the pool runs under the **ApplicationPoolIdentity** account.
* Creates the application in the default website.
* Creates a secure (https) binding to port 443 and sets the certificate hash if one has been specified during configuration by calling the [SetProperty](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-setproperty) method.
* Sets IIS authentication to anonymous if you called [SetProperty](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-setproperty) and specified X509AuthCertificate or X509AuthUsername in the *pPropertyValue* argument. Sets authentication to Windows if you called **SetProperty** and specified X509AuthKerberos.
* Sets SSL flags depending on the type of authentication chosen during configuration. The default flags for all authentication types are SSL (require secure channel) and SSL_128 (128-bit encryption). Additionally, if you specify X509AuthCertificate, the SSL_REQUIRE_CERT and SSL_NEGOTIATE_CERT flags are set.
* Adds read and write access to the event tracing directory.
* Updates the security descriptor of the Deleted Objects container in Active Directory to permit access by the computer and/or the application pool. This enables the CEP service to notify the certification authority when a relevant Active Directory object is deleted. If Active Directory is installed on a domain controller, both the computer and application pool are allowed to access the Deleted Objects container. If Active Directory is not installed on a domain controller, only the computer is allowed access.

  **Note** If access to the Deleted Objects container fails, the method returns a failure **HRESULT** and sets the [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-get_errorstring) property to "Setup cannot give the Certificate Enrollment Policy Web Service account List permission on the ""Deleted Objects"" container. The web service will not be able to detect deletion of Active Directory objects such as certificate templates. To complete Setup, a member of the Domain Admins group must manually give the Certificate Enrollment Policy Web Service account List permission on the ""Deleted Objects"" container in Active Directory Domain Services (AD DS)."

## See also

[ICertificateEnrollmentPolicyServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentpolicyserversetup)

[SetProperty](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-setproperty)