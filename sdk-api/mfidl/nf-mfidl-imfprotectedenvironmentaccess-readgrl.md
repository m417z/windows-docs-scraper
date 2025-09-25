# IMFProtectedEnvironmentAccess::ReadGRL

## Description

Gets the Global Revocation List (GLR).

## Parameters

### `outputLength`

The length of the data returned in **output**.

### `output`

Receives the contents of the global revocation list file.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Allows reading of the system Global Revocation List (GRL).

## See also

[IMFProtectedEnvironmentAccess](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfprotectedenvironmentaccess)