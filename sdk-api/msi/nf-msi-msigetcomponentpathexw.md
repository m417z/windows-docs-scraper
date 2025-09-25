# MsiGetComponentPathExW function

## Description

The
**MsiGetComponentPathEx** function returns the full path to an installed component. If the key path for the component is a registry key then the function returns the registry key.

This function extends the existing [MsiGetComponentPath](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msigetcomponentpatha) function to enable searches for components across user accounts and installation contexts.

## Parameters

### `szProductCode` [in]

A null-terminated string value that specifies an application's product code GUID. The function gets the path of installed components used by this application.

### `szComponentCode` [in]

A null-terminated string value that specifies a component code GUID. The function gets the path of an installed component having this component code.

### `szUserSid` [in, optional]

A null-terminated string value that specifies the security identifier (SID) for a user in the system. The function gets the paths of installed components of applications installed under the user accounts identified by this SID. The special SID string s-1-1-0 (Everyone) specifies all users in the system. If this parameter is **NULL**, the function gets the path of an installed component for the currently logged-on user only.

| SID type | Meaning |
| --- | --- |
| ****NULL**** | Specifies the currently logged-on user. |
| **User SID** | Specifies a particular user in the system. An example of an user SID is "S-1-3-64-2415071341-1358098788-3127455600-2561". |
| **s-1-1-0** | Specifies all users in the system. |

**Note** The special SID string s-1-5-18 (System) cannot be used to search applications installed in the per-machine installation context. Setting the SID value to s-1-5-18 returns **ERROR_INVALID_PARAMETER**. When *dwContext* is set to MSIINSTALLCONTEXT_MACHINE only, *szUserSid* must be **NULL**.

### `dwContext` [in, optional]

A flag that specifies the installation context. The function gets the paths of installed components of applications installed in the specified installation context. This parameter can be a combination of the following values.

| Context | Meaning |
| --- | --- |
| **MSIINSTALLCONTEXT_USERMANAGED**<br><br>1 | Include applications installed in the per–user–managed installation context. |
| **MSIINSTALLCONTEXT_USERUNMANAGED**<br><br>2 | Include applications installed in the per–user–unmanaged installation context. |
| **MSIINSTALLCONTEXT_MACHINE**<br><br>4 | Include applications installed in the per-machine installation context. When *dwInstallContext* is set to **MSIINSTALLCONTEXT_MACHINE** only, the *szUserSID* parameter must be **NULL**. |

### `lpOutPathBuffer` [out, optional]

A string value that receives the path to the component. This parameter can be **NULL**. If the component is a registry key, the registry roots are represented numerically. If this is a registry subkey path, there is a backslash at the end of the Key Path. If this is a registry value key path, there is no backslash at the end. For example, a registry path on a 32-bit operating system of **HKEY_CURRENT_USER**\**SOFTWARE**\**Microsoft** is returned as "01:\SOFTWARE\Microsoft\". The registry roots returned on 32-bit operating systems are defined as shown in the following table.

**Note** On 64-bit operating systems, a value of 20 is added to the numerical registry roots in this table to distinguish them from registry key paths on 32-bit operating systems.
For example, a registry key path of **HKEY_CURRENT_USER**\**SOFTWARE**\**Microsoft** is returned as "21:\SOFTWARE\Microsoft\", if the component path is a registry key on a 64-bit operating system.

| Root | Meaning |
| --- | --- |
| **HKEY_CLASSES_ROOT** | 00 |
| **HKEY_CURRENT_USER** | 01 |
| **HKEY_LOCAL_MACHINE** | 02 |
| **HKEY_USERS** | 03 |

### `pcchOutPathBuffer` [in, out, optional]

Pointer to a location that receives the size of the buffer, in **TCHAR**, pointed to by the *szPathBuf* parameter. The value in this location should be set to the count of **TCHAR** in the string including the terminating null character. If the size of the buffer is too small, this parameter receives the length of the string value without including the terminating null character in the count.

## Return value

The
**MsiGetComponentPathEx** function returns the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_NOTUSED** | The component being requested is disabled on the computer. |
| **INSTALLSTATE_BADCONFIG** | Configuration data is corrupt. |
| **INSTALLSTATE_ABSENT** | The component is not installed. |
| **INSTALLSTATE_INVALIDARG** | One of the function parameters is invalid. |
| **INSTALLSTATE_LOCAL** | The component is installed locally. |
| **INSTALLSTATE_SOURCE** | The component is installed to run from source. |
| **INSTALLSTATE_SOURCEABSENT** | The component source is inaccessible. |
| **INSTALLSTATE_UNKNOWN** | The product code or component ID is unknown. |
| **INSTALLSTATE_BROKEN** | The component is corrupt or partially missing in some way and requires repair. |

## Remarks

The
**MsiGetComponentPathEx** function might return **INSTALLSTATE_ABSENT** or **INSTALL_STATE_UNKNOWN**, for the following reasons:

* INSTALLSTATE_ABSENT

  The application did not properly ensure that the feature was installed by calling
  [MsiUseFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiusefeaturea) and, if necessary,
  [MsiConfigureFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigurefeaturea).
* INSTALLSTATE_UNKNOWN

  The feature is not published. The application should have determined this earlier by calling
  [MsiQueryFeatureState](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiqueryfeaturestatea) or
  [MsiEnumFeatures](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msienumfeaturesa). The application makes these calls while it initializes. An application should only use features that are known to be published. Since INSTALLSTATE_UNKNOWN should have been returned by
  [MsiUseFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiusefeaturea) as well, either
  **MsiUseFeature** was not called, or its return value was not properly checked.

> [!NOTE]
> The msi.h header defines MsiGetComponentPathEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Component-Specific Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)