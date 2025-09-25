# DOT11EXT_NIC_SPECIFIC_EXTENSION callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtNicSpecificExtension** function to issue proprietary NDIS 6.0 method
requests to the Native 802.11 miniport driver that manages a wireless LAN (WLAN) adapter.

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the WLAN adapter. This handle value was
specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `dwInBufferSize` [in]

The size, in bytes, of the caller-allocated data buffer referenced by the
*pvInBuffer* parameter.

### `pvInBuffer` [in]

A pointer to a caller-allocated input buffer that contains the data required to perform the
operation. The format of this data is defined by the IHV.

### `pdwOutBufferSize` [in, out]

A pointer to a caller-allocated DWORD variable. When the
**Dot11ExtNicSpecificExtension** function is called, the IHV Extensions DLL
must set this variable to the size, in bytes, of the caller-allocated data buffer referenced by the
*pvOutBuffer* parameter. When the function returns, the operating system sets the variable to the
actual number of bytes returned in the data buffer referenced by the
*pvOutBuffer* parameter.

### `pvOutBuffer` [out]

A pointer to a caller-allocated buffer that contains data returned from the Native 802.11 miniport
driver for the specified request. The format of this data is defined by the IHV. This parameter can be
**NULL** if data is not to be returned by the Native 802.11 miniport driver.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtNicSpecificExtension(
  _In_opt_ HANDLE hDot11SvcHandle,
  _In_     DWORD  dwInBufferSize,
  _In_     LPVOID pvInBuffer,
  _Inout_  DWORD  *pdwOutBufferSize,
  _Out_    LPVOID pvOutBuffer
);
```

## Remarks

The
**Dot11ExtNicSpecificExtension** function allows the IHV Extensions DLL to
pass proprietary method requests to the Native 802.11 miniport driver, which is referenced by the
*hDot11SvcHandle* parameter. The operating system issues the method request through the Native 802.11
[OID_DOT11_NIC_SPECIFIC_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-nic-specific-extension) object identifier (OID).

**Note** OID_DOT11_NIC_SPECIFIC_EXTENSION is an optional OID for support by the Native
802.11 miniport driver. If the driver does not support this OID,
**Dot11ExtNicSpecificExtension** will return a value of ERROR_NOT_SUPPORTED.

## See also

[OID_DOT11_NIC_SPECIFIC_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-nic-specific-extension)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)