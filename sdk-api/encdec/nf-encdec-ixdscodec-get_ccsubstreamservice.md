# IXDSCodec::get_CCSubstreamService

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_CCSubstreamService** method queries which line 21 data channels the XDS Codec filter sends to the **XDSToRat** object. By default, it sends just the Extended Data Services (XDS) channel.

## Parameters

### `pSubstreamMask` [out, retval]

Receives a bitwise combination of zero or more [KS_CC_SUBSTREAM](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/ks-cc-substream) flags.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument |
| **S_OK** | Success |

## See also

[IXDSCodec Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-ixdscodec)