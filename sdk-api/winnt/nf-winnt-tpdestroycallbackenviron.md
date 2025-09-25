# TpDestroyCallbackEnviron function

## Description

Deletes the specified callback environment. Call this function when the callback environment is no longer needed for creating new thread pool objects.

## Parameters

### `CallbackEnviron` [in]

A **TP_CALLBACK_ENVIRON** structure that defines the callback environment. The [TpInitializeCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpinitializecallbackenviron) function returns this structure.

## See also

[TpInitializeCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpinitializecallbackenviron)

[TpSetCallbackActivationContext](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackactivationcontext)

[TpSetCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackcleanupgroup)

[TpSetCallbackFinalizationCallback](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackfinalizationcallback)

[TpSetCallbackLongFunction](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbacklongfunction)

[TpSetCallbackNoActivationContext](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbacknoactivationcontext)

[TpSetCallbackPersistent](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackpersistent)

[TpSetCallbackPriority](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackpriority)

[TpSetCallbackRaceWithDll](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackracewithdll)

[TpSetCallbackThreadpool](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackthreadpool)