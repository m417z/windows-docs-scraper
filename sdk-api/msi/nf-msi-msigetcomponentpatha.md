# MsiGetComponentPathA function

## Description

The
**MsiGetComponentPath** function returns the full path to an installed component. If the key path for the component is a registry key then the registry key is returned.

## Parameters

### `szProduct` [in]

Specifies the product code for the client product.

### `szComponent` [in]

Specifies the component ID of the component to be located.

### `lpPathBuf` [out]

Pointer to a variable that receives the path to the component. This parameter can be null. If the component is a registry key, the registry roots are represented numerically. If this is a registry subkey path, there is a backslash at the end of the Key Path. If this is a registry value key path, there is no backslash at the end. For example, a registry path on a 32-bit operating system of **HKEY_CURRENT_USER**\**SOFTWARE**\**Microsoft** is returned as "01:\SOFTWARE\Microsoft\". The registry roots returned on 32-bit operating systems are defined as shown in the following table.

**Note** On 64-bit operating systems, a value of 20 is added to the numerical registry roots in this table to distinguish them from registry key paths on 32-bit operating systems.
For example, a registry key path of **HKEY_CURRENT_USER**\**SOFTWARE**\**Microsoft** is returned as "21:\SOFTWARE\Microsoft\", if the component path is a registry key on a 64-bit operating system.

| Root | Meaning |
| --- | --- |
| **HKEY_CLASSES_ROOT** | 00 |
| **HKEY_CURRENT_USER** | 01 |
| **HKEY_LOCAL_MACHINE** | 02 |
| **HKEY_USERS** | 03 |

### `pcchBuf` [in, out]

Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the *lpPathBuf* parameter. On input, this is the full size of the buffer, including a space for a terminating null character. If the buffer passed in is too small, the count returned does not include the terminating null character.

If *lpPathBuf* is null, *pcchBuf* can be null.

## Return value

The
**MsiGetComponentPath** function returns the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_NOTUSED** | The component being requested is disabled on the computer. |
| **INSTALLSTATE_ABSENT** | The component is not installed. |
| **INSTALLSTATE_INVALIDARG** | One of the function parameters is invalid. |
| **INSTALLSTATE_LOCAL** | The component is installed locally. |
| **INSTALLSTATE_SOURCE** | The component is installed to run from source. |
| **INSTALLSTATE_SOURCEABSENT** | The component source is inaccessible. |
| **INSTALLSTATE_UNKNOWN** | The product code or component ID is unknown. |

## Remarks

Upon success of the
**MsiGetComponentPath** function, the *pcchBuf* parameter contains the length of the string in *lpPathBuf*.

The
**MsiGetComponentPath** function might return INSTALLSTATE_ABSENT or INSTALL_STATE_UNKNOWN, for the following reasons:

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
> The msi.h header defines MsiGetComponentPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Component-Specific Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)