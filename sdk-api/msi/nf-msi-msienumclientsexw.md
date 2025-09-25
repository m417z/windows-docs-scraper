# MsiEnumClientsExW function

## Description

The
**MsiEnumClientsEx** function enumerates the installed applications that use a specified component. The function retrieves a [product code](https://learn.microsoft.com/windows/desktop/Msi/product-codes) for an application each time it is called.

**[Windows Installer 4.5 or earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-4-5):** Not supported. This function is available beginning with Windows Installer 5.0.

## Parameters

### `szComponent` [in]

The component code GUID that identifies the component. The function enumerates the applications that use this component.

### `szUserSid` [in, optional]

A null-terminated string value that contains a security identifier (SID.) The enumeration of applications extends to users identified by this SID. The special SID string s-1-1-0 (Everyone) enumerates all applications for all users in the system. A SID value other than s-1-1-0 specifies a user SID for a particular user and enumerates the instances of applications installed by the specified user.

| SID type | Meaning |
| --- | --- |
| ****NULL**** | Specifies the currently logged-on user. |
| **User SID** | Specifies an enumeration for a particular user. An example of an user SID is "S-1-3-64-2415071341-1358098788-3127455600-2561". |
| **s-1-1-0** | Specifies an enumeration for all users in the system. |

**Note** The special SID string s-1-5-18 (System) cannot be used to enumerate applications that exist in the per-machine installation context. Setting the SID value to s-1-5-18 returns **ERROR_INVALID_PARAMETER**. When *dwContext* is set to **MSIINSTALLCONTEXT_MACHINE** only, the value of *szUserSid* must be **NULL**.

### `dwContext` [in]

A flag that extends the enumeration to instances of applications installed in the specified installation context. The enumeration includes only instances of applications that are installed by the users identified by *szUserSid*.

This can be a combination of the following values.

| Context | Meaning |
| --- | --- |
| **MSIINSTALLCONTEXT_USERMANAGED**<br><br>1 | Include applications installed in the per–user–managed installation context. |
| **MSIINSTALLCONTEXT_USERUNMANAGED**<br><br>2 | Include applications installed in the per–user–unmanaged installation context. |
| **MSIINSTALLCONTEXT_MACHINE**<br><br>4 | Include applications installed in the per-machine installation context. When *dwInstallContext* is set to **MSIINSTALLCONTEXT_MACHINE** only, the value of the *szUserSID* parameter must be **NULL**. |

### `dwProductIndex` [in]

Specifies the index of the application to retrieve. The value of this parameter must be zero (0) in the first call to the function. For each subsequent call, the index must be incremented by 1. The index should only be incremented if the previous call to the function returns **ERROR_SUCCESS**.

### `szProductBuf` [out, optional]

A string value that receives the product code for the application. The length of the buffer at this location should be large enough to hold a null-terminated string value containing the product code. The first 38 **TCHAR** characters receives the GUID for the component, and the 39th character receives a terminating NULL character.

### `pdwInstalledContext` [out, optional]

A flag that gives the installation context of the application.

This can be a combination of the following values.

| Context | Meaning |
| --- | --- |
| **MSIINSTALLCONTEXT_USERMANAGED**<br><br>1 | The application is installed in the per–user–managed installation context. |
| **MSIINSTALLCONTEXT_USERUNMANAGED**<br><br>2 | The application is installed in the per–user–unmanaged installation context. |
| **MSIINSTALLCONTEXT_MACHINE**<br><br>4 | The application is in the per-machine installation installation context. |

### `szSid` [out, optional]

Receives the security identifier (SID) that identifies the user that installed the application. The location receives an empty string value if this instance of the application exists in a per-machine installation context.

The length of the buffer should be large enough to hold a null-terminated string value containing the SID. If the buffer is too small, the function returns **ERROR_MORE_DATA** and the location pointed to by *pcchSid* receives the number of **TCHAR** in the SID, not including the terminating NULL character.

If *szSid* is set to **NULL** and *pcchSid* is a valid pointer to a location in memory, the function returns **ERROR_SUCCESS** and the location receives the number of **TCHAR** in the SID, not including the terminating null character. The function can then be called again to retrieve the value, with the *szSid* buffer resized large enough to contain *pcchSid + 1 characters.

| SID type | Meaning |
| --- | --- |
| Empty string | The application is installed in a per-machine installation context. |
| **User SID** | The SID for the user that installed the product. |

### `pcchSid` [in, out, optional]

Pointer to a location in memory that contains a variable that specifies the number of **TCHAR** in the SID, not including the terminating null character. When the function returns, this variable is set to the size of the requested SID whether or not the function can successfully copy the SID and terminating null character into the buffer location pointed to by *szSid*. The size is returned as the number of TCHAR in the requested value, not including the terminating null character.

This parameter can be set to **NULL** only if *szSid* is also **NULL**, otherwise the function returns **ERROR_INVALID_PARAMETER**. If *szSid* and *pcchSid* are both set to **NULL**, the function returns **ERROR_SUCCESS** if the SID exists, without retrieving the SID value.

## Return value

The **MsiEnumClientsEx** function returns one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Administratator privileges are required to enumerate components of applications installed by users other than the current user. |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter is passed to the function. |
| **ERROR_NO_MORE_ITEMS** | There are no more applications to enumerate. |
| **ERROR_SUCCESS** | The function succeeded. |
| **ERROR_MORE_DATA** | The provided buffer was too small to hold the entire value. |
| **ERROR_FUNCTION_FAILED** | The function failed. |

## Remarks

> [!NOTE]
> The msi.h header defines MsiEnumClientsEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).