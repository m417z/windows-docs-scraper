# MsiGetFeatureValidStatesW function

## Description

The
**MsiGetFeatureValidStates** function returns a valid installation state.

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szFeature` [in]

Specifies the feature name.

### `lpInstallStates` [out]

Receives the location to hold the valid installation states. For each valid installation state, the installer sets *pInstallState* to a combination of the following values. This parameter should not be null.

| Decimal Value | Meaning |
| --- | --- |
| **2**<br><br>INSTALLSTATE_ADVERTISED | The feature can be advertised. |
| **4**<br><br>INSTALLSTATE_ABSENT | The feature can be absent. |
| **8**<br><br>INSTALLSTATE_LOCAL | The feature can be installed on the local drive. |
| **16**<br><br>INSTALLSTATE_SOURCE | The feature can be configured to run from source, CD-ROM, or network. |
| **32**<br><br>INSTALLSTATE_DEFAULT | The feature can be configured to use the default location: local or source. |

## Return value

The
**MsiGetFeatureValidStates** function returns the following values:

## Remarks

See
[Calling Database Functions From Programs](https://learn.microsoft.com/windows/desktop/Msi/calling-database-functions-from-programs).

The **MsiGetFeatureValidStates** function determines state validity by querying all components that are linked to the specified feature without taking into account the current installed state of any component.

The possible valid states for a feature are determined as follows:

* If the feature does not contain components, both INSTALLSTATE_LOCAL and INSTALLSTATE_SOURCE are valid states for the feature.
* If at least one component of the feature has an attribute of msidbComponentAttributesLocalOnly or msidbComponentAttributesOptional, INSTALLSTATE_LOCAL is a valid state for the feature.
* If at least one component of the feature has an attribute of msidbComponentAttributesSourceOnly or msidbComponentAttributesOptional, INSTALLSTATE_SOURCE is a valid state for the feature.
* If a file of a component that belongs to the feature is patched or from a compressed source, then INSTALLSTATE_SOURCE is not included as a valid state for the feature.
* INSTALLSTATE_ADVERTISE is not a valid state if the feature disallows advertisement (msidbFeatureAttributesDisallowAdvertise) or the feature requires platform support for advertisement (msidbFeatureAttributesNoUnsupportedAdvertise) and the platform does not support it.
* INSTALLSTATE_ABSENT is a valid state for the feature if its attributes do not include msidbFeatureAttributesUIDisallowAbsent.
* Valid states for child features marked to follow the parent feature (msidbFeatureAttributesFollowParent) are based upon the parent feature's action or installed state.

After calling
**MsiGetFeatureValidStates** a conditional statement may then be used to test the valid installation states of a feature. For example, the following call to
**MsiGetFeatureValidStates** gets the installation state of Feature1.

``` syntax
MsiGetFeatureValidStates(hProduct, "Feature1", &dwValidStates);
```

If Feature1 has attributes of value 0 (favor local), and Feature1 has one component with attributes of value 0 (local only), the value of dwValidStates after the call is 14. This indicates that INSTALLSTATE_LOCAL, INSTALLSTATE_ABSENT,and INSTALLSTATE_ADVERTISED are valid states for Feature1. The following conditional statement evaluates to True if local is a valid state for this feature.

( ( dwValidStates & ( 1 << INSTALLSTATE_LOCAL ) ) == ( 1 << INSTALLSTATE_LOCAL ) )

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

> [!NOTE]
> The msiquery.h header defines MsiGetFeatureValidStates as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installer Selection Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Passing Null as the Argument of Windows Installer Functions](https://learn.microsoft.com/windows/desktop/Msi/passing-null-as-the-argument-of-windows-installer-functions)