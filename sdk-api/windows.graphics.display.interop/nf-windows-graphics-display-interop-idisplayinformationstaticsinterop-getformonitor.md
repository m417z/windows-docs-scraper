## Description

Retrieves a [DisplayInformation](https://learn.microsoft.com/uwp/api/windows.graphics.display.displayinformation) object for the specified monitor. **GetForMonitor** always allocates and returns a new **DisplayInformation**.

## Parameters

### `monitor`

Type: \[in]\ **[HMONITOR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The monitor's handle.

### `riid`

Type: \[in]\ **[REFIID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/bbde795f-5398-42d8-9f59-3613da03c318)**

The **GUID** of the [DisplayInformation](https://learn.microsoft.com/uwp/api/windows.graphics.display.displayinformation) class.

### `displayInfo`

Type: \[iid_is\]\[retval\]\[out\] **[void](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\*\***

A pointer to a memory block that receives a pointer to the returned [DisplayInformation](https://learn.microsoft.com/uwp/api/windows.graphics.display.displayinformation) object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

## Remarks

Considerations:

* Window movements are not tracked, since there is no window.
* Any scale factor returned by the [DisplayInformation](https://learn.microsoft.com/uwp/api/windows.graphics.display.displayinformation) is the current scale factor for the entire monitor. DPI virtualization acts in the same way as for [GetScaleFactorForMonitor](https://learn.microsoft.com/windows/win32/api/shellscalingapi/nf-shellscalingapi-getscalefactorformonitor), which is the underlying API used to read scale in this case.
* If you wish to register for events, then the current thread must have a [Windows.System.DispatcherQueue](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueue) running, in order to receive events. That **DispatcherQueue** will be snapped upon the call to **GetForMonitor**. If there is no **DispatcherQueue**, then an exception (at the application binary interface level, a **HRESULT**) is returned in the event handler registration methods.
* The current thread can be MTA or STA.

You're responsible for: caching the created **DisplayInformation** for as long as the argument of *monitor* is relevant; de-registering event handlers; and dropping the last reference in order to destroy the **DisplayInformation** instance.

## Examples

See the code example in [IDisplayInformationStaticsInterop::GetForWindow](https://learn.microsoft.com/windows/win32/api/windows.graphics.display.interop/nf-windows-graphics-display-interop-idisplayinformationstaticsinterop-getforwindow).

## See also