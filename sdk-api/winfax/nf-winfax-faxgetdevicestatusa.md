# FaxGetDeviceStatusA function

## Description

The **FaxGetDeviceStatus** function returns to a fax client application current status information for the fax device of interest. The returned data includes, among other items, device and station identifiers, sender and recipient names, and routing information.

## Parameters

### `FaxPortHandle` [in]

Type: **HANDLE**

Specifies a fax port handle returned by a call to the [FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport) function.

### `DeviceStatus` [out]

Type: **PFAX_DEVICE_STATUS***

Pointer to the address of a buffer to receive a [FAX_DEVICE_STATUS](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_device_statusa) structure. The structure describes the status of one fax device. For information about memory allocation, see the following Remarks section

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or both of the *DeviceStatus* or *FaxPortHandle* parameters are **NULL**. |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_PORT_QUERY](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred during memory allocation. |

## Remarks

A fax administration application typically calls the **FaxGetDeviceStatus** function to display the status of a fax device associated with a fax server. The **FaxGetDeviceStatus** function allocates the memory required for the [FAX_DEVICE_STATUS](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_device_statusa) buffer pointed to by the *DeviceStatus* parameter. An application must call the [FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer) function to deallocate the resources associated with this parameter.

For more information, see [Fax Device Management](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-device-management) and [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

> [!NOTE]
> The winfax.h header defines FaxGetDeviceStatus as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_DEVICE_STATUS](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_device_statusa)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer)

[FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport)