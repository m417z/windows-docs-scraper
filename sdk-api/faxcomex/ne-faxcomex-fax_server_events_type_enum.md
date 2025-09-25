# FAX_SERVER_EVENTS_TYPE_ENUM enumeration

## Description

The **FAX_SERVER_EVENTS_TYPE_ENUM** enumeration defines the types of events the fax service sends to client applications that are listening for events. The members of this enumeration are bit values and can be used in combination.

## Constants

### `fsetNONE:0`

No events are sent.

### `fsetIN_QUEUE:0x1`

The client requests notifications about fax jobs in the incoming queue. When the status of an incoming fax job changes, the fax service issues a notification of this type.

### `fsetOUT_QUEUE:0x2`

The client requests notification about fax jobs in the outgoing queue. When the status of an outgoing fax job changes, the fax service issues a notification of this type.

### `fsetCONFIG:0x4`

The client requests notifications about changes to the fax server configuration. When the configuration data changes, the fax service issues a notification of this type.

### `fsetACTIVITY:0x8`

The client requests notifications about the fax server activity. When the activity status of the fax server changes, the fax service issues a notification of this type.

### `fsetQUEUE_STATE:0x10`

The client requests notifications about changes in the status of the fax job queue. When the status of the queue changes, the fax service issues a notification.

### `fsetIN_ARCHIVE:0x20`

The client requests notifications about the addition or removal of fax messages from the incoming archive. When a message is removed from the archive, the fax service issues a notification. The notification includes the archive type (inbound) and the unique ID of the fax message.

### `fsetOUT_ARCHIVE:0x40`

The client requests notifications about the addition or removal of fax messages from the outgoing archive. When a message is removed from the archive, the fax service issues a notification. The notification includes the archive type (outbound) and the unique ID of the fax message.

### `fsetFXSSVC_ENDED:0x80`

The client requests notifications when the fax service stops executing.

### `fsetDEVICE_STATUS:0x100`

The client requests notifications when a device status changes.

### `fsetINCOMING_CALL:0x200`

The client requests notifications when there is an incoming call.

## Remarks

The following table lists the [IFaxServerNotify](https://learn.microsoft.com/windows/desktop/api/faxcomex/nn-faxcomex-ifaxservernotify2) methods called by each member.

| Name | [IFaxServerNotify](https://learn.microsoft.com/windows/desktop/api/faxcomex/nn-faxcomex-ifaxservernotify2) method called |
| --- | --- |
| fsetNONE | None |
| fsetIN_QUEUE | **OnIncomingJobAdded**<br><br>**OnIncomingJobRemoved**<br><br>**OnIncomingJobChanged** |
| fsetOUT_QUEUE | **OnOutgoingJobAdded**<br><br>**OnOutgoingJobRemoved**<br><br>**OnOutgoingJobChanged** |
| fsetCONFIG | **OnReceiptOptionsChange**<br><br>**OnActivityLoggingConfigChange**<br><br>**OnSecurityConfigChange**<br><br>**OnEventLoggingConfigChange**<br><br>**OnOutgoingQueueConfigChange**<br><br>**OnOutgoingArchiveConfigChange**<br><br>**OnIncomingArchiveConfigChange**<br><br>**OnDevicesConfigChange**<br><br>**OnOutboundRoutingGroupsConfigChange**<br><br>**OnOutboundRoutingRulesConfigChange** |
| fsetACTIVITY | **OnServerActivityChange** |
| fsetQUEUE_STATE | **OnQueuesStatusChange** |
| fsetIN_ARCHIVE | **OnIncomingMessageAdded**<br><br>**OnIncomingMessageRemoved** |
| fsetOUT_ARCHIVE | **OnOutgoingMessageAdded**<br><br>**OnOutgoingMessageRemoved** |
| fsetFXSSVC_ENDED | **OnServerShutDown** |
| fsetDEVICE_STATUS | **OnDeviceStatusChange** |
| fsetINCOMING_CALL | **OnNewCall** |

The following table lists the [IFaxServerNotify2](https://learn.microsoft.com/windows/win32/api/faxcomex/nn-faxcomex-_ifaxservernotify2) methods called by each member.

| Name | [IFaxServerNotify2](https://learn.microsoft.com/windows/win32/api/faxcomex/nn-faxcomex-_ifaxservernotify2) method called |
| --- | --- |
| fsetNONE | None |
| fsetIN_QUEUE | **OnIncomingJobAdded**<br><br>**OnIncomingJobRemoved**<br><br>**OnIncomingJobChanged** |
| fsetOUT_QUEUE | **OnOutgoingJobAdded**<br><br>**OnOutgoingJobRemoved**<br><br>**OnOutgoingJobChanged** |
| fsetCONFIG | **OnReceiptOptionsChange**<br><br>**OnActivityLoggingConfigChange**<br><br>**OnSecurityConfigChange**<br><br>**OnEventLoggingConfigChange**<br><br>**OnOutgoingQueueConfigChange**<br><br>**OnOutgoingArchiveConfigChange**<br><br>**OnIncomingArchiveConfigChange**<br><br>**OnDevicesConfigChange**<br><br>**OnOutboundRoutingGroupsConfigChange**<br><br>**OnOutboundRoutingRulesConfigChange**<br><br>**OnGeneralServerConfigChanged** |
| fsetACTIVITY | **OnServerActivityChange** |
| fsetQUEUE_STATE | **OnQueuesStatusChange** |
| fsetIN_ARCHIVE | **OnIncomingMessageAdded**<br><br>**OnIncomingMessageRemoved** |
| fsetOUT_ARCHIVE | **OnOutgoingMessageAdded**<br><br>**OnOutgoingMessageRemoved** |
| fsetFXSSVC_ENDED | **OnServerShutDown** |
| fsetDEVICE_STATUS | **OnDeviceStatusChange** |
| fsetINCOMING_CALL | **OnNewCall** |

## See also

[IFaxServer::ListenToServerEvents](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-listentoserverevents-vb)

[IFaxServerNotify](https://learn.microsoft.com/windows/desktop/api/faxcomex/nn-faxcomex-ifaxservernotify2)