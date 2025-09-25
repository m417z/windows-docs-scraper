# ICertificateEnrollmentPolicyServerSetup::SetProperty

## Description

The **SetProperty** method specifies a [CEPSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-cepsetupproperty) enumeration value for the Certificate Enrollment Policy (CEP) Web Service configuration.

## Parameters

### `propertyId` [in]

A value of the [CEPSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-cepsetupproperty) enumeration that specifies the property value to set. The following values are valid.

| Value | Description |
| --- | --- |
| **ENUM_CEPSETUPPROP_AUTHENTICATION** | The *pPropertyValue* parameter contains a value that identifies the type of authentication to be used. |
| **ENUM_CEPSETUPPROP_SSLCERTHASH** | The *pPropertyValue* parameter contains a hash of the certificate, if any, used during authentication. **ENUM_CEPSETUPPROP_AUTHENTICATION** must be set to X509AuthCertificate. |
| **ENUM_CEPSETUPPROP_KEYBASED_RENEWAL** | The *pPropertyValue* parameter specifies whether to set up the Enrollment Policy Server in a mode that returns policies for KeyBasedRenewal templates only. |
| **ENUM_CEPSETUPPROP_URL** | You cannot specify this value. |

### `pPropertyValue` [in]

A pointer to a **VARIANT** variable that contains the property value.

If you specify **ENUM_CEPSETUPPROP_AUTHENTICATION** in the *propertyId* parameter, the **VARIANT** subtype must be **VT_I2**, **VT_I4** or **VT_UII4**, and the *pPropertyValue* argument must be one of the following constants:

* **X509AuthKerberos**
* **X509AuthUsername**
* **X509AuthCertificate**

If you specify **ENUM_CEPSETUPPROP_SSLCERTHASH** in the *propertyId* parameter, you must set the *pPropertyValue* parameter to a **VT_BSTR** subtype that contains a hash of the certificate used for authentication.

If you specify **ENUM_CEPSETUPPROP_AUTHENTICATION** in the *propertyId* parameter, the *pPropertyValue* parameter contains the authentication procedure.

If you specify **ENUM_CEPSETUPPROP_URL** in the *propertyId* parameter, the *pPropertyValue* parameter contains the Certificate Enrollment Policy (CEP) Web Service URL.

If you specify **ENUM_CEPSETUPPROP_KEYBASED_RENEWAL** in the *propertyId* parameter, you must set the *pPropertyValue* parameter to the **VT_BOOL** subtype that indicates whether to set up the Enrollment Policy Server in a mode that returns policies for KeyBasedRenewal templates only.

## Return value

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *propertyId* argument is not a member of the [CEPSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-cepsetupproperty) enumeration type or you have tried to set the **ENUM_CEPSETUPPROP_URL** value. |
| **E_POINTER** | The *pPropertyValue* parameter cannot be **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)** | The [ICertificateEnrollmentPolicyServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentpolicyserversetup) object has not been initialized.<br><br>The [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-get_errorstring) property value is set to "The setup object has not been initialized. Please initialize the setup object with the InitializeInstallDefaults method." |
| **HRESULT_FROM_WIN32(ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH)** | If you are setting the **ENUM_CEPSETUPPROP_AUTHENTICATION** property, the **VARIANT** subtype must be **VT_I2**, **VT_I4**, or **VT_UI4**. |

## Remarks

You must call [InitializeInstallDefaults](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-initializeinstalldefaults) before calling the **SetProperty** method.

## See also

[GetProperty](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-getproperty)

[ICertificateEnrollmentPolicyServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentpolicyserversetup)

[InitializeInstallDefaults](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentpolicyserversetup-initializeinstalldefaults)