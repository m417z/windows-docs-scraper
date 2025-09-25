# PPO_ENUMERATE_INTERRUPT_SOURCE_CALLBACK callback (pepfx.h)

## Description

An *EnumerateInterruptSource* callback routine supplies a platform extension plug-in (PEP) with information about an interrupt source.

## Parameters

### `CallbackContext` [in]

A pointer to a callback context. The PEP specified this pointer value as a parameter in the [EnumerateUnmaskedInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackenumerateunmaskedinterrupts) call that initiated the enumeration of interrupt sources.

### `InterruptInformation` [in]

A pointer to a [PEP_UNMASKED_INTERRUPT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_unmasked_interrupt_information) structure that contains information about the interrupt source.

## Return value

If the *EnumerateInterruptSource* callback routine returns TRUE, **EnumerateUnmaskedInterrupts** will continue to call the *EnumerateInterruptSource* callback routine while more interrupts are available to be enumerated. If the *EnumerateInterruptSource* callback routine returns FALSE, **EnumerateUnmaskedInterrupts** returns without enumerating any more interrupts.

## Prototype

```cpp
PO_ENUMERATE_INTERRUPT_SOURCE_CALLBACK EnumerateInterruptSource;

BOOLEAN EnumerateInterruptSource(
  _In_ PVOID                               CallbackContext,
  _In_ PPEP_UNMASKED_INTERRUPT_INFORMATION InterruptInformation
)
{ ... }
```

## Remarks

This callback routine is implemented by a PEP, and is called by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The *Callback* parameter of the [EnumerateUnmaskedInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackenumerateunmaskedinterrupts) routine is a pointer to an *EnumerateInterruptSource* callback routine.

After a PEP calls **EnumerateUnmaskedInterrupts** to enumerate the unmasked interrupt sources, PoFx calls the PEP's *EnumerateInterruptSource* callback routine once for each unmasked interrupt source. **EnumerateUnmaskedInterrupts** returns only after the last call to the *EnumerateInterruptSource* callback routine completes.

An *EnumerateInterruptSource* callback routine is called at the same IRQL as the PEP's call to **EnumerateUnmaskedInterrupts** that initiates the enumeration callbacks.

## See also

[PEP_UNMASKED_INTERRUPT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_unmasked_interrupt_information)

[EnumerateUnmaskedInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackenumerateunmaskedinterrupts)