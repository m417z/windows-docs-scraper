# IIsdbTSInformationDescriptor::GetRemoteControlKeyId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the remote_control_key_id field value from an Integrated Services Digital Broadcasting (ISDB) transport stream (TS) information descriptor. This field indicates the recommended remote control key number to
which the applicable transport stream is assigned.

## Parameters

### `pbVal` [out]

Receives the remote_control_key_id field value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbTSInformationDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbtsinformationdescriptor)