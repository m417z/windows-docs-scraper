# IBandSite::GetBandSiteInfo

## Description

Gets information about a band in the band site.

## Parameters

### `pbsinfo` [in, out]

Type: **[BANDSITEINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-bandsiteinfo)***

The address of a [BANDSITEINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-bandsiteinfo) structure that contains
the band site information for the object. The
**dwMask** member of this structure
specifies what information is being requested.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error code otherwise.

## See also

[BANDSITEINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-bandsiteinfo)

[IBandSite](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ibandsite)

[IDeskBand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ideskband)