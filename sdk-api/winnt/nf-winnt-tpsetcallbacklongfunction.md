# TpSetCallbackLongFunction function

## Description

Indicates that callbacks associated with this callback environment may not return quickly.

## Parameters

### `CallbackEnviron` [in, out]

A **TP_CALLBACK_ENVIRON** structure that defines the callback environment. The [TpInitializeCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpinitializecallbackenviron) function returns this structure.

## Remarks

The thread pool may use this information to better determine when a new thread should be created.

This function is implemented as an inline function.

## See also

[TpDestroyCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpdestroycallbackenviron)

[TpInitializeCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpinitializecallbackenviron)

[TpSetCallbackActivationContext](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackactivationcontext)

[TpSetCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackcleanupgroup)

[TpSetCallbackFinalizationCallback](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackfinalizationcallback)

[TpSetCallbackNoActivationContext](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbacknoactivationcontext)

[TpSetCallbackPersistent](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackpersistent)

[TpSetCallbackPriority](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackpriority)

[TpSetCallbackRaceWithDll](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackracewithdll)

[TpSetCallbackThreadpool](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackthreadpool)