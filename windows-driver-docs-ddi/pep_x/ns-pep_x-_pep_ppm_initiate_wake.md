# _PEP_PPM_INITIATE_WAKE structure (pep_x.h)

## Description

The **PEP_PPM_INITIATE_WAKE** structure indicates whether a processor requires an interrupt to wake up from an idle state.

## Members

### `NeedInterruptForCompletion` [out]

Whether the processor requires an interrupt finish waking up from an idle state. Set to **TRUE** if the processor requires an interrupt, or to **FALSE** if it does not.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_INITIATE_WAKE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_initiate_wake) notification. The **NeedInterruptForCompletion** member contains an output value that the platform extension plug-in (PEP) writes to the structure in response to this notification.

If the PEP sets the **NeedInterruptForCompletion** member to TRUE, the PEP must ensure that the processor is enabled to be interrupted before the [AcceptProcessorNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbacknotifyppm) callback routine returns.

The PEP should set the **NeedInterruptForCompletion** member to **FALSE** if the processor is already running and/or will eventually exit the idle state (and is in the process of doing so) without requiring a software-generated interrupt.

## See also

[AcceptProcessorNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbacknotifyppm)

[PEP_NOTIFY_PPM_INITIATE_WAKE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_initiate_wake)