# _AACS_CHALLENGE_KEY structure

## Description

The AACS_CHALLENGE_KEY structure contains the challenge key that the device sends to the host.

## Members

### `EllipticCurvePoint`

The elliptical curve (ECC) point data.

### `Signature`

The signature that the client uses to verify that the ECC point is valid for the current Advanced Access Content System (AACS) authentication sequence.

## Remarks

Clients retrieve the Advanced Access Content System (AACS) challenge key with an [IOCTL_AACS_GET_CHALLENGE_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_get_challenge_key) request. Clients send an AACS challenge key to the logical unit in an [AACS_SEND_CHALLENGE_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_send_challenge_key) structure with an [IOCTL_AACS_SEND_CHALLENGE_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_send_challenge_key).

## See also

[AACS_SEND_CHALLENGE_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_send_challenge_key)

[IOCTL_AACS_GET_CHALLENGE_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_get_challenge_key)

[IOCTL_AACS_SEND_CHALLENGE_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_send_challenge_key)