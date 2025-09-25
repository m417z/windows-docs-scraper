# CertControlStore function

## Description

The **CertControlStore** function allows an application to be notified when there is a difference between the contents of a cached store in use and the contents of that store as it is persisted to storage. Differences can occur as another [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) makes a change that affects the store as it is persisted.

The **CertControlStore** function can be used to synchronize a cached store, if necessary, and provides a means to commit changes made in the cached store to persisted storage.

## Parameters

### `hCertStore` [in]

Handle of the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `dwFlags` [in]

If the *dwCtrlType* parameter is set to CERT_STORE_CTRL_COMMIT, this parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_CTRL_COMMIT_FORCE_FLAG** | Forces the contents of the cache memory store to be copied to permanent storage even if the cache has not been changed. |
| **CERT_STORE_CTRL_COMMIT_CLEAR_FLAG** | Inhibits the copying of the contents of the cache memory store to permanent storage even when the store is closed. |
| **CERT_STORE_CTRL_INHIBIT_DUPLICATE_HANDLE_FLAG** | Inhibits a duplicate handle of the event HANDLE. If this flag is set, **CertControlStore** with CERT_STORE_CTRL_CANCEL_NOTIFY passed must be called for this event HANDLE before closing the *hCertStore* handle. |

If *dwCtrlType* is set to CERT_STORE_CTRL_NOTIFY_CHANGE or CERT_STORE_CTRL_RESYNC, the *dwFlags* parameter is not used and must be set to zero.

### `dwCtrlType` [in]

Control action to be taken by **CertControlStore**. The interpretations of *pvCtrlPara* and *dwFlags* depend on the value of *dwCtrlType*. Currently, the following actions are defined.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_CTRL_RESYNC** | The cached store is resynchronized and made to match the persisted store. |
| **CERT_STORE_CTRL_NOTIFY_CHANGE** | A signal is returned in the space pointed to by *pvCtrlPara* to indicate that the current contents of the cached store differ from the store's persisted [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). |
| **CERT_STORE_CTRL_COMMIT** | Any changes made to the cached store are copied to persisted storage. If no changes were made since the cached store was opened or since the last commit, the call is ignored. The call is also ignored if the store provider is a provider that automatically persists changes immediately. |
| **CERT_STORE_CTRL_AUTO_RESYNC** | At the start of every enumeration or find store call, a check is made to determine whether a change has been made in the store. If the store has changed, a re-synchronization is done. This check is only done on first enumeration or find calls, when the *pPrevContext* is **NULL**.<br><br>The **pvCtrPara** member is not used and must be set to **NULL**. |
| **CERT_STORE_CTRL_CANCEL_NOTIFY** | Cancels notification signaling of the event HANDLE passed in a previous CERT_STORE_CTRL_NOTIFY_CHANGE or CERT_STORE_CTRL_RESYNC. The *pvCtrlPara* parameter points to the event HANDLE to be canceled. |

### `pvCtrlPara` [in]

If *dwCtrlType* is CERT_STORE_NOTIFY_CHANGE, *pvCtrlPara* is set to the address of a handle where the system signals the notification change event when a change from the persisted [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the store is detected. The handle must be initialized with a call to the function [CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa). The *pvCtrlPara* parameter can be set to **NULL** for registry-based stores. If *pvCtrlPara* is **NULL**, an internal notification change event is created and registered to be signaled. Using the internal notification change event allows resynchronization operations only if the store was changed.

If *dwCtrlType* is CERT_STORE_CTRL_RESYNC, set *pvCtrlPara* to the address of the event handle to be signaled on the next change in the persisted store. Typically, this address is the address of the event handle passed with CERT_STORE_CTRL_NOTIFY_CHANGE during initialization. The event handle passed is rearmed. If *pvCtrlPara* is set to **NULL**, no event is rearmed.

If *dwCtrlType* CERT_STORE_CTRL_COMMIT, *pvCtrlPara* is not used and must be set to **NULL**.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If *dwCtrlType* is CERT_STORE_NOTIFY_CHANGE, the function returns nonzero if a handle for the event signal was successfully set up. The function returns zero if the event handle was not set up.

If *dwCtrlType* is CERT_STORE_CTRL_RESYNC, the function returns nonzero if the resynchronization succeeded. The function returns zero if the resynchronization failed.

If *dwCtrlType* is CERT_STORE_CTRL_COMMIT, the function returns nonzero to indicate the successful completion of the commit to persisted storage. The function returns zero if the commit failed.

Some providers might not support specific control types. In these cases, **CertControlStore** returns zero and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) is set to the ERROR_NOT_SUPPORTED code.

## Remarks

Resynchronization of a store can be done at any time. It need not follow a signaled notification change event.

CERT_STORE_CTRL_NOTIFY_CHANGE is supported on registry-based store providers by using the [RegNotifyChangeKeyValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regnotifychangekeyvalue) function.

**CertControlStore** using CERT_STORE_CTRL_NOTIFY_CHANGE is called once for each event handle to be passed with CERT_STORE_CTRL_RESYNC. These calls using CERT_STORE_CTRL_NOTIFY_CHANGE must be made after each event is created and not after an event has been signaled.

#### Examples

The following example shows allowing an application to be notified when there is a difference between the contents of a cached store in use and the contents of that store as it is persisted to storage. For the full example including the complete context for this example, see
[Example C Program: Setting and Getting Certificate Store Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-setting-and-getting-certificate-store-properties).

```cpp

//--------------------------------------------------------------------
// Declare and initialize variables.

HCERTSTORE hCertStore;     // Original certificate store
HANDLE     hEvent;
BOOL       fSignal;

//--------------------------------------------------------------------
// Initialize an event.

if(hEvent = CreateEvent(
    NULL,
    FALSE,          // Manual reset is FALSE
    FALSE,          // The initial state of the event is FALSE
    NULL))
{
     printf("An event has been created. \n");
}
else
{
     printf("The event was not created. \n");
     exit(1);
}

//--------------------------------------------------------------------
// Open the MY certificate store.

if ( hCertStore = CertOpenStore(
    CERT_STORE_PROV_SYSTEM,
    0,
    NULL,
    CERT_SYSTEM_STORE_CURRENT_USER,
    L"MY"))
{
    printf("The MY store is open. \n");
}
else
{
    printf("The MY store did not open. \n");
    exit(1);
}

//--------------------------------------------------------------------
//  Call CertControlStore the first time with
//  CERT_CONTROL_STORE_NOTIFY_CHANGE.

if(CertControlStore(
    hCertStore,                        //  The store to be controlled
    0,                                 //  Not used
    CERT_STORE_CTRL_NOTIFY_CHANGE,     //  Control action type
    &hEvent))                          //  Points to the event handle
                           //  When a change is detected,
                           //  a signal is written to the
                    //  memory location pointed to by
                    //  hHandle.
{
    printf("Notify change worked. \n");
}
else
{
    printf("Notify change failed. \n");
    exit(1);
}

//--------------------------------------------------------------------
// Wait for the store to change.

fSignal = (WAIT_OBJECT_0 == WaitForSingleObjectEx(
    hEvent,
    1000,        // Number of milliseconds to wait;
            // Use INFINITE to wait indefinitely for
            // a change
    FALSE));

if (fSignal)
{

//--------------------------------------------------------------------
// The store has changed.
// Call the function a second time with CERT_STORE_CTRL_RESYNC.

    if(CertControlStore(
        hCertStore,             // The store to be controlled
        0,                      // Not used
        CERT_STORE_CTRL_RESYNC, // Control action type
        &hEvent))               // The handle of the event
                                // to be rearmed

    printf("Resynchronization worked. \n");

    else
    {
        printf("Resynchronization failed. \n");
        exit(1);
    }
}
else
{
      printf("The store was not changed. \n");
      printf("Resynchronization was not needed. \n");
}

// Release the handle to the store.

if(CertCloseStore(hCertStore,
                   0))
{
        printf("The MY store was closed. \n");
}
else
{
        printf("An error occurred. The MY store was not closed. \n");
}

```

## See also

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[WaitForSingleObjectEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobjectex)