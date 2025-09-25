# ICertificateEnrollmentServerSetup::SetApplicationPoolCredentials

## Description

The **SetApplicationPoolCredentials** method specifies user account information for the application pool in which the Certificate Enrollment Web Service (CES) runs.

## Parameters

### `bstrUsername` [in]

A **BSTR** that contains the username for the account.

### `bstrPassword` [in]

A **BSTR** that contains the account password.

## Return value

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *bstrUsername* and *bstrPassword* arguments cannot be **NULL** or empty. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)** | The [ICertificateEnrollmentServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentserversetup) object has not been initialized.<br><br>The [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property value is set to "The setup object has not been initialized. Please initialize the setup object with the InitializeInstallDefaults method." |

## Remarks

The **SetApplicationPoolCredentials** method determines whether the user credentials are valid and whether the account is a member of the IIS_IUSRS group. If an error is encountered, the [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property can be set to any of the following:

* "Setup is unable to obtain security information for the account."
* "Setup is unable to check the membership of the account."
* "The account is not a member of the local machine's IIS_IUSRS group."
* "Fail to retrieve the DNS name of the computer."
* "The account should be a domain account. Local account is not allowed."

## See also

[ICertificateEnrollmentServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentserversetup)