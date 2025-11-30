# SetupDiGetClassDevsW function

## Description

The **SetupDiGetClassDevs** function returns a handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains requested device information elements for a local computer.

## Parameters

### `ClassGuid` [in, optional]

A pointer to the GUID for a [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) or a [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes). This pointer is optional and can be **NULL**. For more information about how to set *ClassGuid*, see the following **Remarks** section.

### `Enumerator` [in, optional]

A pointer to a NULL-terminated string that specifies:

* An identifier (ID) of a Plug and Play (PnP) [enumerator](https://learn.microsoft.com/windows-hardware/drivers/). This ID can either be the value's globally unique identifier (GUID) or symbolic name. For example, "PCI" can be used to specify the PCI PnP value. Other examples of symbolic names for PnP values include "USB," "PCMCIA," and "SCSI".
* A PnP [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids). When specifying a PnP device instance ID, DIGCF_DEVICEINTERFACE must be set in the Flags parameter.

This pointer is optional and can be **NULL**. If an *enumeration* value is not used to select devices, set *Enumerator* to **NULL**

For more information about how to set the *Enumerator* value, see the following **Remarks** section.

### `hwndParent` [in, optional]

A handle to the top-level window to be used for a user interface that is associated with installing a device instance in the device information set. This handle is optional and can be **NULL**.

### `Flags` [in]

A variable of type DWORD that specifies control options that filter the device information elements that are added to the device information set. This parameter can be a bitwise OR of zero or more of the following flags. For more information about combining these flags, see the following **Remarks** section.

#### DIGCF_ALLCLASSES

Return a list of installed devices for all device setup classes or all device interface classes.

#### DIGCF_DEVICEINTERFACE

Return devices that support device interfaces for the specified device interface classes. This flag must be set in the *Flags* parameter if the *Enumerator* parameter specifies a [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids).

#### DIGCF_DEFAULT

Return only the device that is associated with the system default device interface, if one is set, for the specified device interface classes.

#### DIGCF_PRESENT

Return only devices that are currently present in a system.

#### DIGCF_PROFILE

Return only devices that are a part of the current hardware profile.

## Return value

If the operation succeeds, **SetupDiGetClassDevs** returns a handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains all installed devices that matched the supplied parameters. If the operation fails, the function returns INVALID_HANDLE_VALUE. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller of **SetupDiGetClassDevs** must delete the returned device information set when it is no longer needed by calling [SetupDiDestroyDeviceInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdidestroydeviceinfolist).

Call [SetupDiGetClassDevsEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsexa) to retrieve the devices for a class on a remote computer.

### Device Setup Class Control Options

Use the following filtering options to control whether **SetupDiGetClassDevs** returns devices for all device setup classes or only for a specified device setup class:

* To return devices for all device setup classes, set the DIGCF_ALLCLASSES flag, and set the *ClassGuid* parameter to **NULL**.
* To return devices only for a specific device setup class, do not set DIGCF_ALLCLASSES, and use *ClassGuid* to supply the GUID of the device setup class.

In addition, you can use the following filtering options in combination with one another to further restrict which devices are returned:

* To return only devices that are present in the system, set the DIGCF_PRESENT flag.
* To return only devices that are part of the current hardware profile, set the DIGCF_PROFILE flag.
* To return devices only for a specific PnP [enumerator](https://learn.microsoft.com/windows-hardware/drivers/), use the *Enumerator* parameter to supply the GUID or symbolic name of the enumerator*.* If *Enumerator* is **NULL**, **SetupDiGetClassDevs** returns devices for all PnP enumerators.

### Device Interface Class Control Options

Use the following filtering options to control whether **SetupDiGetClassDevs** returns devices that support any device interface class or only devices that support a specified device interface class:

* To return devices that support a device interface of any class, set the DIGCF_DEVICEINTERFACE flag, set the DIGCF_ALLCLASSES flag, and set *ClassGuid* to **NULL**. The function adds to the device information set a device information element that represents such a device and then adds to the device information element a device interface list that contains all the device interfaces that the device supports.
* To return only devices that support a device interface of a specified class, set the DIGCF_DEVICEINTERFACE flag and use the *ClassGuid* parameter to supply the class GUID of the device interface class. The function adds to the device information set a device information element that represents such a device and then adds a device interface of the specified class to the device interface list for that device information element.

In addition, you can use the following filtering options to control whether **SetupDiGetClassDevs** returns only devices that support the system default interface for device interface classes:

* To return only the device that supports the system default interface, if one is set, for a specified device interface class, set the DIGCF_DEVICEINTERFACE flag, set the DIGCF_DEFAULT flag, and use *ClassGuid* to supply the class GUID of the device interface class. The function adds to the device information set a device information element that represents such a device and then adds the system default interface to the device interface list for that device information element.
* To return a device that supports a system default interface for an unspecified device interface class, set the DIGCF_DEVICEINTERFACE flag, set the DIGCF_ALLCLASSES flag, set the DIGCF_DEFAULT flag, and set *ClassGuid* to **NULL**. The function adds to the device information set a device information element that represents such a device and then adds the system default interface to the device interface list for that device information element.

You can also use the following options in combination with the other options to further restrict which devices are returned:

* To return only devices that are present in the system, set the DIGCF_PRESENT flag.
* To return only devices that are part of the current hardware profile, set the DIGCF_PROFILE flag.
* To return only a specific device, set the DIGCF_DEVICEINTERFACE flag and use the *Enumerator* parameter to supply the [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) of the device*.* To include all possible devices, set *Enumerator* to **NULL**.

#### Examples

The following are some examples of how to use the **SetupDiGetClassDevs** function.

**Example 1:** Build a list of all devices in the system, including devices that are not currently present.

```
Handle = SetupDiGetClassDevs(NULL, NULL, NULL, DIGCF_ALLCLASSES);
```

**Example 2:**  Build a list of all devices that are present in the system.

```
Handle = SetupDiGetClassDevs(NULL, NULL, NULL, DIGCF_ALLCLASSES | DIGCF_PRESENT);
```

**Example 3:**  Build a list of all devices that are present in the system that are from the network adapter [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/system-defined-device-setup-classes-available-to-vendors).

```
Handle = SetupDiGetClassDevs(&GUID_DEVCLASS_NET, NULL, NULL, DIGCF_PRESENT);
```

**Example 4:**  Build a list of all devices that are present in the system that have enabled an interface from the storage volume [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes).

```
Handle = SetupDiGetClassDevs(&GUID_DEVINTERFACE_VOLUME, NULL, NULL, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);
```

**Example 5:**  Build a list of all devices that are present in the system but do not belong to any known [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/system-defined-device-setup-classes-available-to-vendors) (Windows Vista and later versions of Windows).

**Note** You cannot set the *ClassGuid* parameter to GUID_DEVCLASS_UNKNOWN to detect devices with an unknown setup class. Instead, you must follow this example.

```
HDEVINFO DeviceInfoSet = SetupDiGetClassDevsW(
    NULL,
    NULL,
    NULL,
    DIGCF_ALLCLASSES | DIGCF_PRESENT);

SP_DEVINFO_DATA DeviceInfoData;
ZeroMemory(&DeviceInfoData, sizeof(SP_DEVINFO_DATA));
DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
DWORD DeviceIndex = 0;
DEVPROPTYPE PropType;

GUID     DevGuid;
DWORD Size;

while (SetupDiEnumDeviceInfo(
    DeviceInfoSet,
    DeviceIndex,
    &DeviceInfoData)) {
    DeviceIndex++;

    if (!SetupDiGetDevicePropertyW(
        DeviceInfoSet,
        &DeviceInfoData,
        &DEVPKEY_Device_Class,
        &PropType,
        (PBYTE)&DevGuid,
        sizeof(GUID),
        &Size,
        0) || PropType != DEVPROP_TYPE_GUID) {

        DWORD Error = GetLastError();

        if (Error == ERROR_NOT_FOUND) {
            //
            // This device has an unknown device setup class.
            //

        }
    }
}

if (DeviceInfoSet) {
    SetupDiDestroyDeviceInfoList(DeviceInfoSet);
}

return 0;
```

> [!NOTE]
> The setupapi.h header defines SetupDiGetClassDevs as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Device Information Set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets)

[Device Instance IDs](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids)

[SetupDiCreateDeviceInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinfolist)

[SetupDiDestroyDeviceInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdidestroydeviceinfolist)

[SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces)

[SetupDiGetClassDevsEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsexa)