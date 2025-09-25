# IMFSignedLibrary::GetProcedureAddress

## Description

Gets the procedure address of the specified function in the signed library.

## Parameters

### `name`

The entry point name in the DLL that specifies the function.

### `address`

Receives the address of the entry point.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

See [MFLoadSignedLibrary](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfloadsignedlibrary) for an example of how to create an [IMFSignedLibrary](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsignedlibrary) object and call the **GetProcedureAddress** method.

## See also

[IMFSignedLibrary](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsignedlibrary)

[MFLoadSignedLibrary](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfloadsignedlibrary)