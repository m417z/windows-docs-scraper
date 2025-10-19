# MFRequireProtectedEnvironment function

## Description

Queries whether a media presentation requires the Protected Media Path (PMP).

## Parameters

### `pPresentationDescriptor` [in]

Pointer to the [IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor) interface of a presentation descriptor. The presentation descriptor is created by the media source, and describes the presentation.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | This presentation requires a protected environment. |
| **S_FALSE** | This presentation does not require a protected environment. |

## Remarks

If this function returns **S_OK**, it means the PMP is required for this presentation. Call [MFCreatePMPMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatepmpmediasession) to create the PMP session object.

If the function returns **S_FALSE**, you can use the unprotected pipeline. Call [MFCreateMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatemediasession) to create the regular Media Session object.

Internally, this function checks whether any of the stream descriptors in the presentation have the [MF_SD_PROTECTED](https://learn.microsoft.com/windows/desktop/medfound/mf-sd-protected-attribute) attribute with the value **TRUE**.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)