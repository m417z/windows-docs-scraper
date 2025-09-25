# DSEditSecurity function

## Description

The **DSEditSecurity** function displays a modal dialog box for editing security on a Directory Services (DS) object.

## Parameters

### `hwndOwner` [in]

The dialog box owner window.

### `pwszObjectPath` [in]

The full Active Directory Services (ADS) path of the DS object.

### `pwszObjectClass` [in, optional]

The class of the object.

### `dwFlags` [in]

The combination of DSSI_* flags.

### `pwszCaption` [in, optional]

The dialog box caption.

### `pfnReadSD` [in, optional]

The function for reading the object.

### `pfnWriteSD` [in, optional]

The function for writing the object.

### `lpContext` [in]

The context passed into the read or write functions in the *pfnReadSD* and *pfnWriteSD* parameters.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).