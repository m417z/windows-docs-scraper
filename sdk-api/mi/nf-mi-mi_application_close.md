# MI_Application_Close function

## Description

Deinitializes the management infrastructure client API that was initialized through a call to [MI_Application_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_initializev1).

## Parameters

### `application` [in, out]

Application handle that was initialized through a call to [MI_Application_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_initializev1).

## Return value

This function returns MI_INLINE MI_Result.

## Remarks

**MI_Application_Close** will unload the entire protocol handling infrastructure and background threads associated with the infrastructure.

**MI_Application_Close** cancels all active sessions and operations. Sessions created under the target application and those sessions' operations must close before this function will return. Once the API does so, Mi.dll can be unloaded and any caches held within the MI infrastructure are flushed.

**MI_Application_Close** must not be called from within an asynchronous callback, otherwise it will cause deadlocks.

To avoid a system hang when calling this function, reference count [MI_Application](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_application) and call the **MI_Application_Close** function only when the AppDomain is shutting down and after all sessions have been closed.