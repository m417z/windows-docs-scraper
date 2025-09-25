# TpSetCallbackFinalizationCallback function

## Description

Indicates a function to call when the callback environment is finalized.

## Parameters

### `CallbackEnviron` [in, out]

A **TP_CALLBACK_ENVIRON** structure that defines the callback environment. The [TpInitializeCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpinitializecallbackenviron) function returns this structure.

### `FinalizationCallback` [in]

Pointer to a **TP_SIMPLE_CALLBACK** structure indicating a function to call when the callback environment is finalized.

## Remarks

This function is implemented as an inline function.

## See also

[TpDestroyCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpdestroycallbackenviron)

[TpInitializeCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpinitializecallbackenviron)

[TpSetCallbackActivationContext](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackactivationcontext)

[TpSetCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackcleanupgroup)

[TpSetCallbackLongFunction](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbacklongfunction)

[TpSetCallbackNoActivationContext](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbacknoactivationcontext)

[TpSetCallbackPersistent](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackpersistent)

[TpSetCallbackPriority](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackpriority)

[TpSetCallbackRaceWithDll](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackracewithdll)

[TpSetCallbackThreadpool](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackthreadpool)