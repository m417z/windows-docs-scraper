# SetupDiGetClassDevsExW function

## Description

The **SetupDiGetClassDevsEx** function returns a handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains requested device information elements for a local or a remote computer.

## Parameters

### `ClassGuid` [in, optional]

A pointer to the GUID for a [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) or a [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes). This pointer is optional and can be **NULL**. If a GUID value is not used to select devices, set *ClassGuid* to **NULL**. For more information about how to use *ClassGuid*, see the following **Remarks** section.

### `Enumerator` [in, optional]

A pointer to a NULL-terminated string that specifies:

* An identifier (ID) of a Plug and Play (PnP) [enumerator](https://learn.microsoft.com/windows-hardware/drivers/). This ID can either be the enumerator's globally unique identifier (GUID) or symbolic name. For example, "PCI" can be used to specify the PCI PnP enumerator. Other examples of symbolic names for PnP enumerators include "USB", "PCMCIA", and "SCSI".
* A PnP [device instance IDs](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids). When specifying a PnP device instance ID, DIGCF_DEVICEINTERFACE must be set in the Flags parameter.

This pointer is optional and can be **NULL**. If an *Enumerator* value is not used to select devices, set *Enumerator* to **NULL**

For more information about how to set the *Enumerator* value, see the following **Remarks** section.

### `hwndParent` [in, optional]

A handle to the top-level window to be used for a user interface that is associated with installing a device instance in the device information set. This handle is optional and can be **NULL**.

### `Flags` [in]

A variable of type DWORD that specifies control options that filter the device information elements that are added to the device information set. This parameter can be a bitwise OR of one or more of the following flags. For more information about combining these control options, see the following **Remarks** section.

#### DIGCF_ALLCLASSES

Return a list of installed devices for the specified device setup classes or device interface classes.

#### DIGCF_DEVICEINTERFACE

Return devices that support device interfaces for the specified device interface classes. This flag must be set in the *Flags* parameter if the *Enumerator* parameter specifies a [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids).

#### DIGCF_DEFAULT

Return only the device that is associated with the system default device interface, if one is set, for the specified device interface classes.

#### DIGCF_PRESENT

Return only devices that are currently present.

#### DIGCF_PROFILE

Return only devices that are a part of the current hardware profile.

### `DeviceInfoSet` [in, optional]

The handle to an existing [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) to which **SetupDiGetClassDevsEx** adds the requested device information elements. This parameter is optional and can be set to **NULL**. For more information about using this parameter, see the following **Remarks** section.

### `MachineName` [in, optional]

A pointer to a constant string that contains the name of a remote computer on which the devices reside. A value of **NULL** for *MachineName* specifies that the device is installed on the local computer. Remote computer is not supported beginning with Windows 8 and Windows Server 2012.

> [!CAUTION]
> Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

### `Reserved`

Reserved for internal use. This parameter must be set to **NULL**.

##### - Flags.DIGCF_ALLCLASSES

Return a list of installed devices for the specified device setup classes or device interface classes.

##### - Flags.DIGCF_DEFAULT

Return only the device that is associated with the system default device interface, if one is set, for the specified device interface classes.

##### - Flags.DIGCF_DEVICEINTERFACE

Return devices that support device interfaces for the specified device interface classes. This flag must be set in the *Flags* parameter if the *Enumerator* parameter specifies a [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids).

##### - Flags.DIGCF_PRESENT

Return only devices that are currently present.

##### - Flags.DIGCF_PROFILE

Return only devices that are a part of the current hardware profile.

## Return value

If the operation succeeds, **SetupDiGetClassDevsEx** returns a handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains all installed devices that matched the supplied parameters. If the operation fails, the function returns INVALID_HANDLE_VALUE. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller of **SetupDiGetClassDevsEx** must delete the returned device information set when it is no longer needed by calling [SetupDiDestroyDeviceInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdidestroydeviceinfolist).

If *DeviceInfoSet* is **NULL**, **SetupDiGetClassDevsEx** creates a new device information set that contains the retrieved device information elements and returns a handle to the new device information set. If the caller requests that the function retrieve devices for a device setup class that is supplied by the *ClassGuid*  parameter, the function sets the device setup class of the new device information set to the supplied class GUID.

If *DeviceInfoSet* is not set to **NULL**, the function adds the retrieved device information elements to the device information set that is associated with the supplied handle, and returns the supplied handle. If *ClassGuid* supplies a device setup class, the device setup class of the supplied device information set must be set to the supplied class GUID.

### Device Setup Class Control Options

Use the following filtering options to control whether **SetupDiGetClassDevsEx** returns devices for all device setup classes or only for a specified device setup class:

* To return devices for all device setup classes, set the DIGCF_ALLCLASSES flag and set the *ClassGuid* parameter to **NULL**.
* To return devices only for a specific device setup class, do not set DIGCF_ALLCLASSES and use *ClassGuid* to supply the GUID of the device setup class.

In addition, you can use the following filtering options to further restrict which devices are returned.

* To return only devices that are present in the system, set the DIGCF_PRESENT flag.
* To return only devices that are part of the current hardware profile, set the DIGCF_PROFILE flag.
* To return devices for a specific PnP [enumerator](https://learn.microsoft.com/windows-hardware/drivers/) only, use the *Enumerator* parameter to supply the GUID or symbolic name of the enumerator*.* If *Enumerator* is **NULL**, **SetupDiGetClassDevsEx** returns devices for all PnP enumerators.

### Device Interface Class Control Options

Use the following filtering options to control whether **SetupDiGetClassDevsEx** returns devices that support any device interface class or only devices that support a specified device interface class:

* To return devices that support a device interface of any class, set the DIGCF_DEVICEINTERFACE flag, set the DIGCF_ALLCLASSES flag, and set *ClassGuid* to **NULL**. The function adds to the device information set a device information element that represents such a device, and then adds to the device information element a device interface list that contains all the device interfaces that the device supports.
* To return only devices that support a device interface of a specified class, set the DIGCF_DEVICEINTERFACE flag and use the *ClassGuid* parameter to supply the class GUID of the device interface class. The function adds to the device information set a device information element that represents such a device, and then adds a device interface of the specified class to the device interface list for that device information element.

In addition, you can use the following filtering options to control whether **SetupDiGetClassDevsEx** returns only devices that support the system default interface for device interface classes:

* To return only the device that supports the system default interface, if one is set, for a specified device interface class, set the DIGCF_DEVICEINTERFACE flag, set the DIGCF_DEFAULT flag, and use *ClassGuid* to supply the class GUID of the device interface class. The function adds to the device information set a device information element that represents such a device, and then adds the system default interface to the device interface list for that device information element.
* To return a device that supports a system default interface for an unspecified device interface class, set the DIGCF_DEVICEINTERFACE flag, set the DIGCF_ALLCLASSES flag, set the DIGCF_DEFAULT flag, and set *ClassGuid* to **NULL**. The function adds to the device information set a device information element that represents such a device, and then adds the system default interface to the device interface list for that device information element.

You can also use the following options in combination with the other options to further restrict which devices are returned.

* To return only devices that are present in the system, set the DIGCF_PRESENT flag.
* To return only devices that are part of the current hardware profile, set the DIGCF_PROFILE flag.
* To return only a specific device, set the DIGCF_DEVICEINTERFACE flag and use the *Enumerator* parameter to supply the [device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) of the device*.* To include all possible devices, set *Enumerator* to **NULL**.

### Retrieving Devices in a Device Setup Class That Support a Device Interface Class

An installer can use **SetupDiGetClassDevsEx** to retrieve a list of devices of a particular device setup class that support a device interface of a specified device interface class. For example, to retrieve a list of all devices on a local computer that support a device interface in the "mounted device" interface class and that are members of the "Volume" device setup class, an installer should perform the following operations:

1. Call [SetupDiCreateDeviceInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinfolistexa) to create an empty device information set for the "Volume" device setup class. Set *ClassGuid* to a pointer to the class GUID for the "Volume" device setup class and set *hwndParent* as appropriate. In response to such a call, the function will return a handle to type HDEVINFO to the device information set.
2. Call **SetupDiGetClassDevsEx** with the following settings:
   * Set *ClassGuid* to a pointer to the class GUID of the "mounted device" device interface class.
   * Set *Flags* to DIGCF_DEVICEINTERFACE.
   * Set *DeviceInfoSet* to the HDEVINFO handle obtained in step (1).
   * Set *hwndParent* as appropriate and the remaining parameters to **NULL**.

In an operation of this type, **SetupDiGetClassDevsEx** returns a device if the device setup class of the device is the same as the supplied device information set and if the device supports a device interface whose class is the same as the specified device interface class.

> [!NOTE]
> The setupapi.h header defines SetupDiGetClassDevsEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Device Information Set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets)

[Device Instance IDs](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids)

[SetupDiCreateDeviceInfoListEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinfolistexa)

[SetupDiDestroyDeviceInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdidestroydeviceinfolist)

[SetupDiEnumDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdienumdeviceinterfaces)

[SetupDiGetClassDevs](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdevsw)