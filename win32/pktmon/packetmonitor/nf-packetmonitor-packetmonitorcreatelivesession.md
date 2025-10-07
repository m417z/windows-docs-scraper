# PacketMonitorCreateLiveSession function

## Description

Creates an independent Packet Monitor session.

With the multisession feature, you can create multiple sessions, and configure each one with different sets of parameters to capture packets. This API supports the creation of an independent session for Packet Monitor.

## Parameters

### [in] handle

Handle to the pktmon driver which was obtained by first calling ‘PacketMonitorInitialize’.

### [in] name

Name to identify the session. The maximum length allowed is 256. Minimum is 1.

### [out] session

This is declared as ‘DECLARE_HANDLE(PACKETMONITOR_SESSION)’.

If SUCCESS, this will contain the object to the session. Later, the session can be controlled through the same object for functions like:

PacketMonitorCloseSessionHandle

PacketMonitorSetSessionActive

PacketMonitorAddSingleDataSourceToSession

PacketMonitorAddCaptureConstraint

PacketMonitorAttachOutputToSession

## Returns

If the function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

The session needs to be activated to start monitoring the traffic on it. That can be done by calling ‘PacketMonitorSetSessionActive’.

After a user is done working with a Packet Monitor session, they must call PacketMonitorCloseSessionHandle.

## See also

[Packet Monitor (Pktmon) reference](https://learn.microsoft.com/windows/win32/pktmon/pktmon-reference)