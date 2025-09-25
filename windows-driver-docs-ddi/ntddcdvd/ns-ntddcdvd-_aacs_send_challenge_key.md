# _AACS_SEND_CHALLENGE_KEY structure

## Description

The AACS_SEND_CHALLENGE_KEY structure is defined as a challenge key that host software sends to an Advanced Access Content System (AACS) device.

## Members

### `SessionId`

A value of type DVD_SESSION_ID that specifies an Authentication Grant Identifier (AGID).

### `ChallengeKey`

A structure of type [AACS_CHALLENGE_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_challenge_key) that specifies the challenge key to retrieve.

## Remarks

Host software send this challenge key to an AACS-compliant device with an [IOCTL_AACS_SEND_CHALLENGE_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_send_challenge_key) request.

## See also

[AACS_CHALLENGE_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_challenge_key)

[DVD_SESSION_ID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff553743(v=vs.85))

[IOCTL_AACS_SEND_CHALLENGE_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_send_challenge_key)