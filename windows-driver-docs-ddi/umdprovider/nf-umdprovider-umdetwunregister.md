# UMDEtwUnregister function

## Description

Unregisters the event trace provider. Call this function before the user-mode driver is unloaded. After this function is called, the driver should not make any other calls to log events.

## Remarks

**UMDEtwUnregister** is defined inline in Umdprovider.h as:

```cpp
// Registration handle, returned by EventRegister and passed to EventUnregister
__declspec(selectany) REGHANDLE RegHandle = NULL;

FORCEINLINE void UMDEtwUnregister()
{
    EventUnregister(RegHandle);
}
```

The [EventUnregister](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventunregister) function is described in the [Windows Events](https://learn.microsoft.com/windows/desktop/Events/windows-events) documentation.

## See also

[UMDEtwRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/umdprovider/nf-umdprovider-umdetwregister)