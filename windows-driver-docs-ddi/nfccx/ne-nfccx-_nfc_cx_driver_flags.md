# _NFC_CX_DRIVER_FLAGS enumeration

## Description

Specifies run-time driver flags.

## Constants

### `NFC_CX_DRIVER_DISABLE_WTD_TIMER`

Disable watchdog timer in CX.

### `NFC_CX_DRIVER_DISABLE_NFCEE_DISCOVERY`

Disable NFCEE discovery.

### `NFC_CX_DRIVER_DISABLE_RECOVERY_MODE`

Disable NCI recovery mechanism in CX.

### `NFC_CX_DRIVER_DISABLE_HOST_CARD_EMULATION`

Disable host card emulation feature.

### `NFC_CX_DRIVER_HCI_NETWORK_PER_NFCEE`

NFCC implements a separate HCI network per NFCEE.

### `NFC_CX_DRIVER_DISABLE_NFCEE_ACTION_NTF`

Disable NFCEE action notification.

### `NFC_CX_DRIVER_ENABLE_EEPROM_WRITE_PROTECTION`

Enable opt to over-write only when configs change.

### `NFC_CX_DRIVER_ISODEP_RNAK_PRESENCE_CHK_SUPPORTED`

The R-NAK command for ISO-DEP will be used for presence check.

### `NFC_CX_DRIVER_RF_ROUTING_POWER_SUB_STATES_SUPPORTED`

Indicates support for RF routing switched ON power sub-states.

### `NFC_CX_DRIVER_SKIP_DEVICE_STOP_IDLE`

NFC CX will not call [WdfDeviceStopIdle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicestopidle) or [WdfDeviceResumeIdle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceresumeidle).

### `NFC_CX_DRIVER_POWER_AND_LINK_CONTROL_SUPPORTED`

Indicates that **NFCEE_POWER_AND_LINK_CTRL** is supported for the NCI 1.x protocol as an extension.

## Remarks

The NFC CX allows the NFC client driver to provide some driver flags that can be used to configure the run-time implementation of the class extension. These flags enable the NFC CX to implement some standard NCI operations slightly differently to support different firmware implementations due to ambiguities in the NCI specification.

## See also

- [NFC class extension design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfc-class-extension-)
- [Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)