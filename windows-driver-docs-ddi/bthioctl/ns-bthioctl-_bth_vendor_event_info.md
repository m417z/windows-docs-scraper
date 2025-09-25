# _BTH_VENDOR_EVENT_INFO structure

## Description

The BTH_VENDOR_EVENT_INFO structure specifies the buffer that is associated with the
GUID_BLUETOOTH_HCI_VENDOR_EVENT GUID.

## Members

### `BthAddress`

The address of the local radio that is associated with the event.

### `EventSize`

The size, in bytes, of the event buffer. The size includes the event header.

### `EventInfo`

A UCHAR array for the event buffer. The buffer includes the event header.

## Remarks

The BTH_VENDOR_EVENT_INFO structure contains data that is associated with a
GUID_BLUETOOTH_HCI_VENDOR_EVENT event.

An application or driver that registers for notifications for the GUID_BTHPORT_DEVICE_INTERFACE GUID
receives the WM_DEVICECHANGE message that has
*wParam* set to DBT_CUSTOMEVENT and the event GUID set to GUID_BLUETOOTH_HCI_VENDOR_EVENT.