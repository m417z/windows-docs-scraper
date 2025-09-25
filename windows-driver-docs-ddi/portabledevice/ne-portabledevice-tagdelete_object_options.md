# tagDELETE_OBJECT_OPTIONS enumeration

## Description

The **DELETE_OBJECT_OPTIONS** enumeration type describes options that are supported by a device when deleting an object.

## Constants

### `PORTABLE_DEVICE_DELETE_NO_RECURSION`

Delete the object only and fail if it has children.

### `PORTABLE_DEVICE_DELETE_WITH_RECURSION`

Delete the object and all its children.

## Remarks

An application can retrieve the deletion options that the device supports by calling the **IPortableDeviceCapabilities::GetCommandOptions** method for the **WPD_COMMAND_OBJECT_MANAGEMENT_DELETE_OBJECTS** command. It should examine the **WPD_OPTION_OBJECT_MANAGEMENT_RECURSIVE_DELETE_SUPPORTED** option value that this method returns in an [IPortableDeviceValuesCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevaluescollection) object.

## See also

[Structures and Enumeration Types](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff597672(v=vs.85))