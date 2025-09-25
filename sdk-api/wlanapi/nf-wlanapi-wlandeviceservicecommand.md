## Description

Allows an original equipment manufacturer (OEM) or independent hardware vendor (IHV) component to communicate with a device service on a particular wireless LAN interface.

## Parameters

### `hClientHandle` [in]

Type: **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The client's session handle, obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pInterfaceGuid` [in]

Type: **CONST [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)\***

A pointer to the **GUID** of the wireless LAN interface to be queried. You can determine the **GUID** of each wireless LAN interface enabled on a local computer by using the [WlanEnumInterfaces](https://learn.microsoft.com/windows/win32/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function.

### `pDeviceServiceGuid` [in]

Type: **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)\***

The **GUID** identifying the device service for this command.

### `dwOpCode` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The operational code identifying the operation to be performed on the device service.

### `dwInBufferSize` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size, in bytes, of the input buffer.

### `pInBuffer` [in]

Type: **[PVOID](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A generic buffer for command input.

### `dwOutBufferSize` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size, in bytes, of the output buffer.

### `pOutBuffer` [in, out, optional]

Type: **[PVOID](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A generic buffer for command output.

### `pdwBytesReturned` [out]

Type: **[PDWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of bytes returned.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, the return value is **ERROR_SUCCESS**. If the function fails with **ERROR_ACCESS_DENIED**, then the caller doesn't have sufficient permissions to perform this operation. The caller needs to either have admin privilege, or needs to be a UMDF driver.

## Remarks

## See also