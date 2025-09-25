# IESFileExpiryDateEvent::GetTunerId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a globally unique identifier (GUID) from a **FileExpiryDate** event that identifies the media transform device (MTD) that originated the event.

## Parameters

### `pguidTunerId` [out, retval]

Receives the GUID for the MTD.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESFileExpiryDateEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesfileexpirydateevent)