# MsiSetFeatureAttributesW function

## Description

The
**MsiSetFeatureAttributes** function can modify the default attributes of a feature at runtime. Note that the default attributes of features are authored in the Attributes column of the
[Feature table](https://learn.microsoft.com/windows/desktop/Msi/feature-table).

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szFeature` [in]

Specifies the feature name within the product.

### `dwAttributes` [in]

Feature attributes specified at run time as a set of bit flags:

| Constant | Meaning |
| --- | --- |
| **INSTALLFEATUREATTRIBUTE_FAVORLOCAL**<br><br>1 | Modifies default feature attributes to msidbFeatureAttributesFavorLocal at run time. See Attributes column of the [Feature table](https://learn.microsoft.com/windows/desktop/Msi/feature-table) for a description. |
| **INSTALLFEATUREATTRIBUTE_FAVORSOURCE**<br><br>2 | Modifies default feature attributes to msidbFeatureAttributesFavorSource at run time. See Attributes column of the [Feature table](https://learn.microsoft.com/windows/desktop/Msi/feature-table) for a description. |
| **INSTALLFEATUREATTRIBUTE_FOLLOWPARENT**<br><br>4 | Modifies default feature attributes to msidbFeatureAttributesFollowParent at run time. Note that this is not a valid attribute to be set for top-level features. See Attributes column of the [Feature table](https://learn.microsoft.com/windows/desktop/Msi/feature-table) for a description. |
| **INSTALLFEATUREATTRIBUTE_FAVORADVERTISE**<br><br>8 | Modifies default feature attributes to msidbFeatureAttributesFavorAdvertise at run time. See Attributes column of the [Feature table](https://learn.microsoft.com/windows/desktop/Msi/feature-table) for a description. |
| **INSTALLFEATUREATTRIBUTE_DISALLOWADVERTISE**<br><br>16 | Modifies default feature attributes to msidbFeatureAttributesDisallowAdvertise at run time. See Attributes column of the [Feature table](https://learn.microsoft.com/windows/desktop/Msi/feature-table) for a description. |
| **INSTALLFEATUREATTRIBUTE_NOUNSUPPORTEDADVERTISE**<br><br>32 | Modifies default feature attributes to msidbFeatureAttributesNoUnsupportedAdvertise at run time. See Attributes column of the [Feature table](https://learn.microsoft.com/windows/desktop/Msi/feature-table) for a description. |

## Return value

This function returns UINT.

## Remarks

**MsiSetFeatureAttributes** must be called after
[CostInitialize action](https://learn.microsoft.com/windows/desktop/Msi/costinitialize-action) and before
[CostFinalize action](https://learn.microsoft.com/windows/desktop/Msi/costfinalize-action). The function returns ERROR_FUNCTION_FAILED if called at any other time.

The INSTALLFEATUREATTRIBUTE_FAVORLOCAL, INSTALLFEATUREATTRIBUTE_FAVORSOURCE, and INSTALLFEATUREATTRIBUTE_FOLLOWPARENT flags are mutually exclusive. Only one of these bits can be set for any feature. If more than one of these flags is set, the behavior of that feature is undefined.

See
[Calling Database Functions From Programs](https://learn.microsoft.com/windows/desktop/Msi/calling-database-functions-from-programs).

> [!NOTE]
> The msiquery.h header defines MsiSetFeatureAttributes as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).