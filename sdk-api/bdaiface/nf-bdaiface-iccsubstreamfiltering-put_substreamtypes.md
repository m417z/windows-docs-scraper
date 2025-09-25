# ICCSubStreamFiltering::put_SubstreamTypes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **get_SubstreamTypes** method sets the closed captioning services the pin will deliver.

## Parameters

### `Types` [in]

Bitwise OR of flags that specify the closed captioning services. For a list of flags, see [KS_CC_SUBSTREAM Constants](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/ks-cc-substream). Any services that are not selected are simply dropped.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[ICCSubStreamFiltering Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-iccsubstreamfiltering)