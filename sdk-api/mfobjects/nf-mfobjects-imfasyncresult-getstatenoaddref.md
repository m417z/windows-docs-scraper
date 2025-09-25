# IMFAsyncResult::GetStateNoAddRef

## Description

Returns the state object specified by the caller in the asynchronous **Begin** method, without incrementing the object's reference count.

## Return value

Returns a pointer to the state object's **IUnknown** interface, or **NULL** if no object was set. This pointer does not have an outstanding reference count. If you store this pointer, you must call **AddRef** on the pointer.

## Remarks

This method cannot be called remotely.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Asynchronous Callback Methods](https://learn.microsoft.com/windows/desktop/medfound/asynchronous-callback-methods)

[IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult)