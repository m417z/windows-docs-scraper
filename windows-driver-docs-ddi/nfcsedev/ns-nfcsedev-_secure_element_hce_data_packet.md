# _SECURE_ELEMENT_HCE_DATA_PACKET structure

## Description

**SECURE_ELEMENT_HCE_DATA_PACKET** is an input buffer to [IOCTL_NFCSE_HCE_REMOTE_SEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ni-nfcsedev-ioctl_nfcse_hce_remote_send) and output buffer for [IOCTL_NFCSE_HCE_REMOTE_RECV](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ni-nfcsedev-ioctl_nfcse_hce_remote_recv).

## Members

### `bConnectionId`

The ID of the connection established between the device and the smart card reader, on which to send and receive the HCE packet. This ID is also received from [IOCTL_NFCSE_GET_NEXT_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ni-nfcsedev-ioctl_nfcse_get_next_event) when the event type ([SECURE_ELEMENT_EVENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ne-nfcsedev-_secure_element_event_type)) is **HceActivated** or **HceDeactivated**. Then the **pbEventData** field of the returned [SECURE_ELEMENT_EVENT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ns-nfcsedev-_secure_element_event_info) structure is a [SECURE_ELEMENT_HCE_ACTIVATION_PAYLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ns-nfcsedev-_secure_element_hce_activation_payload) structure, which contains a **bConnectionId** member.

### `cbPayload`

Length of ISO 7816-4 APDU buffer.

### `pbPayload[ANYSIZE_ARRAY]`

Buffer holding ISO 7816-4 APDU.