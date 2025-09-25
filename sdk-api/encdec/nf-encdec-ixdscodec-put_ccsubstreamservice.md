# IXDSCodec::put_CCSubstreamService

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_CCSubstreamService** method specifies which line 21 data channels the XDS Codec filter sends to the **XDSToRat** object. By default, only the Extended Data Services (XDS) channel is supported.

## Parameters

### `SubstreamMask` [in]

Bitwise combination of zero or more [KS_CC_SUBSTREAM](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/ks-cc-substream) flags, specifying the line 21 services.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument |
| **S_OK** | Success |

## See also

[IXDSCodec Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-ixdscodec)