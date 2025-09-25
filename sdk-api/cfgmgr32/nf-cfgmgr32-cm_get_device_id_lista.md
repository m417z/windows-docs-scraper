# CM_Get_Device_ID_ListA function

## Description

The **CM_Get_Device_ID_List** function retrieves a list of [device instance IDs](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) for the local computer's [device instances](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `pszFilter` [in, optional]

Caller-supplied pointer to a character string that is either set to a subset of the computer's device instance identifiers (IDs), or to **NULL**. See the following description of *ulFlags*.

### `Buffer` [out]

Address of a buffer to receive a set of NULL-terminated device instance identifier strings. The end of the set is terminated by an extra **NULL**. The required buffer size should be obtained by calling [CM_Get_Device_ID_List_Size](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_list_sizea).

### `BufferLen` [in]

Caller-supplied length, in characters, of the buffer specified by *Buffer*.

### `ulFlags` [in]

One of the following caller-supplied bit flags that specifies search filters:

#### CM_GETIDLIST_FILTER_BUSRELATIONS

If this flag is set, *pszFilter* must specify a device instance identifier. The function returns device instance IDs for the [bus relations](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations) of the specified device instance.

#### CM_GETIDLIST_FILTER_CLASS (Windows 7 and later versions of Windows)

If this flag is set, *pszFilter* contains a string that specifies a [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) GUID. The returned list contains device instances for which the property (referenced by the CM_DRP_CLASSGUID constant) matches the specified device setup class GUID.

The CM_DRP_CLASSGUID constant is defined in *Cfgmgr32.h*.

#### CM_GETIDLIST_FILTER_PRESENT (Windows 7 and later versions of Windows)

If this flag is set, the returned list contains only device instances that are currently present on the system. This value can be combined with other *ulFlags* values, such as CM_GETIDLIST_FILTER_CLASS.

#### CM_GETIDLIST_FILTER_TRANSPORTRELATIONS (Windows 7 and later versions of Windows)

If this flag is set, *pszFilter* must specify the device instance identifier of a composite device node ([devnode](https://learn.microsoft.com/windows-hardware/drivers/)).

The function returns the device instance identifiers of the devnodes that represent the transport relations of the specified composite devnode.

For more information about composite devnodes and transport relations, see the following **Remarks** section.

#### CM_GETIDLIST_DONOTGENERATE

Used only with CM_GETIDLIST_FILTER_SERVICE. If set, and if the device tree does not contain a devnode for the specified service, this flag prevents the function from creating a devnode for the service.

#### CM_GETIDLIST_FILTER_EJECTRELATIONS

If this flag is set, *pszFilter* must specify a device instance identifier. The function returns device instance IDs for the [ejection relations](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations) of the specified device instance.

#### CM_GETIDLIST_FILTER_ENUMERATOR

If this flag is set, *pszFilter* must specify the name of a device enumerator, optionally followed by a [device ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-ids). The string format is *EnumeratorName*\\<*DeviceID*>, such as **ROOT** or **ROOT\\\*PNP0500**.

If *pszFilter* supplies only an enumerator name, the function returns [device instance IDs](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) for the instances of each device associated with the enumerator. Enumerator names can be obtained by calling [CM_Enumerate_Enumerators](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_enumerate_enumeratorsw).

If *pszFilter* supplies both an enumerator and a [device ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-ids), the function returns [device instance IDs](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids) only for the instances of the specified device that is associated with the enumerator.

#### CM_GETIDLIST_FILTER_NONE

If this flag is set, *pszFilter* is ignored, and a list of all devices on the system is returned.

#### CM_GETIDLIST_FILTER_POWERRELATIONS

If this flag is set, *pszFilter* must specify a device instance identifier. The function returns device instance IDs for the power relations of the specified device instance.

#### CM_GETIDLIST_FILTER_REMOVALRELATIONS

If this flag is set, *pszFilter* must specify a device instance identifier. The function returns device instance IDs for the [removal relations](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations) of the specified device instance.

#### CM_GETIDLIST_FILTER_SERVICE

If this flag is set, *pszFilter* must specify the name of a Microsoft Windows service (typically a driver). The function returns device instance IDs for the device instances controlled by the specified service.

Note that if the device tree does not contain a [devnode](https://learn.microsoft.com/windows-hardware/drivers/) for the specified service, this function creates one by default. To inhibit this behavior, also set CM_GETIDLIST_DONOTGENERATE.

If no search filter flag is specified, the function returns all device instance IDs for all device instances.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

Starting with Windows 7, a device that supports multiple transport paths for packet-based data is referred to as a *composite*  device and is represented by a *composite* [devnode](https://learn.microsoft.com/windows-hardware/drivers/). A composite devnode logically represents the composite device to the user and applications as a single device, even though the composite devnode can have multiple paths to the physical device.

Each active transport path to the physical device is represented by a transport devnode and is referred to as a *transport relation* for the composite device.

The composite devnode (but not the related transport devnodes) exposes device interfaces to applications and the system. When an application uses these public device interfaces, the composite device routes the packet-based data to one or more of these transport devnodes, which then transport the data to the physical device.

For example, if a physical cell phone is simultaneously connected to the computer on the USB and the Bluetooth buses, each bus enumerates a child transport devnode on that bus to represent the device's physical connection.

In this case, if you set the CM_GETIDLIST_FILTER_TRANSPORTRELATIONS flags in *ulFlags* and specify the device instance ID of the cell phone's composite devnode in *pszFilter*, the function returns the device instance IDs for the two transport devnodes in the *Buffer* parameter.

For more information about device instance IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

> [!NOTE]
> The cfgmgr32.h header defines CM_Get_Device_ID_List as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CM_Get_Device_ID_List_Size](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_list_sizea)