# PacketMonitorSetSessionActive function

## Description

Activate or deactivate a packet monitor session.

This function is used to activate (or deactivate if already active) a session. Network traffic monitoring starts only after a session is activated. To pause/stop an active monitoring session, the same API should be called with corresponding argument. A session can be activated or deactivated multiple times over the course of its lifetime.

## Parameters

### [in] session

Session object previously obtained by calling ‘PacketMonitorCreateLiveSession’.

### [in] active

True is passed to activate the session.

False is passed to deactivate a previously active session. Traffic monitoring will stop before the API returns.

## Returns

If the function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

A deactivated session can be activated again to resume network traffic monitoring.

## See also

[Packet Monitor (Pktmon) reference](https://learn.microsoft.com/windows/win32/pktmon/pktmon-reference)