# WlanGetInterfaceCapability function

## Description

The **WlanGetInterfaceCapability** function retrieves the capabilities of an interface.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

The GUID of this interface.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

### `ppCapability` [out]

A [WLAN_INTERFACE_CAPABILITY](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_interface_capability) structure that contains information about the capabilities of the specified interface.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | *hClientHandle* is **NULL** or invalid, *pInterfaceGuid* is **NULL**, *pReserved* is not **NULL**, or *ppCapability* is **NULL**. |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **ERROR_NOT_SUPPORTED** | This function was called from an unsupported platform. This value will be returned if this function was called from a Windows XP with SP3 or Wireless LAN API for Windows XP with SP2 client. |
| **RPC_STATUS** | Various error codes. |

## Remarks

The caller is responsible for calling the [WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory) function to free the memory allocated to *ppCapability*.