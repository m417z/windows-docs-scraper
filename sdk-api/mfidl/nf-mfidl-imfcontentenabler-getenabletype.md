# IMFContentEnabler::GetEnableType

## Description

Retrieves the type of operation that this content enabler performs.

## Parameters

### `pType` [out]

Receives a GUID that identifies the type of operation. An application can tailor its user interface (UI) strings for known operation types. See Remarks.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The following GUIDs are defined for the *pType* parameter.

| Value | Description |
| --- | --- |
| MFENABLETYPE_MF_RebootRequired | The user must reboot his or her computer. |
| MFENABLETYPE_MF_UpdateRevocationInformation | Update revocation information. |
| MFENABLETYPE_MF_UpdateUntrustedComponent | Update untrusted components. |
| MFENABLETYPE_WMDRMV1_LicenseAcquisition | License acquisition for Windows Media Digital Rights Management (DRM) version 1. |
| MFENABLETYPE_WMDRMV7_Individualization | Individualization. |
| MFENABLETYPE_WMDRMV7_LicenseAcquisition | License acquisition for Windows Media DRM version 7 or later. |

## See also

[How to Play Protected Media Files](https://learn.microsoft.com/windows/desktop/medfound/how-to-play-protected-media-files)

[IMFContentEnabler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentenabler)