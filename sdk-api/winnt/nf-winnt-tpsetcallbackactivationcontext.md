# TpSetCallbackActivationContext function

## Description

Assigns an activation context to the callback environment.

## Parameters

### `CallbackEnviron` [in, out]

A **TP_CALLBACK_ENVIRON** structure that defines the callback environment. The [TpInitializeCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpinitializecallbackenviron) function returns this structure.

### `ActivationContext` [in, optional]

Pointer to an **_ACTIVATION_CONTEXT** structure.

## Remarks

This function is implemented as an inline function.

## See also

[TpDestroyCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpdestroycallbackenviron)

[TpInitializeCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpinitializecallbackenviron)

[TpSetCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackcleanupgroup)

[TpSetCallbackFinalizationCallback](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackfinalizationcallback)

[TpSetCallbackLongFunction](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbacklongfunction)

[TpSetCallbackNoActivationContext](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbacknoactivationcontext)

[TpSetCallbackPersistent](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackpersistent)

[TpSetCallbackPriority](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackpriority)

[TpSetCallbackRaceWithDll](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackracewithdll)

[TpSetCallbackThreadpool](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackthreadpool)