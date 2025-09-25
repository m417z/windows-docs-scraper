# MsiCreateTransformSummaryInfoW function

## Description

The
**MsiCreateTransformSummaryInfo** function creates summary information of an existing transform to include validation and error conditions. Execution of this function sets the error record, which is accessible by using
[MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

## Parameters

### `hDatabase` [in]

The handle to the database that contains the new database summary information.

### `hDatabaseReference` [in]

The handle to the database that contains the original summary information.

### `szTransformFile` [in]

The name of the transform to which the summary information is added.

### `iErrorConditions` [in]

The error conditions that should be suppressed when the transform is applied. Use one or more of the following values.

| Error condition | Meaning |
| --- | --- |
| **none**<br><br>0x00000000 | None of the following conditions. |
| **MSITRANSFORM_ERROR_ADDEXISTINGROW**<br><br>0x00000001 | Adding a row that exists. |
| **MSITRANSFORM_ERROR_DELMISSINGROW**<br><br>0x00000002 | Deleting a row that does not exist. |
| **MSITRANSFORM_ERROR_ADDEXISTINGTABLE**<br><br>0x00000004 | Adding a table that exists. |
| **MSITRANSFORM_ERROR_DELMISSINGTABLE**<br><br>0x00000008 | Deleting a table that does not exist. |
| **MSITRANSFORM_ERROR_UPDATEMISSINGROW**<br><br>0x00000010 | Updating a row that does not exist. |
| **MSITRANSFORM_ERROR_CHANGECODEPAGE**<br><br>0x00000020 | Transform and database code pages do not match, and their code pages are neutral. |

### `iValidation` [in]

Specifies the properties to be validated to verify that the transform can be applied to the database. This parameter can be one or more of the following values.

| Validation flag | Meaning |
| --- | --- |
| **none**<br><br>0x00000000 | Do not validate properties. |
| **MSITRANSFORM_VALIDATE_LANGUAGE**<br><br>0x00000001 | Default language must match base database. |
| **MSITRANSFORM_VALIDATE_PRODUCT**<br><br>0x00000002 | Product must match base database. |

Validate product version flags.

| Validation flag | Meaning |
| --- | --- |
| **MSITRANSFORM_VALIDATE_MAJORVERSION**<br><br>0x00000008 | Check major version only. |
| **MSITRANSFORM_VALIDATE_MINORVERSION**<br><br>0x00000010 | Check major and minor versions only. |
| **MSITRANSFORM_VALIDATE_UPDATEVERSION**<br><br>0x00000020 | Check major, minor, and update versions. |

Product version relationship flags. In the following table the installed version is the version of the package that is being transformed, and the base version is the version of the package that is used to create the transform.

| Validation flag | Meaning |
| --- | --- |
| **MSITRANSFORM_VALIDATE_NEWLESSBASEVERSION**<br><br>0x00000040 | Installed version < base version. |
| **MSITRANSFORM_VALIDATE_NEWLESSEQUALBASEVERSION**<br><br>0x00000080 | Installed version <= base version. |
| **MSITRANSFORM_VALIDATE_NEWEQUALBASEVERSION**<br><br>0x00000100 | Installed version = base version. |
| **MSITRANSFORM_VALIDATE_NEWGREATEREQUALBASEVERSION**<br><br>0x00000200 | Installed version >= base version. |
| **MSITRANSFORM_VALIDATE_NEWGREATERBASEVERSION**<br><br>0x00000400 | Installed version > base version. |

Upgrade code validation flags.

| Validation flag | Meaning |
| --- | --- |
| **MSITRANSFORM_VALIDATE_UPGRADECODE**<br><br>0x00000800 | UpgradeCode must match base database. |

## Return value

This function returns UINT.

## Remarks

The [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) Property and
[ProductVersion](https://learn.microsoft.com/windows/desktop/Msi/productversion) Property must be defined in the
[Property Table](https://learn.microsoft.com/windows/desktop/Msi/property-table) of both the base and reference databases. If MSITRANSFORM_VALIDATE_UPGRADECODE is used, the
[UpgradeCode](https://learn.microsoft.com/windows/desktop/Msi/upgradecode) Property must also be defined in both databases. If these conditions are not met,
**MsiCreateTransformSummaryInfo** returns ERROR_INSTALL_PACKAGE_INVALID.

* Do not use the semicolon for filenames or paths, because it is used as a list delimiter for transforms, sources, and patches.
* This function cannot be called from custom actions. A call to this function from a custom action causes the function to fail.

> [!NOTE]
> The msiquery.h header defines MsiCreateTransformSummaryInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Database Transforms](https://learn.microsoft.com/windows/desktop/Msi/database-transforms)

[Summary Information Stream Property Set](https://learn.microsoft.com/windows/desktop/Msi/summary-information-stream-property-set)