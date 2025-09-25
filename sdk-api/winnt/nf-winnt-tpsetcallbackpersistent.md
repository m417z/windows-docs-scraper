# TpSetCallbackPersistent function

## Description

Specifies that the callback should run on a persistent thread.

## Parameters

### `CallbackEnviron` [in, out]

A **TP_CALLBACK_ENVIRON** structure that defines the callback environment. The [TpInitializeCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpinitializecallbackenviron) function returns this structure.

## Remarks

This function is implemented as an inline function.

## See also

[TpDestroyCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpdestroycallbackenviron)

[TpInitializeCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpinitializecallbackenviron)

[TpSetCallbackActivationContext](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackactivationcontext)

[TpSetCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackcleanupgroup)

[TpSetCallbackFinalizationCallback](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackfinalizationcallback)

[TpSetCallbackLongFunction](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbacklongfunction)

[TpSetCallbackNoActivationContext](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbacknoactivationcontext)

[TpSetCallbackPriority](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackpriority)

[TpSetCallbackRaceWithDll](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackracewithdll)

[TpSetCallbackThreadpool](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackthreadpool)