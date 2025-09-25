# DRM_LICENSE_ACQ_DATA structure

## Description

>[!Note]
>The AD RMS SDK leveraging functionality exposed by the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal), which leverages functionality exposed by the client in Msipc.dll.

Not supported.

The **DRM_LICENSE_ACQ_DATA** structure holds license acquisition data during nonsilent license acquisition.

**Note** nonsilent license acquisition is supported only in Rights Management Services client 1.0. Effective with RMS client 1.0 SP1, nonsilent license acquisition is no longer supported.

## Members

### `uVersion`

Version of this structure, for backward compatibility. In C, this value should be initialized to **DRMLICENSEACQDATAVERSION**.

### `wszURL`

URL of a license-granting website.

### `wszLocalFilename`

The path and file name of a local HTML file that will automatically send a license request when loaded in a browser.

### `pbPostData`

Pointer to a URL-safe base64-encoded string containing the license request.

### `dwPostDataSize`

The post data size in characters, plus one for a null terminator.

### `wszFriendlyName`

A human-readable name for the license-granting website.

### `_DRM_LICENSE_ACQ_DATA`

TBD

## Remarks

This structure has a C++ default constructor that takes no parameters and sets all members to **NULL**, except **uVersion**, which is set to **DRMLICENSEACQDATAVERSION**.

## See also

[AD RMS Structures](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-structures)

[DRMAcquireLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmacquirelicense)