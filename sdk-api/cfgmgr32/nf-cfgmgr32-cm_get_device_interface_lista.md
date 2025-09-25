# CM_Get_Device_Interface_ListA function

## Description

The **CM_Get_Device_Interface_List** function retrieves a list of device interface instances that belong to a specified [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes).

## Parameters

### `InterfaceClassGuid` [in]

Supplies a GUID that identifies a device interface class.

### `pDeviceID` [in, optional]

Caller-supplied pointer to a NULL-terminated string that represents a [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids). If specified, the function retrieves device interfaces that are supported by the device for the specified class. If this value is **NULL**, or if it points to a zero-length string, the function retrieves all interfaces that belong to the specified class.

### `Buffer` [out]

Caller-supplied pointer to a buffer that receives multiple, NULL-terminated Unicode strings, each representing the symbolic link name of an interface instance.

### `BufferLen` [in]

Caller-supplied value that specifies the length, in characters, of the buffer pointed to by *Buffer*. Call [CM_Get_Device_Interface_List_Size](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_interface_list_sizea) to determine the required buffer size.

### `ulFlags` [in]

Contains one of the following caller-supplied flags:

#### CM_GET_DEVICE_INTERFACE_LIST_ALL_DEVICES

The function provides a list containing device interfaces associated with all devices that match the specified GUID and device instance ID, if any.

#### CM_GET_DEVICE_INTERFACE_LIST_PRESENT

The function provides a list containing device interfaces associated with devices that are currently active, and which match the specified GUID and device instance ID, if any.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the error codes with the CR_ prefix as defined in *Cfgmgr32.h*.

The following table includes some of the more common error codes that this function might return.

| Return code | Description |
| --- | --- |
| **CR_BUFFER_SMALL** | The *Buffer* buffer is too small to hold the requested list of device interfaces. |

## Remarks

Between calling [CM_Get_Device_Interface_List_Size](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_interface_list_sizea) to get the size of the list and calling **CM_Get_Device_Interface_List** to get the list, a new device interface can be added to the system causing the size returned to no longer be valid. Callers should be robust to that condition and retry getting the size and the list if **CM_Get_Device_Interface_List** returns **CR_BUFFER_SMALL**.

#### Examples

This snippet illustrates retrying getting the size and the list as described in the Remarks section.

```cpp
    CONFIGRET cr = CR_SUCCESS;
    PWSTR DeviceInterfaceList = NULL;
    ULONG DeviceInterfaceListLength = 0;

    do {
        cr = CM_Get_Device_Interface_List_Size(&DeviceInterfaceListLength,
                                               (LPGUID)&GUID_DEVINTERFACE_VOLUME,
                                               NULL,
                                               CM_GET_DEVICE_INTERFACE_LIST_ALL_DEVICES);

        if (cr != CR_SUCCESS)
        {
            break;
        }

        if (DeviceInterfaceList != NULL) {
            HeapFree(GetProcessHeap(),
                     0,
                     DeviceInterfaceList);
        }

        DeviceInterfaceList = (PWSTR)HeapAlloc(GetProcessHeap(),
                                               HEAP_ZERO_MEMORY,
                                               DeviceInterfaceListLength * sizeof(WCHAR));

        if (DeviceInterfaceList == NULL)
        {
            cr = CR_OUT_OF_MEMORY;
            break;
        }

        cr = CM_Get_Device_Interface_List((LPGUID)&GUID_DEVINTERFACE_VOLUME,
                                          NULL,
                                          DeviceInterfaceList,
                                          DeviceInterfaceListLength,
                                          CM_GET_DEVICE_INTERFACE_LIST_ALL_DEVICES);
    } while (cr == CR_BUFFER_SMALL);

    if (cr != CR_SUCCESS)
    {
        goto Exit;
    }

```

> [!NOTE]
> The cfgmgr32.h header defines CM_Get_Device_Interface_List as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CM_Get_Device_Interface_List_Size](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_interface_list_sizea)