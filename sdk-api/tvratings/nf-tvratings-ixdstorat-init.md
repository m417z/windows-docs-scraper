# IXDSToRat::Init

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Init** method sets the [XDSToRat](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/xdstorat-object) object to its initial state.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The XDS Codec filter calls this method on startup or after a discontinuity, such as a channel change. The [XDSToRat](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/xdstorat-object) object should clear any internal buffers and reset its parsing state. This method prevents decoding errors caused by channel changes or other interruptions.

## See also

[IXDSToRat Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tvratings/nn-tvratings-ixdstorat)