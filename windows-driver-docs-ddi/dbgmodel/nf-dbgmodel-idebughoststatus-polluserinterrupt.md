# IDebugHostStatus::PollUserInterrupt

## Description

The PollUserInterrupt method is used to inquire whether the user of the debug host has requested an interruption of the current operation. A property accessor in the data model may, for instance, call into arbitrary code (e.g.: a JavaScript method). That code may take an arbitrary amount of time. In order to keep the debug host responsive, any such code which may take an arbitrary amount of time should check for an interrupt request via calling this method. If the interruptRequested value comes back as true, the caller should immediately abort and return a result of E_ABORT.

It is important that any caller of data model APIs which receives an error of E_ABORT propagate that error outward and not swallow just it.

Certain hosts (in particular, Debugging Tools for Windows) may opt to fail inquiries which occur while an interrupt is pending. In such circumstances, many method calls to [IDebugHost](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughost)* interfaces will return E_ABORT until control has returned to the debug host.

## Parameters

### `interruptRequested`

An indication of whether or not a user interrupt is pending is returned. If the returned value is true, the caller should immediately stop what it is doing and propagate the E_ABORT error code outward.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Sample Code**

```cpp
// within some method...
ComPtr<IDebugHost> spHost; /* get the host*/

ComPtr<IDebugHostStatus> spStatus;
spHost.As(&spStatus);

bool isInterruptRequested;
if (spStatus != nullptr && SUCCEEDED(spStatus->PollUserInterrupt(&isInterruptRequested)) && isInterruptRequested)
{
    // This is the return code to indicate a user initiated abort.
    return E_ABORT;
}
```

## See also

[IDebugHostStatus interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughoststatus)