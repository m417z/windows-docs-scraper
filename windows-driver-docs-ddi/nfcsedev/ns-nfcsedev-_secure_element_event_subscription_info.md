# _SECURE_ELEMENT_EVENT_SUBSCRIPTION_INFO structure

## Description

The SECURE_ELEMENT_EVENT_SUBSCRIPTION_INFO structure is an input parameter to [IOCTL_NFCSE_SUBSCRIBE_FOR_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ni-nfcsedev-ioctl_nfcse_subscribe_for_event).

## Members

### `guidSecureElementId`

### `eEventType`

Secure element event type. A service can subscribe and receive notification when an external reader arrival, external reader departure, transaction, HCE activated, or HCE deactivated event is triggered.