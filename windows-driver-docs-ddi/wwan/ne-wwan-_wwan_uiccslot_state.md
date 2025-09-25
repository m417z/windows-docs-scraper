# _WWAN_UICCSLOT_STATE enumeration

## Description

The **WWAN_UICCSLOT_STATE** enumeration lists the different states of a UICC (SIM) card slot on a modem. The slot state represents a summary of both the slot state and the card state.

## Constants

### `WwanUiccSlotStateUnknown`

The modem is still in the process of initializing so the SIM slot state is not deterministic.

### `WwanUiccSlotStateOffEmpty`

The card slot is powered off and empty. An implementation that is unable to determine the presence of a card in a slot that is powered off reports its state as *Off*.

### `WwanUiccSlotStateOff`

The card slot is powered off and a card is present.

### `WwanUiccSlotStateEmpty`

The card slot is powered on but no card is present.

### `WwanUiccSlotStateNotReady`

The card in the slot is not ready. In other words, it has been reset but has not finished initializing. It cannot be used at this time.

### `WwanUiccSlotStateActive`

The card in the slot is available and ready to accept commands. This has no association with the SIM PIN locked state.

### `WwanUiccSlotStateError`

The card in the slot is in an error state and cannot be used.

### `WwanUiccSlotStateActiveEsim`

The card in the slot is an eSIM with an active profile, and it is ready to accept commands.

### `WwanUiccSlotStateActiveEsimNoProfile`

The card in the slot is an eSIM with no profiles or active profiles, and it is ready to accept commands.

### `WwanUiccSlotStateMax`

The maximum value for this enumeration.

## Remarks

The set of reported states is constrained by the capability of the slot hardware. In the most restrictive case, the slot hardware may only be able to determine that a card is present when it is powered on and active; in such a case the **OffEmpty** and **Off** states will not be reported.

## See also

[WWAN_SLOT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_slot_info)