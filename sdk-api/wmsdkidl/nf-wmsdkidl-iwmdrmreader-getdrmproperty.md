# IWMDRMReader::GetDRMProperty

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**GetDRMProperty** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **GetDRMProperty** method retrieves DRM-specific file attributes and run-time properties.

## Parameters

### `pwstrName` [in]

Specifies the property or file attribute to retrieve.

### `pdwType` [out]

Pointer that receives the data type of the returned value.

### `pValue` [out]

Pointer to the value requested in *pwstrName*.

### `pcbLength` [out]

Size of *pValue*, in bytes.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

This method can be used to retrieve both DRM header attributes and DRM license information for the current file. DRM-related constants are defined in drmexternals.idl and wmsdkidl.idl.

If you specify a "license state" constant, the returned data is a pointer to a [WM_LICENSE_STATE_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd757942(v=vs.85)) structure that fully describes the terms of the license for the particular right. The supported license state constants are described in the following table.

| Constant | Literal string value | Description |
| --- | --- | --- |
| g_wszWMDRM_LicenseState_CollaborativePlay | "LicenseStateData.CollaborativePlay" | License restrictions on playing the file as part of a collaborative peer-to-peer networking scenario. |
| g_wszWMDRM_LicenseState_Copy | "LicenseStateData.Copy" | License restrictions on copying the file to a device. |
| g_wszWMDRM_LicenseState_CopyToCD | "LicenseStateData.Print.redbook" | License restrictions on copying the file to CD.For DRM version 10 licenses, use g_wszWMDRM_LicenseState_Copy for all copy actions. |
| g_wszWMDRM_LicenseState_CopyToNonSDMIDevice | "LicenseStateData.Transfer.NONSDMI" | License restrictions on copying the file to a non-SMDI device.For DRM version 10 licenses, use g_wszWMDRM_LicenseState_Copy for all copy actions. |
| g_wszWMDRM_LicenseState_CopyToSDMIDevice | "LicenseStateData.Transfer.SDMI" | License restrictions on copying the file to an [SDMI](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) device.For DRM version 10 licenses, use g_wszWMDRM_LicenseState_Copy for all copy actions. |
| g_wszWMDRM_LicenseState_Playback | "LicenseStateData.Play" | License restrictions on playing the file. |
| g_wszWMDRM_LicenseState_PlaylistBurn | "LicenseStateData.PlaylistBurn" | License restrictions on copying the file to Red Book audio CD as part of a playlist. |

If you specify an "action allowed" constant, the returned data is a Boolean that indicates whether a specified action is allowed at this time. The supported constants are:

| Constant | Literal string value | Description |
| --- | --- | --- |
| g_wszWMDRM_ActionAllowed_Backup | "ActionAllowed.Backup" | Right to back up the file now. |
| g_wszWMDRM_ActionAllowed_CollaborativePlay | "ActionAllowed.CollaborativePlay" | Right to play the file as part of a collaborative peer-to-peer networking scenario. |
| g_wszWMDRM_ActionAllowed_Copy | "ActionAllowed.Copy" | Right to copy the file to a device. |
| g_wszWMDRM_ActionAllowed_CopyToCD | "ActionAllowed.Print.redbook" | Right to copy file to CD.For DRM version 10 licenses, check g_wszWMDRM_ActionAllowed_Copy for all copy actions. |
| g_wszWMDRM_ActionAllowed_CopyToSDMIDevice | "ActionAllowed.Transfer.SDMI" | Right to copy file to an SDMI device.For DRM version 10 licenses, check g_wszWMDRM_ActionAllowed_Copy for all copy actions. |
| g_wszWMDRM_ActionAllowed_CopyToNonSDMIDevice | "ActionAllowed.Transfer.NONSDMI" | Right to copy file to a non-SMDI device.For DRM version 10 licenses, check g_wszWMDRM_ActionAllowed_Copy for all copy actions. |
| g_wszWMDRM_ActionAllowed_Playback | "ActionAllowed.Play" | Right to play file. |
| g_wszWMDRM_ActionAllowed_PlaylistBurn | "ActionAllowed.PlaylistBurn" | Right to copy the file to Red Book audio CD as part of a playlist. |

If you specify a "DRM Header" constant, the returned value is the string literal for the specified property. The supported DRM Header constants are:

| Constant | Literal string value | Description |
| --- | --- | --- |
| g_wszWMDRM_DRMHeader_KeyID | "DRMHeader.KID" | DRM key value. |
| g_wszWMDRM_DRMHeader_LicenseAcqURL | "DRMHeader.LAINFO" | DRM license acquisition URL. |
| g_wszWMDRM_DRMHeader_ContentID | "DRMHeader.CID" | DRM content ID. |
| g_wszWMDRM_DRMHeader_IndividualizedVersion | "DRMHeader.SECURITYVERSION" | Individualized version. |
| g_wszWMDRM_DRMHeader_ContentDistributor | "DRMHeader.ContentDistributor" | Content distributor. |
| g_wszWMDRM_DRMHeader_SubscriptionContentID | "DRMHeader.SubscriptionContentID" | Subscription content ID. |

Before calling this method on a new file, always call the helper function [WMIsContentProtected](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-wmiscontentprotected) to ensure that the file is protected with DRM. It is important to do this because in some cases this method might succeed when called on unprotected content.

## See also

[DRM Attribute List](https://learn.microsoft.com/windows/desktop/wmformat/drm-attribute-list)

[DRM Properties](https://learn.microsoft.com/windows/desktop/wmformat/drm-properties)

[IWMDRMEditor::GetDRMProperty](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmeditor-getdrmproperty)

[IWMDRMReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmreader)

[IWMDRMReader::SetDRMProperty](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmreader-setdrmproperty)

[WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype)