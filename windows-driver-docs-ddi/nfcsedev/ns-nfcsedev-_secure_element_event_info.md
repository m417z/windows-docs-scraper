# _SECURE_ELEMENT_EVENT_INFO structure

## Description

This structure provides information about a secure element event.

## Members

### `guidSecureElementId`

This is a unique identifier for the secure element.

### `eEventType`

This is an event type. For more information about the types, see the [SECURE_ELEMENT_EVENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ne-nfcsedev-_secure_element_event_type) enumeration topic.

### `cbEventData`

This is the amount of bytes for the pbEventData array.

### `pbEventData[ANYSIZE_ARRAY]`

This is the event data buffer. When **eEventType** is **HceActivated** or **HceDeactivated**, this member contains a pointer to a [SECURE_ELEMENT_HCE_ACTIVATION_PAYLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ns-nfcsedev-_secure_element_hce_activation_payload) structure. The **bConnectionId** member in that structure is the same ID value that's used in [SECURE_ELEMENT_HCE_DATA_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ns-nfcsedev-_secure_element_hce_data_packet) to send and receive an HCE packet with [IOCTL_NFCSE_HCE_REMOTE_SEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ni-nfcsedev-ioctl_nfcse_hce_remote_send) and [IOCTL_NFCSE_HCE_REMOTE_RECV](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ni-nfcsedev-ioctl_nfcse_hce_remote_recv).

When **eEventType** is **ExternalReaderArrival** or **ExternalReaderDeparture**, **pbEventData** is empty and **cbEventData** is 0.

When **eEventType** is **Transaction**, **pbEventData** contains a list of parameters that is encoded in BER-TLV fields. This event is mapped to EVT_TRANSACTION.