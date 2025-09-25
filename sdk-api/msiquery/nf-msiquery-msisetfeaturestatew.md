# MsiSetFeatureStateW function

## Description

The
**MsiSetFeatureState** function sets a feature to a specified state.

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szFeature` [in]

Specifies the name of the feature.

### `iState` [in]

Specifies the state to set. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_ABSENT** | The feature is not installed. |
| **INSTALLSTATE_LOCAL** | The feature is installed on the local drive. |
| **INSTALLSTATE_SOURCE** | The feature is run from the source, CD, or network. |
| **INSTALLSTATE_ADVERTISED** | The feature is advertised. |

## Return value

The
**MsiSetFeatureState** function returns the following values:

## Remarks

The
**MsiSetFeatureState** function requests a change in the select state of a feature in the
[Feature](https://learn.microsoft.com/windows/desktop/Msi/feature-table) table and its children. In turn, the action state of all the components linked to the changed feature records are also updated appropriately, based on the new feature select state.

The
[MsiSetInstallLevel](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msisetinstalllevel) function must be called before calling
**MsiSetFeatureState**.

When **MsiSetFeatureState** is called, the installer attempts to set the action state of each component tied to the specified feature to the specified state. However, there are common situations when the request cannot be fully implemented. For example, if a feature is tied to two components, component A and component B, through the [FeatureComponents](https://learn.microsoft.com/windows/desktop/Msi/featurecomponents-table) table, and component A has the **msidbComponentAttributesLocalOnly** attribute and component B has the **msidbComponentAttributesSourceOnly** attribute. In this case, if **MsiSetFeatureState** is called with a requested state of either INSTALLSTATE_LOCAL or INSTALLSTATE_SOURCE, the request cannot be fully implemented for both components. In this case, both components are turned ON, with component A set to Local and component B set to Source.

If more than one feature is linked to a single component (a common scenario), the final action state of that component is determined as follows:

* If at least one feature requires the component to be installed locally, the feature is installed with a state of local.
* If at least one feature requires the component to be run from the source, the feature is installed with a state of source.
* If at least one feature requires the removal of the component, the action state is absent.

See
[Calling Database Functions from Programs](https://learn.microsoft.com/windows/desktop/Msi/calling-database-functions-from-programs).

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

> [!NOTE]
> The msiquery.h header defines MsiSetFeatureState as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installer Selection Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)