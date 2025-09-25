# DOT11EXT_FREE_BUFFER callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtFreeBuffer** function to free memory allocated through a call to
[Dot11ExtAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_allocate_buffer).

## Parameters

### `pvMemory` [in, optional]

A pointer to the buffer to be freed. If the value of
*pvMemory* is **NULL**, the
**Dot11ExtFreeBuffer** function returns immediately.

## Prototype

```cpp
VOID WINAPI * Dot11ExtFreeBuffer(
  _In_opt_ LPVOID pvMemory
);
```

## Remarks

The IHV Extension DLL must not call the
**Dot11ExtFreeBuffer** function for any variable-length buffer allocated
within an IHV handler function and passed to the operating system through a parameter to the function. In
this situation, the operating system is responsible for freeing the buffer after the return of the IHV
Handler function.

For more information about the IHV Handler functions, see
[Native 802.11 IHV Handler
Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions).

## See also

[Native 802.11 IHV Handler
Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions)

[Dot11ExtAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_allocate_buffer)