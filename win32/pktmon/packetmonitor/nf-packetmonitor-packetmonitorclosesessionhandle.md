# PacketMonitorCloseSessionHandle function

## Description

Closes handle to previously created session object.

This is called to close the handle to a previously created session object. Failure to close a session handle will result in leaked resources in the PktMon driver.

## Parameters

### [in] session

Session Object previously created by calling ‘PacketMonitorCreateLiveSession’.

## See also

[Packet Monitor (Pktmon) reference](https://learn.microsoft.com/windows/win32/pktmon/pktmon-reference)