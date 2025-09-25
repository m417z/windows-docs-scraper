# MFCreatePMPServer function

## Description

Creates the protected media path (PMP) server object.

## Parameters

### `dwCreationFlags` [in]

A member of the [MFPMPSESSION_CREATION_FLAGS](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfpmpsession_creation_flags) enumeration that specifies how to create the PMP session.

### `ppPMPServer` [out]

Receives a pointer to the [IMFPMPServer](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpmpserver) interface. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)