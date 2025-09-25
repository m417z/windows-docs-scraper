# CM_Unregister_Notification function

## Description

Use [UnregisterDeviceNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unregisterdevicenotification) instead of **CM_Unregister_Notification** if your code targets Windows 7 or earlier versions of Windows.

The **CM_Unregister_Notification** function closes the specified HCMNOTIFICATION handle.

## Parameters

### `NotifyContext` [in]

The HCMNOTIFICATION handle returned by the [CM_Register_Notification](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_register_notification) function.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

Do not call **CM_Unregister_Notification** from a notification callback. Doing so may cause a deadlock because **CM_Unregister_Notification** waits for pending callbacks to finish.

Instead, if you want to unregister from the notification callback, you must do so asynchronously. The following sequence shows one way to do this:

1. Allocate a context structure to use with your notifications. Include a pointer to a threadpool work structure (**PTP_WORK**) and any other information you would like to pass to the notification callback.
2. Call [CreateThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwork). Provide a callback function that calls **CM_Unregister_Notification**. Add the returned work structure to the previously allocated context structure.
3. Call [CM_Register_Notification](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_register_notification) and provide the context structure as the *pContext* parameter.
4. Do work, get notifications, etc.
5. Call [SubmitThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-submitthreadpoolwork) from within the notification callback, providing the pointer to a threadpool work structure (**PTP_WORK**) stored in your context structure.
6. When the threadpool thread runs, the work item calls **CM_Unregister_Notification**.
7. Call [CloseThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolwork) to release the work object.

If you are finished with the context structure, don't forget to release resources and free the structure.

**Caution** Do not free the context structure until after the work item has called **CM_Unregister_Notification**. You can still receive notifications after submitting the threadpool work item and before the work item calls **CM_Unregister_Notification**.

#### Examples

The following example shows how to unregister from the notification callback, as described in the Remarks section.

```
typedef struct _CALLBACK_CONTEXT {
    BOOL bUnregister;
    PTP_WORK pWork;
    HCMNOTIFICATION hNotify;
    CRITICAL_SECTION lock;
} CALLBACK_CONTEXT, *PCALLBACK_CONTEXT;

DWORD
WINAPI
EventCallback(
    __in HCMNOTIFICATION hNotification,
    __in PVOID Context,
    __in CM_NOTIFY_ACTION Action,
    __in PCM_NOTIFY_EVENT_DATA EventData,
    __in DWORD EventDataSize
    )
{
    PCALLBACK_CONTEXT pCallbackContext = (PCALLBACK_CONTEXT)Context;

   // unregister from the callback
    EnterCriticalSection(&(pCallbackContext->lock));

    // in case this callback fires before the registration call returns, make sure the notification handle is properly set
    Context->hNotify = hNotification;

    if (!pCallbackContext->bUnregister) {
        pCallbackContext->bUnregister = TRUE;
        SubmitThreadpoolWork(pCallbackContext->pWork);
    }

    LeaveCriticalSection(&(pCallbackContext->lock));

    return ERROR_SUCCESS;
};

VOID
CALLBACK
WorkCallback(
    _Inout_ PTP_CALLBACK_INSTANCE Instance,
    _Inout_opt_ PVOID Context,
    _Inout_ PTP_WORK pWork
    )
{
    PCALLBACK_CONTEXT pCallbackContext = (PCALLBACK_CONTEXT)Context;

    CM_Unregister_Notification(pCallbackContext->hNotify);
}

VOID NotificationFunction()
{
    CONFIGRET cr = CR_SUCCESS;
    HRESULT hr = S_OK;
    CM_NOTIFY_FILTER NotifyFilter = { 0 };
    BOOL bShouldUnregister = FALSE;
    PCALLBACK_CONTEXT context;

    context = (PCALLBACK_CONTEXT)HeapAlloc(GetProcessHeap(),
                                           HEAP_ZERO_MEMORY,
                                           sizeof(CALLBACK_CONTEXT));
    if (context == NULL) {
        goto end;
    }

    InitializeCriticalSection(&(context->lock));

    NotifyFilter.cbSize = sizeof(NotifyFilter);
    NotifyFilter.Flags = 0;
    NotifyFilter.FilterType = CM_NOTIFY_FILTER_TYPE_DEVICEINSTANCE;
    NotifyFilter.Reserved = 0;

    hr = StringCchCopy(NotifyFilter.u.DeviceInstance.InstanceId,
                       MAX_DEVICE_ID_LEN,
                       TEST_DEVICE_INSTANCE_ID);
    if (FAILED(hr)) {
        goto end;
    }

    context->pWork = CreateThreadpoolWork(WorkCallback, context, NULL);
    if (context->pWork == NULL) {
        goto end;
    }

    cr = CM_Register_Notification(&NotifyFilter,
                                  context,
                                  EventCallback,
                                  &context->hNotify);
   if (cr != CR_SUCCESS) {
        goto end;
    }

    // ... do work here ...

    EnterCriticalSection(&(context->lock));

    if (!context->bUnregister) {
        // unregister not from the callback
        bShouldUnregister = TRUE;
        context->bUnregister = TRUE;
    }

    LeaveCriticalSection(&(context->lock));

    if (bShouldUnregister) {
        cr = CM_Unregister_Notification(context->hNotify);
        if (cr != CR_SUCCESS) {
            goto end;
        }
    } else {
        // if the callback is the one performing the unregister, wait for the threadpool work item to complete the unregister
        WaitForThreadpoolWorkCallbacks(context->pWork, FALSE);
    }

end:

    if (context != NULL) {
        if (context->pWork != NULL) {
            CloseThreadpoolWork(context->pWork);
        }

        DeleteCriticalSection(&(context->lock));

        HeapFree(GetProcessHeap(), 0, context);
    }

    return;
}

```

## See also

[UnregisterDeviceNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unregisterdevicenotification)