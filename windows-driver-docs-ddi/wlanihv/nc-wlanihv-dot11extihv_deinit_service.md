# DOT11EXTIHV_DEINIT_SERVICE callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvDeinitService* function to halt the IHV Extensions DLL.

## Parameters

## Prototype

```cpp
DOT11EXTIHV_DEINIT_SERVICE Dot11ExtIhvDeinitService;

VOID APIENTRY Dot11ExtIhvDeinitService(
   VOID
)
{ ... }
```

## Remarks

When the
*Dot11ExtIhvDeinitService* function is called, the IHV Extensions DLL must be brought to a state that
it can safely be unloaded by the operating system. The DLL must follow these guidelines when this
function is called.

* The operating system calls the
  [Dot11ExtIhvDeinitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_adapter) function prior to calling the
  *Dot11ExtIhvDeinitService* function. As a result, the
  *Dot11ExtIhvDeinitService* function should not initiate any operations on the WLAN adapter.
  Instead,
  *Dot11ExtIhvDeinitService* should prepare the DLL to be unloaded by the operating system.
* The DLL must terminate all executing threads that it created. The DLL must not return from the
  *Dot11ExtIhvDeinitService* function call until all threads have been terminated.
* The DLL must free any allocated resources for the DLL itself. In particular, all memory the DLL
  allocated through calls to
  [Dot11ExtAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_allocate_buffer) must be
  freed through calls to
  [Dot11ExtFreeBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_free_buffer).

## See also

[Dot11ExtAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_allocate_buffer)

[Dot11ExtIhvDeinitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_adapter)

[Dot11ExtFreeBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_free_buffer)