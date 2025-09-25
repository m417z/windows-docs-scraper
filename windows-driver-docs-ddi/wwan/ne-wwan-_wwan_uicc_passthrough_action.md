# _WWAN_UICC_PASSTHROUGH_ACTION enumeration

## Description

The **WWAN_UICC_PASSTHROUGH_ACTION** enumeration defines the passthrough action specified by the MB host for a modem miniport adapter after it resets a UICC smart card.

## Constants

### `WwanUiccPassThroughDisable`

Indicates to disable passthrough to the UICC after reset. When UICC passthrough is disabled, the MB host treats the UICC as a regular Telecom UICC and expects a Telecom UICC file system to be present on the UICC.

### `WwanUiccPassThroughEnable`

Indicates to enable passthrough to the UICC after reset. When UICC passthrough is enabled, the modem miniport adapter treats the UICC as if it were in a passthrough mode that enables communication between the host and UICC, even if the UICC has no Telecom UICC file system. The miniport adapter does not send any APDUs to the card and does not interfere at any time with the communication between the host and the UICC.

### `WwanUiccPassThroughActionMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## See also

[MB UICC reset operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-reset-operations)

[WWAN_SET_UICC_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_uicc_reset)