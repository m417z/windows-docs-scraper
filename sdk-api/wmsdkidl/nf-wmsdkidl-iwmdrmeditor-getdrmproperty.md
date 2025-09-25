# IWMDRMEditor::GetDRMProperty

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**GetDRMProperty** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **GetDRMProperty** method retrieves the specified [DRM](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) property.

## Parameters

### `pwstrName` [in]

Specifies the DRM file attribute to retrieve.

### `pdwType` [out]

Pointer that receives the data type of the returned value.

### `pValue` [out]

Pointer to the value requested in *pwstrName*.

### `pcbLength` [out]

Length of *pValue* in bytes.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

This method retrieves only DRM properties listed below. The file must first be opened using [IWMMetadataEditor::Open](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmetadataeditor-open) or [IWMMetadataEditor2::OpenEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmetadataeditor2-openex).

Also, before calling **GetDRMProperty** on an opened file, always call the helper function [WMIsContentProtected](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-wmiscontentprotected) to ensure that the file is protected with DRM. It is important to do this because in some cases this method might succeed when called on unprotected content.

The following properties are accessible from this method:

* [DRM_IsDRM](https://learn.microsoft.com/windows/desktop/wmformat/drm-isdrm)
* [DRM_IsDRMCached](https://learn.microsoft.com/windows/desktop/wmformat/drm-isdrmcached)
* [DRM_BaseLicenseAcqURL](https://learn.microsoft.com/windows/desktop/wmformat/drm-baselicenseacqurl)
* [DRM_Rights](https://learn.microsoft.com/windows/desktop/wmformat/drm-rights)
* [DRM_LicenseID](https://learn.microsoft.com/windows/desktop/wmformat/drm-licenseid)
* [DRM_ActionAllowed_Playback](https://learn.microsoft.com/windows/desktop/wmformat/drm-actionallowed-playback)
* [DRM_ActionAllowed_CopyToCD](https://learn.microsoft.com/windows/desktop/wmformat/drm-actionallowed-copytocd)
* [DRM_ActionAllowed_CopyToSDMIDevice](https://learn.microsoft.com/windows/desktop/wmformat/drm-actionallowed-copytosdmidevice)
* [DRM_ActionAllowed_CopyToNonSDMIDevice](https://learn.microsoft.com/windows/desktop/wmformat/drm-actionallowed-copytononsdmidevice)
* [DRM_ActionAllowed_Backup](https://learn.microsoft.com/windows/desktop/wmformat/drm-actionallowed-backup)
* [DRM_DRMHeader_KeyID](https://learn.microsoft.com/windows/desktop/wmformat/drm-drmheader-keyid)
* [DRM_DRMHeader_LicenseAcqURL](https://learn.microsoft.com/windows/desktop/wmformat/drm-drmheader-licenseacqurl)
* [DRM_DRMHeader_ContentID](https://learn.microsoft.com/windows/desktop/wmformat/drm-drmheader-contentid)
* [DRM_DRMHeader_IndividualizedVersion](https://learn.microsoft.com/windows/desktop/wmformat/drm-drmheader-individualizedversion)
* [DRM_DRMHeader_ContentDistributor](https://learn.microsoft.com/windows/desktop/wmformat/drm-drmheader-contentdistributor)
* [DRM_DRMHeader_SubscriptionContentID](https://learn.microsoft.com/windows/desktop/wmformat/drm-drmheader-subscriptioncontentid)
* [DRM_LicenseState_Playback](https://learn.microsoft.com/windows/desktop/wmformat/drm-licensestate-playback)
* [DRM_LicenseState_CopyToCD](https://learn.microsoft.com/windows/desktop/wmformat/drm-licensestate-copytocd)
* [DRM_LicenseState_CopyToSDMIDevice](https://learn.microsoft.com/windows/desktop/wmformat/drm-licensestate-copytosdmidevice)
* [DRM_LicenseState_CopyToNonSDMIDevice](https://learn.microsoft.com/windows/desktop/wmformat/drm-licensestate-copytononsdmidevice)

## See also

[DRM Attribute List](https://learn.microsoft.com/windows/desktop/wmformat/drm-attribute-list)

[DRM Properties](https://learn.microsoft.com/windows/desktop/wmformat/drm-properties)

[IWMDRMEditor Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmeditor)