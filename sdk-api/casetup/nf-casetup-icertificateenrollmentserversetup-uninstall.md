## Description

The **UnInstall** method removes the Certificate Enrollment Web Service (CES).

## Parameters

### `pCAConfig`

This parameter is reserved for future use.

### `pAuthentication`

This parameter is reserved for future use.

## Return value

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The user must be a local administrator.<br><br>The [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property value is set to "You have to be the local machine administrator in order to run this setup." |
| **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)** | The [ICertificateEnrollmentServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentserversetup) object has been initialized. An object is initialized when you successfully call [InitializeInstallDefaults](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-initializeinstalldefaults).<br><br>The [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property value is set to "The object has been initialized. You cannot call UnInstall on an initialized object." |

## Remarks

You can call this method to remove CES. However, because you cannot call the **UnInstall** method on an [ICertificateEnrollmentServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentserversetup) object that has already been initialized, you must create a new **ICertificateEnrollmentServerSetup** before calling **UnInstall**.

This method attempts to delete all CES-related directories and the application pool. If it is unable to do so, it still returns S_OK, but you can check the [ErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-get_errorstring) property to determine what problems the method encountered.

This function performs the following actions:

* Initializes Windows Management Instrumentation (WMI).
* Attempts to delete the %windir%\systemdata\ces directory and all application subdirectories that may exist. For more information, see the [Install](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-install) Remarks section.
* Attempts to delete the application pool and all applications in the pool.
* Attempts to update the security descriptor of the Deleted Objects container in Active Directory to deny access by the computer. For more information, see the [Install](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertificateenrollmentserversetup-install) Remarks section.

## See also

[ICertificateEnrollmentServerSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertificateenrollmentserversetup)