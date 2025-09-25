# _NFCRM_SET_RADIO_STATE structure

## Description

This structure is used to set the radio state. The driver, in the case of airplane mode, has to persist the radio state and restore it when airplane mode is disabled.

## Members

### `SystemStateUpdate`

The **SystemStateUpdate**. If true, indicates that IOCTL_NFCRM_SET_RADIO_STATE is triggered by airplane mode.

### `MediaRadioOn`

The **MediaRadioOn** flag either enables the system trigger (airplane mode if **SystemStateUpdate** is true) or disables it.

## Remarks

Airplane mode status is ON if **SystemStateUpdate** is true and **MediaRadioOn** is false.

Airplane mode status is OFF if **SystemStateUpdate** is true and **MediaRadioOn** is true.

NFC status is ON if **SystemStateUpdate** is false and **MediaRadioOn** is true.

NFC status is OFF if **SystemStateUpdate** is false and **MediaRadioOn** is false.