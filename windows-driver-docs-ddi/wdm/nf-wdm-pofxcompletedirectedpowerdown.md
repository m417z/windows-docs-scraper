# PoFxCompleteDirectedPowerDown function

## Description

A DFx (Directed [PoFx](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework)) client driver calls this function to complete the Directed power down transition.

## Parameters

### `Handle`

A POHANDLE value that represents the registration of the processor (as a device) with [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx).

## Remarks

The driver typically calls this routine from its [*PO_FX_DIRECTED_POWER_DOWN_CALLBACK*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_directed_power_down_callback) callback routine.

## See also

/windows-hardware/drivers/kernel/introduction-to-the-directed-power-management-framework