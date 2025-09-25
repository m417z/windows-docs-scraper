# ICertSrvSetup::SetDatabaseInformation

## Description

The **SetDatabaseInformation** method sets the database related information for the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) role.

## Parameters

### `bstrDBDirectory` [in]

A string that contains the name of the directory where the CA database files will be stored. This parameter must not be **NULL** or an empty string.

### `bstrLogDirectory` [in]

A string that contains the name of the directory where the CA database log files will be stored. This parameter must not be **NULL** or an empty string.

### `bstrSharedFolder` [in]

This parameter is reserved for future use and must be **NULL** or an empty string.

### `bForceOverwrite` [in]

A value that indicates whether to overwrite any existing database files in the specified directory. A value of **VARIANT_TRUE** specifies to overwrite existing files.

## Remarks

The **SetDatabaseInformation** method creates the specified directories if they do not exist.

Upon failure, the **SetDatabaseInformation** method might set additional error information in the [CAErrorId](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertsrvsetup-get_caerrorid) and [CAErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertsrvsetup-get_caerrorstring) properties.

## See also

[ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup)