# _WWAN_SET_UICC_RESET structure

## Description

The **WWAN_SET_UICC_RESET** structure represents the passthrough action the MB host specifies for a modem miniport adapter after it resets a UICC smart card.

## Members

### `PassThroughAction`

The passthrough action specified by the host. For more info, see [WWAN_UICC_PASSTHROUGH_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_uicc_passthrough_action).

### `SlotId`

A ULONG value that identifies the SIM slot of the operation. For single SIM devices this value is 0. For dual SIM devices this value is [0..1].

## See also

[MB UICC reset operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-reset-operations)

[NDIS_WWAN_SET_UICC_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_uicc_reset)

[WWAN_UICC_PASSTHROUGH_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_uicc_passthrough_action)