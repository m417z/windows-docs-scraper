# ICertificateEnrollmentPolicyServerSetup::GetProperty

## Description

The **GetProperty** method retrieves a [CEPSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-cepsetupproperty) enumeration value for the Certificate Enrollment Policy (CEP) Web Service configuration.

## Parameters

### `propertyId` [in]

A value of the [CEPSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-cepsetupproperty) enumeration that specifies the property value to set. The following values are valid.

| Value | Description |
| --- | --- |
| **ENUM_CEPSETUPPROP_AUTHENTICATION** | The *pPropertyValue* parameter contains a value that identifies the type of authentication to be used. |
| **ENUM_CEPSETUPPROP_SSLCERTHASH** | The *pPropertyValue* parameter contains a hash of the certificate, if any, used during authentication. |
| **ENUM_CEPSETUPPROP_KEYBASED_RENEWAL** | The *pPropertyValue* parameter specifies whether to set up the Enrollment Policy Server in a mode that returns policies for KeyBasedRenewal templates only. |
| **ENUM_CEPSETUPPROP_URL** | Contains the CEP service URL. If the **GetProperty** method returns successfully, the *pPropertyValue* argument will contain a **VT_BSTR** subtype that contains a URL of the form "https://*computerDNSname*/ADPolicyProvider_cep_*AuthenticationType*/service.svc/cep" where the authentication type can be one of the following:<br><br>* kerberos<br>* usernamepassword<br>* certificate |

### `pPropertyValue` [out]

A pointer to a **VARIANT** variable that contains the property value.

If you specify **ENUM_CEPSETUPPROP_AUTHENTICATION** in the *propertyId* parameter, the *pPropertyValue* parameter will contain one of the following constants if the **GetProperty** method returns successfully:

* **X509AuthKerberos**
* **X509AuthUsername**
* **X509AuthCertificate**

If you specify **ENUM_CEPSETUPPROP_SSLCERTHASH** in the *propertyId* parameter, the *pPropertyValue* parameter will contain a **VT_BSTR** subtype that contains the hash if the **GetProperty** method returns successfully.

If you specify **ENUM_CEPSETUPPROP_AUTHENTICATION** in the *propertyId* parameter, the *pPropertyValue* parameter contains the authentication procedure.

If you specify **ENUM_CEPSETUPPROP_URL** in the *propertyId* parameter, the *pPropertyValue* parameter contains the Certificate Enrollment Policy (CEP) Web Service URL.

If you specify **ENUM_CEPSETUPPROP_KEYBASED_RENEWAL** in the *propertyId* parameter, you must set the *pPropertyValue* parameter to the **VT_BOOL** subtype that indicates whether to set up the Enrollment Policy Server in a mode that returns policies for KeyBasedRenewal templates only.

## Return value

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *propertyId* argument is not a member of the [CEPSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-cepsetupproperty) enumeration type. |
| **E_POINTER** | The *pPropertyValue* parameter cannot be **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)** | The [ICertificateEnrollmentPolicyServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentpolicyserversetup) object has not been initialized.<br><br>The [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-get_errorstring) property value is set to "The setup object has not been initialized. Please initialize the setup object with the InitializeInstallDefaults method." |

## See also

[ICertificateEnrollmentPolicyServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentpolicyserversetup)

[InitializeInstallDefaults](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-initializeinstalldefaults)

[SetProperty](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-setproperty)