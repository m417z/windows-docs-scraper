# IDTFilter::put_BlockUnRatedDelay

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_BlockUnRatedDelay** method sets the length of time the filter waits before it blocks unrated content.

## Parameters

### `msecsDelayBeforeBlock` [in]

Specifies the delay, in milliseconds. The value must be from 0 to 60000 (60 seconds).

## Return value

Returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument |
| **S_OK** | Success |

## Remarks

Regardless of the value of this property, the filter does not block unrated content unless the **BlockUnRated** property is **TRUE**.

## See also

[IDTFilter Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-idtfilter)

[IDTFilter::put_BlockUnRated](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nf-encdec-idtfilter-put_blockunrated)