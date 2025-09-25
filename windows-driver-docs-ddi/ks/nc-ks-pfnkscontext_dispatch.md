# PFNKSCONTEXT_DISPATCH callback function

## Description

A streaming minidriver's *KStrContextDispatch* routine is called to process IRP_MJ_POWER IRPs.

## Parameters

### `Context` [in]

Specifies the user-supplied memory context to be passed as the *PowerContext* argument to the [KsSetPowerDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kssetpowerdispatch) function.

### `Irp` [in]

Specifies the power IRP to be processed.

## Return value

Returns STATUS_SUCCESS.

## Remarks

*KStrContextDispatch* must not complete the power IRP that is passed in the *Irp* parameter.

To manipulate the list entry only, *KStrContextDispatch* can call **KsSetPowerDispatch** while processing the power IRP. Manipulating other list entries can cause enumeration errors.

## See also

[KsSetPowerDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kssetpowerdispatch)