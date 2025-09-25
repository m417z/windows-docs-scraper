## Description

Retrieves a list of the supported device services on a given wireless LAN interface.

## Parameters

### `hClientHandle` [in]

Type: **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

Type: **CONST [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)\***

A pointer to the **GUID** of the wireless LAN interface to be queried. You can determine the **GUID** of each wireless LAN interface enabled on a local computer by using the [WlanEnumInterfaces](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function.

### `ppDevSvcGuidList` [out]

Type: **[PWLAN_DEVICE_SERVICE_GUID_LIST](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_device_service_guid_list)\***

A pointer to storage for a pointer to receive the returned list of device service **GUID**s in a [WLAN_DEVICE_SERVICE_GUID_LIST](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_device_service_guid_list) structure. If the call succeeds, then the buffer for the **WLAN_DEVICE_SERVICE_GUID_LIST** returned is allocated by the **WlanGetSupportedDeviceServices** function.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, the return value is **ERROR_SUCCESS**. If the function fails with **ERROR_ACCESS_DENIED**, then the caller doesn't have sufficient permissions to perform this operation. The caller needs to either have admin privilege, or needs to be a UMDF driver.

## Remarks

If the call succeeds, then the **WlanGetSupportedDeviceServices** function allocates memory for the device services **GUID** list that's returned in a buffer pointed to by the *ppDevSvcGuidList* parameter. When you no longer need the buffer pointed to by *ppDevSvcGuidList*, you should release the memory used for it by calling the [WlanFreeMemory](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanfreememory) function.

## See also