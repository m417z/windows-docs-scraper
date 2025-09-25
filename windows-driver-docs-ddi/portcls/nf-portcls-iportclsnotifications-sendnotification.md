# IPortClsNotifications::SendNotification

## Description

Sends a notification to the listening UWP apps, to allow for communications between audio modules and UWP apps.

## Parameters

### `NotificationId` [in]

KSNOTIFICATIONID_AudioModule

### `NotificationBuffer` [in]

Pointer to a [PCNOTIFICATION_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcnotification_buffer) structure to send to the listening audio module UWP clients.

## Remarks

Pointer to the PCNOTIFICATION structure to send to Audio Module clients.

The expected format of the payload is a [KSAUDIOMODULE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ksaudiomodule_notification) structure. The miniport driver can optionally send additional information immediately following the **KSAUDIOMODULE_NOTIFICATION** structure that will be untouched and sent to the Audio Module clients.

For more information about audio modules, see [Implementing Audio Module Discovery](https://learn.microsoft.com/windows-hardware/drivers/audio/implementing-audio-module-communication).

## See also

[IPortClsNotifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportclsnotifications)