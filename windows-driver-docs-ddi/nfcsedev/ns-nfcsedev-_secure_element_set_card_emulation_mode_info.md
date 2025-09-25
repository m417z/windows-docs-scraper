# _SECURE_ELEMENT_SET_CARD_EMULATION_MODE_INFO structure

## Description

SECURE_ELEMENT_SET_CARD_EMULATION_MODE_INFO is the input parameter for [IOCTL_NFCSE_SET_CARD_EMULATION_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ni-nfcsedev-ioctl_nfcse_set_card_emulation_mode).

## Members

### `guidSecureElementId`

This is a unique identifier for the secure element.

### `eMode`

Card emulation mode: off, power dependent, or power-independent.