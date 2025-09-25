# IDXGIDevice2::EnqueueSetEvent

## Description

Flushes any outstanding rendering commands and sets the specified event object to the signaled state after all previously submitted rendering commands complete.

## Parameters

### `hEvent` [in]

A handle to the event object. The [CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) or [OpenEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-openeventa) function returns this handle. All types of event objects (manual-reset, auto-reset, and so on) are supported.

The handle must have the EVENT_MODIFY_STATE access right. For more information about access rights, see [Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

## Return value

Returns **S_OK** if successful; otherwise, returns one of the following values:

* **E_OUTOFMEMORY** if insufficient memory is available to complete the operation.
* **E_INVALIDARG** if the parameter was validated and determined to be incorrect.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **EnqueueSetEvent** fails with E_NOTIMPL. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## Remarks

**EnqueueSetEvent** calls the [SetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setevent) function on the event object after all previously submitted rendering commands complete or the device is removed.

After an application calls **EnqueueSetEvent**, it can immediately call the [WaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject) function to put itself to sleep until rendering commands complete.

You cannot use **EnqueueSetEvent** to determine work completion that is associated with presentation ([IDXGISwapChain::Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present)); instead, we recommend that you use [IDXGISwapChain::GetFrameStatistics](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-getframestatistics).

#### Examples

The following example code shows how to use **EnqueueSetEvent**.

```
void BlockingFinish( IDXGIDevice2* pDevice )
{
    // Create a manual-reset event object.
    hEvent = CreateEvent(
        NULL,               // default security attributes
        TRUE,               // manual-reset event
        FALSE,              // initial state is nonsignaled
        FALSE
        );

    if (hEvent == NULL)
    {
        printf("CreateEvent failed (%d)\n", GetLastError());
        return;
    }

    pDevice->EnqueueSetEvent(hEvent);

    DWORD dwWaitResult = WaitForSingleObject(
        hEvent, // event handle
        INFINITE);    // indefinite wait

    switch (dwWaitResult)
    {
        // Event object was signaled
        case WAIT_OBJECT_0:
            // Commands completed
            break;

        // An error occurred
        default:
            printf("Wait error (%d)\n", GetLastError());
            return 0;
    }

    CloseHandle(hEvent);
}

```

## See also

[IDXGIDevice2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgidevice2)