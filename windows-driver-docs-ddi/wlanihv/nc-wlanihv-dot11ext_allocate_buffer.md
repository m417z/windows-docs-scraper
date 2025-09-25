# DOT11EXT_ALLOCATE_BUFFER callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtAllocateBuffer** function to allocate memory for variable-length
buffers.

## Parameters

### `dwByteCount` [in]

Size, in bytes, of the buffer to allocate.

### `ppvBuffer` [out]

A pointer to a caller-supplied variable that stores the address of the allocated buffer. The
*ppvBuffer* parameter has a valid non-null value if the return value is ERROR_SUCCESS.

## Return value

The call returns an ERROR_xxxx code defined in
Winerror.h. The following ERROR_xxxx codes are commonly returned by the
**Dot11ExtAllocateBuffer** function.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The call succeeded without an error. |
| **ERROR_OUTOFMEMORY** | The operating system was unable to allocate the memory due to a lack of resources. |

## Prototype

```cpp
DWORD WINAPI * Dot11ExtAllocateBuffer(
  _In_  DWORD  dwByteCount,
  _Out_ LPVOID *ppvBuffer
);
```

## Remarks

The IHV Extensions DLL must follow these guidelines when calling the
**Dot11ExtAllocateBuffer** function.

* The IHV Extensions DLL must call this function when returning any variable-length buffer from an IHV
  Handler function. In this situation, the operating system is responsible for freeing the buffer after
  the return of the IHV Handler function.

  For more information about the IHV Handler functions, see
  [Native 802.11 IHV Handler
  Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions).
* The IHV Extensions DLL might call this function to allocate memory referenced by the DLL itself.

  In this situation, the DLL must free the memory buffer by calling
  [Dot11ExtFreeBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_free_buffer).

## See also

[Native 802.11 IHV Handler
Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions)

[Dot11ExtIhvCreateDiscoveryProfiles](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_create_discovery_profiles)

[Dot11ExtFreeBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_free_buffer)