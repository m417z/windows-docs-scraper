# DOT11EXTIHV_CONTROL callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the IHV Extensions DLL
*Dot11ExtIhvControl* function to allow independent hardware vendor (IHV) control of WLAN drivers or
services.

## Parameters

### `hIhvExtAdapter` [in, optional]

The handle used by the IHV Extensions DLL to reference the WLAN adapter. This handle value was
specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV Handler function.

### `dwInBufferSize` [in]

The size, in bytes, of the input control buffer pointed to by the
*pInBuffer* parameter.

### `pInBuffer` [in, optional]

A pointer to the input control buffer.

### `dwOutBufferSize` [in]

The size, in bytes, of the output buffer (if provided) pointed to by the
*pOutBuffer* parameter.

### `pOutBuffer` [out, optional]

A pointer to the output buffer, if provided.

### `pdwBytesReturned` [out]

A pointer to a variable that contains the size, in bytes, of the response input/output
buffer.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_CONTROL Dot11ExtIhvControl;

DWORD APIENTRY Dot11ExtIhvControl(
  _In_opt_  HANDLE hIhvExtAdapter,
  _In_      DWORD  dwInBufferSize,
  _In_opt_  PBYTE  pInBuffer,
  _In_      DWORD  dwOutBufferSize,
  _Out_opt_ PBYTE  pOutBuffer,
  _Out_     DWORD  pdwBytesReturned
)
{ ... }
```

## Remarks

The operating system calls this function when the
**WlanIhvControl** function is called with the
*Type* parameter set to a value of
**wlan_ihv_control_type_service**. For a description of the
**WlanIhvControl** function, see the Microsoft Windows SDK documentation.

Data transferred with this function is not validated, so the IHV is responsible for correctly parsing
the input buffer.

The data buffer pointed to by the
*pdwBytesReturned* parameter will always be returned. However, the buffer pointed to by
*pOutBuffer* will be copied only if a valid pointer is provided and the value pointed to by
*pdwBytesReturned* is less than or equal to
*dwOutBufferSize* .

## See also

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)