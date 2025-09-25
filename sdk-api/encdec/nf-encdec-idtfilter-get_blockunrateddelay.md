# IDTFilter::get_BlockUnRatedDelay

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_BlockUnRatedDelay** method retrieves that length of time the filter waits before it blocks unrated content.

## Parameters

### `pmsecsDelayBeforeBlock` [out, retval]

Receives the delay, in milliseconds.

## Return value

Returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument |
| **S_OK** | Success |

## Remarks

Regardless of the value of this property, the filter does not block unrated content unless the **BlockUnRated** property is **TRUE**.

## See also

[IDTFilter Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-idtfilter)

[IDTFilter::get_BlockUnRated](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nf-encdec-idtfilter-get_blockunrated)