# IMFProtectedEnvironmentAccess::Call

## Description

Allows content protection systems to access the protected environment.

## Parameters

### `inputLength`

The length in bytes of the input data.

### `input`

A pointer to the input data.

### `outputLength`

The length in bytes of the output data.

### `output`

A pointer to the output data.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

See [MFCreateProtectedEnvironmentAccess](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreateprotectedenvironmentaccess) for an example of how to create an [IMFProtectedEnvironmentAccess](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfprotectedenvironmentaccess) object and use the **Call** method.

## See also

[IMFProtectedEnvironmentAccess](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfprotectedenvironmentaccess)

[MFCreateProtectedEnvironmentAccess](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreateprotectedenvironmentaccess)