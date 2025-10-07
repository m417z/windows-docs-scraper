# PacketMonitorAttachOutputToSession function

## Description

This function is used to attach output to an existing session.

## Parameters

### [in] session

Session handle.

### [in] outputHandle

Handle to an existing output type. Currently, the only output type supported is Real Time Stream. Hence, the outputHandle here would be object of type ‘PACKETMONITOR_REALTIME_STREAM’ which was created using ‘PacketMonitorCreateRealtimeStream’.

## Returns

If SUCCESS, it returns S_OK, else an HRESULT error code.

## Remarks

An output will only become active and start receiving monitoring information once the session is activated. This API can be called either before or after the call to ‘PacketMonitorSetSessionActive’.

## See also

[Packet Monitor (Pktmon) reference](https://learn.microsoft.com/windows/win32/pktmon/pktmon-reference)