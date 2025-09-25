# WlanIhvControl function

## Description

The **WlanIhvControl** function provides a mechanism for independent hardware vendor (IHV) control of WLAN drivers or services.

## Parameters

### `hClientHandle` [in]

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

The GUID of the interface.

### `Type` [in]

 A [WLAN_IHV_CONTROL_TYPE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_ihv_control_type-r1) structure that specifies the type of software bypassed by the IHV control function.

### `dwInBufferSize` [in]

The size, in bytes, of the input buffer.

### `pInBuffer` [in]

A generic buffer for driver or service interface input.

### `dwOutBufferSize` [in]

The size, in bytes, of the output buffer.

### `pOutBuffer` [in, out, optional]

A generic buffer for driver or service interface output.

### `pdwBytesReturned` [out]

The number of bytes returned.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient permissions to perform this operation. When called, [WlanIhvControl](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanihvcontrol) retrieves the discretionary access control list (DACL) stored with the **wlan_secure_ihv_control** object. If the DACL does not contain an access control entry (ACE) that grants WLAN_WRITE_ACCESS permission to the access token of the calling thread, then **WlanIhvControl** returns **ERROR_ACCESS_DENIED**. |
| **ERROR_INVALID_PARAMETER** | *hClientHandle* is **NULL** or invalid, *pInterfaceGuid* is **NULL**, or *pdwBytesReturned* is **NULL**. |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **ERROR_NOT_SUPPORTED** | This function was called from an unsupported platform. This value will be returned if this function was called from a Windows XP with SP3 or Wireless LAN API for Windows XP with SP2 client. |
| **RPC_STATUS** | Various error codes. |

## See also

[WLAN_IHV_CONTROL_TYPE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_ihv_control_type-r1)