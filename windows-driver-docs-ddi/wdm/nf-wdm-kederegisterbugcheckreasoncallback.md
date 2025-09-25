# KeDeregisterBugCheckReasonCallback function

## Description

The **KeDeregisterBugCheckReasonCallback** routine removes a callback routine that was registered by **[KeRegisterBugCheckReasonCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckreasoncallback)**.

## Parameters

### `CallbackRecord` [in, out]

Pointer to a **[KBUGCHECK_REASON_CALLBACK_RECORD](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)** structure. *CallbackRecord* must be the same value that was passed to **[KeRegisterBugCheckReasonCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckreasoncallback)** when the callback was registered.

## Return value

**KeDeregisterBugCheckReasonCallback** returns **TRUE** if the callback is successfully removed. It returns **FALSE** if the specified callback is not registered.

## See also

**[KeRegisterBugCheckReasonCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckreasoncallback)**