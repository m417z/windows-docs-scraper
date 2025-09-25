# _AACS_BINDING_NONCE structure

## Description

The AACS_BINDING_NONCE structure contains the binding nonce.

## Members

### `BindingNonce`

The binding nonce for the requested logical block address(es) (LBAs).

### `MAC`

A message authentication code (MAC) that clients can use to verify that the binding nonce is for the current Advanced Access Content System (AACS) Authentication sequence.

## Remarks

Clients retrieve the binding nonce with an [IOCTL_AACS_READ_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_read_binding_nonce) request or an [IOCTL_AACS_GENERATE_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_generate_binding_nonce) request.

## See also

[IOCTL_AACS_GENERATE_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_generate_binding_nonce)

[IOCTL_AACS_READ_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_read_binding_nonce)