## Description

A printer interface DLL's **DrvSplDeviceCaps** function queries a printer for its capabilities.

## Parameters

### `hPrinter`

Caller-supplied handle to the printer.

### `pszDeviceName` [in]

Caller-supplied pointer to a Unicode string that contains the printer name.

### `Capability`

Caller-supplied bit flag that indicates the capability to query for. (The flags are defined in header file wingdi.h.) This function is not required to support all of the DC_*XXX* flags, but it must support those listed in the following table.

| Flag | Definition |
|---|---|
| DC_MEDIAREADY | The *pOutput* parameter points to a buffer that the function should fill with an array of string buffers, each 64 characters in length. Each array element should contain a NULL-terminated string representing a name for a paper form that is available for use. The function's return value should be the number of elements in the returned array. If *pOutput* is **NULL**, the function should just return the number of array elements required. |
| DC_PAPERNAMES | The *pOutput* parameter points to a buffer that the function should fill with an array of string buffers, each 64 characters in length. Each array element should contain a NULL-terminated string representing a name for a paper form. The function's return value should be the number of elements in the returned array. If *pOutput* is **NULL**, the function should just return the number of array elements required. |

### `pOutput` [out, optional]

Caller-supplied pointer to a buffer that receives function-supplied information. The buffer's use depends on the value of the *Capability* parameter. The caller is responsible for allocating and freeing this buffer.

### `cchBufSize`

Caller-supplied size (in characters) of the buffer pointed to by the *pOutput* parameter.

### `pDevmode` [in, optional]

Caller-supplied pointer to a [**DEVMODEW**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure that describes the current print job characteristics. If **NULL**, the function should use the driver's internal default DEVMODEW structure.

## Return value

The return value depends on the *Capability* parameter. If *Capability* indicates a capability that the driver does not support, or if an error is encountered, the function should return GDI_ERROR.

## Remarks

For descriptions of the DC_*XXX* flags, see [DrvDeviceCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdevicecapabilities).

This function must be defined in the .def file as DrvSplDeviceCaps @ 254, because the spooler uses the ordinal number 254 to obtain the driver function pointer.

## See also

[DrvDeviceCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdevicecapabilities)