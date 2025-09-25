# IRtwqAsyncResult::GetStateNoAddRef

## Description

Returns the state object specified by the caller in the asynchronous **Begin** method, without incrementing the object's reference count.

## Return value

Returns a pointer to the state object's **IUnknown** interface, or **NULL** if no object was set. This pointer does not have an outstanding reference count. If you store this pointer, you must call **AddRef** on the pointer.

## See also

[IRtwqAsyncResult](https://learn.microsoft.com/windows/desktop/api/rtworkq/nn-rtworkq-irtwqasyncresult)