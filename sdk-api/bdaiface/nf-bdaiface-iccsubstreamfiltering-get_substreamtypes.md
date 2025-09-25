# ICCSubStreamFiltering::get_SubstreamTypes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **get_SubstreamTypes** method retrieves the list of closed captioning services this pin is delivering.

## Parameters

### `pTypes` [out]

Receives a bitwise OR of flags that specify the closed captioning services. For a list of flags, see [KS_CC_SUBSTREAM Constants](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/ks-cc-substream).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[ICCSubStreamFiltering Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-iccsubstreamfiltering)