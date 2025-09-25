# IIsdbCAServiceDescriptor::GetMessageControl

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the delay time, in days, before the automatic entitlement management message (EMM) is displayed from a conditional access (CA) service descriptor.

## Parameters

### `pbVal` [out]

Receives the number of days before the EMM message is displayed. A value of 0xFF indicates that the delay time is
disabled (that the start of the delay time has been put on hold).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When playing a previously received and stored program on a receiver with stored
reception functionality, a least significant bit of 1 in this field indicates that the
automatic display message will not be displayed.

## See also

[IIsdbCAServiceDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbcaservicedescriptor)