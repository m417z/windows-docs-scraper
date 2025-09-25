# TpSetCallbackCleanupGroup function

## Description

Associates the specified cleanup group with the specified callback environment.

## Parameters

### `CallbackEnviron` [in, out]

A **TP_CALLBACK_ENVIRON** structure that defines the callback environment. The [TpInitializeCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpinitializecallbackenviron) function returns this structure.

### `CleanupGroup` [in]

A **TP_CLEANUP_GROUP** structure that defines the cleanup group. The [CreateThreadpoolCleanupGroup](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolcleanupgroup) function returns this structure.

### `CleanupGroupCancelCallback` [in, optional]

The cleanup callback to be called if the cleanup group is canceled before the associated object is released. The function is called when you call [CloseThreadpoolCleanupGroupMembers](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolcleanupgroupmembers).

## Remarks

This function is implemented as an inline function.

## See also

[TpDestroyCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpdestroycallbackenviron)

[TpInitializeCallbackEnviron](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpinitializecallbackenviron)

[TpSetCallbackActivationContext](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackactivationcontext)

[TpSetCallbackFinalizationCallback](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackfinalizationcallback)

[TpSetCallbackLongFunction](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbacklongfunction)

[TpSetCallbackNoActivationContext](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbacknoactivationcontext)

[TpSetCallbackPersistent](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackpersistent)

[TpSetCallbackPriority](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackpriority)

[TpSetCallbackRaceWithDll](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackracewithdll)

[TpSetCallbackThreadpool](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-tpsetcallbackthreadpool)