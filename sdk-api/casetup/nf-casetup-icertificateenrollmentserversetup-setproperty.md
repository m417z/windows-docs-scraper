# ICertificateEnrollmentServerSetup::SetProperty

## Description

The **SetProperty** method specifies a [CESSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-cessetupproperty) enumeration value for the Certificate Enrollment Web Service (CES) configuration.

## Parameters

### `propertyId` [in]

A [CESSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-cessetupproperty) enumeration value that specifies the property value to retrieve.

### `pPropertyValue` [in]

A pointer to a **VARIANT** variable that contains the property value.

## Return value

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *propertyId* argument is not a member of the [CESSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-cessetupproperty) enumeration type.<br><br>Also, if you are setting the **ENUM_CESSETUPPROP_AUTHENTICATION** property, you must specify one of the following values in the *pPropertyValue* argument:<br><br>* **X509AuthKerberos**<br>* **X509AuthUsername**<br>* **X509AuthCertificate** |
| **E_POINTER** | The *pPropertyValue* parameter cannot be **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)** | The [ICertificateEnrollmentServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentserversetup) object has not been initialized.<br><br>The [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property value is set to "The setup object has not been initialized. Please initialize the setup object with the InitializeInstallDefaults method." |
| **HRESULT_FROM_WIN32(ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH)** | If you are setting the **ENUM_CESSETUPPROP_AUTHENTICATION** property, the **VARIANT** subtype must be **VT_I2**, **VT_I4**, or **VT_UI4**. |

## Remarks

You must call [InitializeInstallDefaults](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-initializeinstalldefaults) before calling **SetProperty**.

You cannot set the **ENUM_CESSETUPPROP_URL** property.

You cannot set the **ENUM_CESSETUPPROP_USE_IISAPPPOOLIDENTITY** if the WSEnrollmentServer application pool already exists and WMI has been initialized.

If you are setting the **ENUM_CESSETUPPROP_AUTHENTICATION** property, the **VARIANT** subtype must be **VT_I2**, **VT_I4** or **VT_UII4**, and the *pPropertyValue* argument must be one of the following constants:

* **X509AuthKerberos**
* **X509AuthUsername**
* **X509AuthCertificate**

You cannot set the ENUM_CESSETUPPROP_CACONFIG property if the target server is a standalone certification authority. The [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property will be set to "The Certificate Enrollment Web Service cannot be used with a standalone certification authority (CA). It can only be used with an enterprise CA."

.

## See also

[ICertificateEnrollmentServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentserversetup)