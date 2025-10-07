# WMDRM\_LICENSE\_FILTER structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMDRM\_LICENSE\_FILTER** structure defines filtering parameters for use when creating a license enumeration.

## Members

**dwVersion**

Specifies a minimum version number for the returned licenses.

**bstrKID**

Specifies a key ID to filter licenses for. Only licenses with the specified key ID will be included in the enumeration.

**bstrRights**

Specifies a set of rights to filter licenses for. Only licenses that provide all of the specified rights will be included in the enumeration.

**bstrAllowedSourceIDs**

Specifies the sources of protected content to include in the license search.

## Remarks

This structure is used by the [**IWMDRMLicenseManagement::CreateLicenseEnumeration**](https://learn.microsoft.com/windows/win32/wmformat/iwmdrmlicensemanagement-createlicenseenumeration) method.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)

