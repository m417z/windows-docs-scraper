# CM_Get_Device_Interface_List_SizeW function

## Description

The **CM_Get_Device_Interface_List_Size** function retrieves the buffer size
that must be passed to the
[CM_Get_Device_Interface_List](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_interface_listw)
function.

## Parameters

### `pulLen` [out]

Caller-supplied pointer to a location that receives the required length, in characters, of a buffer to
hold the multiple Unicode strings that will be returned by
**CM_Get_Device_Interface_List**.

### `InterfaceClassGuid` [in]

Supplies a GUID that identifies a
[device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes).

### `pDeviceID` [in, optional]

Caller-supplied pointer to a NULL-terminated string that represents a
[device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids). If specified, the
function retrieves the length of symbolic link names for the device interfaces that are supported by the
device, for the specified class. If this value is **NULL**, or if it points to a
zero-length string, the function retrieves the length of symbolic link names for all interfaces that belong
to the specified class.

### `ulFlags` [in]

Contains one of the following caller-supplied flags:

| Value | Meaning |
| --- | --- |
| **CM_GET_DEVICE_INTERFACE_LIST_ALL_DEVICES** | The function provides the size of a list that contains device interfaces associated with all devices that match the specified **GUID** and device instance ID, if any. |
| **CM_GET_DEVICE_INTERFACE_LIST_PRESENT** | The function provides the size of a list containing device interfaces associated with devices that are currently active, and which match the specified GUID and device instance ID, if any. |

## Return value

If the operation succeeds, the function returns **CR_SUCCESS**. Otherwise, it
returns one of the error codes with the **CR_** prefix as defined in
Cfgmgr32.h.

## See also

[CM_Get_Device_Interface_List](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_interface_listw)

## Remarks

> [!NOTE]
> The cfgmgr32.h header defines CM_Get_Device_Interface_List_Size as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).