# IMFASFContentInfo::SetProfile

## Description

Uses profile data from a profile object to configure settings in the ContentInfo object.

## Parameters

### `pIProfile` [in]

The [IMFASFProfile](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfprofile) interface of the profile object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If there is already information in the ContentInfo object when this method is called, it is replaced by the information from the profile object.

## See also

[ASF ContentInfo Object](https://learn.microsoft.com/windows/desktop/medfound/asf-contentinfo-object)

[IMFASFContentInfo](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfcontentinfo)

[IMFASFContentInfo::GetProfile](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfcontentinfo-getprofile)

[Initializing the ContentInfo Object of a New ASF File](https://learn.microsoft.com/windows/desktop/medfound/initializing-the-contentinfo-object-of-a-new-asf-file)