# PathMakeUniqueName function

## Description

Creates a unique path name from a template.

## Parameters

### `pszUniqueName` [out]

Type: **PWSTR**

A buffer that receives a null-terminated Unicode string that contains the unique path name. It should be at least MAX_PATH characters in length.

### `cchMax`

Type: **UINT**

The number of characters in the buffer pointed to by *pszUniqueName*.

### `pszTemplate` [in]

Type: **PCWSTR**

A null-terminated Unicode string that contains a template that is used to construct the unique name. This template is used for drives that require file names with the 8.3 format. This string should be no more than MAX_PATH characters in length, including the terminating null character.

### `pszLongPlate` [in, optional]

Type: **PCWSTR**

A null-terminated Unicode string that contains a template that is used to construct the unique name. This template is used for drives that support long file names. This string should be no more than MAX_PATH characters in length, including the terminating null character.

### `pszDir` [in, optional]

Type: **PCWSTR**

A null-terminated string that contains the directory in which the new file resides. This string should be no more than MAX_PATH characters in length, including the terminating null character.

## Return value

Type: **BOOL**

Returns **TRUE** if successful; otherwise, **FALSE**.

## Remarks

This function generates a new unique file name based on the templates specified by *pszTemplate*, for drives that require the 8.3 format, and *pszLongPlate* for drives that support long file names. For example, if you specify "My New Filename" for *pszLongPlate*, **PathMakeUniqueName** returns names such as "My New Filename (1)", "My New Filename (2)", and so on.