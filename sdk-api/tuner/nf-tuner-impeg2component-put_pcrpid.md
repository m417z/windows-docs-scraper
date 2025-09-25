# IMPEG2Component::put_PCRPID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_PCRPID** method sets the packet identifier (PID) for the packets that contain the PCR for this substream.

## Parameters

### `PCRPID` [in]

Specifies the PCR PID.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IMPEG2Component Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-impeg2component)