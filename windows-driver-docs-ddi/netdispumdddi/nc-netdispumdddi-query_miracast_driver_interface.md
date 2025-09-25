# QUERY_MIRACAST_DRIVER_INTERFACE callback function

## Description

Called by the operating system to query the Miracast user-mode driver interface, [MIRACAST_DRIVER_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-_miracast_driver_interface).

## Parameters

### `MiracastDriverInterfaceVersion` [in]

The version of the Miracast display interface, supplied by the operating system.

This version is defined in Netdispumdddi.h as a **MIRACAST_DRIVER_INTERFACE_VERSION_XXX** value. For Windows 8.1, the value is **MIRACAST_DRIVER_INTERFACE_VERSION_1**.

### `MiracastDriverInterfaceSize` [in]

The size, supplied by the operating system, of the buffer pointed to by *pMiracastDriverInterface*.

### `pMiracastDriverInterface` [out]

A pointer to a buffer, supplied by the operating system, that holds the returned Miracast display driver interface, which is a structure of type [MIRACAST_DRIVER_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-_miracast_driver_interface).

## Return value

On success, this function returns **STATUS_SUCCESS**. Otherwise, the function returns an error code defined in the Ntstatus.h header.

## Remarks

When the Miracast user-mode driver is loaded, the operating system calls the [GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) function with "QueryMiracastDriverInterface" entered as the function name in the *lpProcName* parameter.

**Note** If the Miracast user-mode driver doesn't supply a function with this name, the operating system fails the Miracast display device.

## See also

[GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress)

[MIRACAST_DRIVER_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-_miracast_driver_interface)