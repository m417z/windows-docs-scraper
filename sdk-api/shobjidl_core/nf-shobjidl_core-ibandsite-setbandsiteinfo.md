# IBandSite::SetBandSiteInfo

## Description

Sets information about the band site.

## Parameters

### `pbsinfo` [in]

Type: **[BANDSITEINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-bandsiteinfo)***

The address of a [BANDSITEINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-bandsiteinfo) structure that receives
the band site information for the object. The
**dwMask** member of this structure
specifies what information is being set.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error code otherwise.

## See also

[IBandSite](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ibandsite)

[IDeskBand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ideskband)