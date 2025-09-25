# KeDeregisterBugCheckCallback function

## Description

The **KeDeregisterBugCheckCallback** routine removes a callback routine that was registered by [KeRegisterBugCheckCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckcallback).

## Parameters

### `CallbackRecord` [in, out]

Pointer to a [KBUGCHECK_CALLBACK_RECORD](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure. *CallbackRecord* must be the same value that was passed to [KeRegisterBugCheckCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckcallback) when the callback was registered.

## Return value

**KeDeregisterBugCheckCallback** returns **TRUE** if the specified callback is successfully removed. It returns **FALSE** if the specified callback is not registered.

## See also

[KeRegisterBugCheckCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckcallback)