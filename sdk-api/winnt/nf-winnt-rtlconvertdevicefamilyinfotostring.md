## Description

Retrieves string representations of device family info.

## Parameters

### `pulDeviceFamilyBufferSize`

Type: _Inout_ **PDWORD**

The size of the buffer for the device family.

### `pulDeviceFormBufferSize`

Type: _Inout_ **PDWORD**

The size of the buffer for the device form.

### `DeviceFamily`

Type: _Out_writes_bytes_(*pulDeviceFamilyBufferSize) **PWSTR**

The retrieved device family.

### `DeviceForm`

Type: _Out_writes_bytes_(*pulDeviceFormBufferSize) **PWSTR**

The retrieved device form.

## Return value

Type: DWORD

A success or failure status.

## Remarks

At this time, this function doesn't have an associated library file. Your application can call [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name (`NtDll.dll`) to obtain a module handle. It can then call [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) with the module handle and the name of this function to get the function address.

## See also