# MFCreateASFProfileFromPresentationDescriptor function

## Description

Creates an ASF profile object from a presentation descriptor.

## Parameters

### `pIPD`

Pointer to the [IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor) interface of the presentation descriptor that contains the profile information.

### `ppIProfile`

Receives a pointer to the [IMFASFProfile](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfprofile) interface. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)