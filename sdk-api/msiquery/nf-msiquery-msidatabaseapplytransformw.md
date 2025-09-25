# MsiDatabaseApplyTransformW function

## Description

The
**MsiDatabaseApplyTransform** function applies a transform to a database.

## Parameters

### `hDatabase` [in]

Handle to the database obtained from [MsiOpenDatabase](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiopendatabasea) to the transform.

### `szTransformFile` [in]

Specifies the name of the transform file to apply.

### `iErrorConditions` [in]

Error conditions that should be suppressed. This parameter is a bit field that can contain the following bits.

| Error condition | Meaning |
| --- | --- |
| **MSITRANSFORM_ERROR_ADDEXISTINGROW**<br><br>0x0001 | Adding a row that already exists. |
| **MSITRANSFORM_ERROR_DELMISSINGROW**<br><br>0x0002 | Deleting a row that does not exist. |
| **MSITRANSFORM_ERROR_ADDEXISTINGTABLE**<br><br>0x0004 | Adding a table that already exists. |
| **MSITRANSFORM_ERROR_DELMISSINGTABLE**<br><br>0x0008 | Deleting a table that does not exist. |
| **MSITRANSFORM_ERROR_UPDATEMISSINGROW**<br><br>0x0010 | Updating a row that does not exist. |
| **MSITRANSFORM_ERROR_CHANGECODEPAGE**<br><br>0x0020 | Transform and database code pages do not match and neither has a neutral code page. |
| **MSITRANSFORM_ERROR_VIEWTRANSFORM**<br><br>0x0100 | Create the temporary [_TransformView table](https://learn.microsoft.com/windows/desktop/Msi/-transformview-table). |

## Return value

The
**MsiDatabaseApplyTransform** function returns one of the following values:

## Remarks

The
**MsiDatabaseApplyTransform** function delays transforming tables until it is necessary. Any tables to be added or dropped are processed immediately. However, changes to the existing table are delayed until the table is loaded or the database is committed.

An error occurs if
**MsiDatabaseApplyTransform** is called when tables have already been loaded and saved to storage.

Because the list delimiter for transforms, sources and patches is a semicolon, this character should not be used for filenames or paths.

This function cannot be called from custom actions. A call to this function from a custom action causes the function to fail.

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

> [!NOTE]
> The msiquery.h header defines MsiDatabaseApplyTransform as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Database Management Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Database Transforms](https://learn.microsoft.com/windows/desktop/Msi/database-transforms)