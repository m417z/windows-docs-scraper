# MsiGetFeatureCostW function

## Description

The
**MsiGetFeatureCost** function returns the disk space required by a feature and its selected children and parent features.

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szFeature` [in]

Specifies the name of the feature.

### `iCostTree` [in]

Specifies the value the function uses to determine disk space requirements. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **MSICOSTTREE_CHILDREN** | The children of the indicated feature are included in the cost. |
| **MSICOSTTREE_PARENTS** | The parent features of the indicated feature are included in the cost. |
| **MSICOSTTREE_SELFONLY** | The feature only is included in the cost. |

### `iState` [in]

Specifies the installation state. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_UNKNOWN** | The product or feature is unrecognized. |
| **INSTALLSTATE_ABSENT** | The product or feature is uninstalled. |
| **INSTALLSTATE_LOCAL** | The product or feature is installed on the local drive. |
| **INSTALLSTATE_SOURCE** | The product or feature is installed to run from source, CD, or network. |
| **INSTALLSTATE_DEFAULT** | The product or feature will be installed to use the default location: local or source. |

### `piCost` [out]

Receives the disk space requirements in units of 512 bytes. This parameter must not be null.

## Return value

The
**MsiGetFeatureCost** function returns the following values:

## Remarks

See
[Calling Database Functions From Programs](https://learn.microsoft.com/windows/desktop/Msi/calling-database-functions-from-programs).

With the
**MsiGetFeatureCost** function, the MSICOSTTREE_SELFONLY value indicates the total amount of disk space (in units of 512 bytes) required by the specified feature only. This returned value does not include the children or the parent features of the specified feature. This total cost is made up of the disk costs attributed to every component linked to the feature.

The MSICOSTTREE_CHILDREN value indicates the total amount of disk space (in units of 512 bytes) required by the specified feature and its children. For each feature, the total cost is made up of the disk costs attributed to every component linked to the feature.

The MSICOSTTREE_PARENTS value indicates the total amount of disk space (in units of 512 bytes) required by the specified feature and its parent features (up to the root of the
[Feature table](https://learn.microsoft.com/windows/desktop/Msi/feature-table)). For each feature, the total cost is made up of the disk costs attributed to every component linked to the feature.

**MsiGetFeatureCost** is dependent upon several other functions to be successful. The following example demonstrates the order in which these functions must be called:

``` syntax
MSIHANDLE   hInstall;      //product handle, must be closed
int         iCost;         //cost returned by MsiGetFeatureCost

MsiOpenPackage("Path to package....",&hInstall);   //"Path to package...." should be replaced with the full path to the package to be opened
MsiDoAction(hInstall,"CostInitialize");         //
MsiDoAction(hInstall,"FileCost");
MsiDoAction(hInstall,"CostFinalize");
MsiDoAction(hInstall,"InstallValidate");
MsiGetFeatureCost(hInstall,"FeatureName",MSICOSTTREE_SELFONLY,INSTALLSTATE_ABSENT,&iCost);
MsiCloseHandle(hInstall);                        //close the open product handle
```

The process to query the cost of features scheduled to be removed is slightly different:

``` syntax
MSIHANDLE   hInstall;      //product handle, must be closed
int         iCost;         //cost returned by MsiGetFeatureCost

MsiOpenPackage("Path to package....",&hInstall);              //"Path to package...." should be replaced with the full path to the package to be opened
MsiDoAction(hInstall,"CostInitialize");                          //
MsiDoAction(hInstall,"FileCost");
MsiDoAction(hInstall,"CostFinalize");
MsiSetFeatureState(hInstall,"FeatureName",INSTALLSTATE_ABSENT);  //set the feature's state to "not installed"
MsiDoAction(hInstall,"InstallValidate");
MsiGetFeatureCost(hInstall,"FeatureName",MSICOSTTREE_SELFONLY,INSTALLSTATE_ABSENT,&iCost);
MsiCloseHandle(hInstall);                                        //close the open product handle
```

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

> [!NOTE]
> The msiquery.h header defines MsiGetFeatureCost as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installer Selection Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Passing Null as the Argument of Windows Installer Functions](https://learn.microsoft.com/windows/desktop/Msi/passing-null-as-the-argument-of-windows-installer-functions)