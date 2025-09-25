# ICertificateEnrollmentServerSetup::GetProperty

## Description

The **GetProperty** method retrieves a [CESSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-cessetupproperty) enumeration value for the Certificate Enrollment Web Service (CES) configuration.

## Parameters

### `propertyId` [in]

A [CESSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-cessetupproperty) enumeration value that specifies the property value to retrieve. For more information, see Remarks.

### `pPropertyValue` [out]

A pointer to a **VARIANT** variable that contains the property value.

## Return value

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *propertyId* argument is not a member of the [CESSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-cessetupproperty) enumeration type. |
| **E_POINTER** | The *pPropertyValue* parameter cannot be **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)** | The [ICertificateEnrollmentServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentserversetup) object has not been initialized.<br><br>The [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property value is set to "The setup object has not been initialized. Please initialize the setup object with the InitializeInstallDefaults method." |

## Remarks

The [CESSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-cessetupproperty) enumeration type contains the following values:

* **ENUM_CESSETUPPROP_USE_IISAPPPOOLIDENTITY**
* **ENUM_CESSETUPPROP_CACONFIG**
* **ENUM_CESSETUPPROP_AUTHENTICATION**
* **ENUM_CESSETUPPROP_SSLCERTHASH**
* **ENUM_CESSETUPPROP_URL**
* **ENUM_CESSETUPPROP_RENEWALONLY**

These values have the following meanings:

* The **ENUM_CESSETUPPROP_USE_IISAPPPOOLIDENTITY** property is a **VT_BOOL** value that specifies whether the server context is **ApplicationPoolIdentity**.
* The **ENUM_CESSETUPPROP_CACONFIG** property contains a certification authority (CA) configuration string (**VT_BSTR**) of the form *computerDNSname*/*CAName* where *computerDNSname* is the fully qualified DNS name of the server and *CAName* is the common name of the CA.
* The **ENUM_CESSETUPPROP_AUTHENTICATION** property specifies the type of authentication procedure used. If the **GetProperty** method returns successfully, the *pPropertyValue* argument will contain one of the following constants:
  + X509AuthKerberos
  + X509AuthUsername
  + X509AuthCertificate
* The **ENUM_CESSETUPPROP_SSLCERTHASH** property contains the hash (**VT_BSTR**) of the certificate used during authentication. The **ENUM_CESSETUPPROP_AUTHENTICATION** property must be set to X509AuthCertificate.
* The **ENUM_CESSETUPPROP_URL** property contains the CES service URL. If the **GetProperty** method returns successfully, the *pPropertyValue* argument will contain a **VT_BSTR** subtype that contains a URL of the form "https://*computerDNSname*/ADPolicyProvider_ces_*AuthenticationType*/service.svc/ces" where the authentication type can be one of the following:
  + kerberos
  + usernamepassword
  + certificate
* The **ENUM_CESSETUPPROP_RENEWALONLY** property is a **VT_BOOL** value that specifies whether CES can process only certificate renewals.

## See also

[ICertificateEnrollmentServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentserversetup)