# DELETE\_OBJECT\_OPTIONS enumeration

The **DELETE\_OBJECT\_OPTIONS** enumeration type describes options that are supported by a device when deleting an object.

## Constants

**PORTABLE\_DEVICE\_DELETE\_NO\_RECURSION**

Delete the object only and fail if it has children.

**PORTABLE\_DEVICE\_DELETE\_WITH\_RECURSION**

Delete the object and all its children.

## Remarks

The application can retrieve the deletion options that the device supports by calling [**IPortableDeviceCapabilities::GetCommandOptions**](https://learn.microsoft.com/windows/desktop/api/PortableDeviceApi/nf-portabledeviceapi-iportabledevicecapabilities-getcommandoptions) for the **WPD\_COMMAND\_OBJECT\_MANAGEMENT\_DELETE\_OBJECTS** command. It should examine the **WPD\_OPTION\_OBJECT\_MANAGEMENT\_RECURSIVE\_DELETE\_SUPPORTED** option value that this method returns in an [**IPortableDeviceValuesCollection**](https://learn.microsoft.com/windows/win32/wpd_sdk/iportabledevicevaluescollection) object.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------------|
| Header<br> | PortableDevice.h |

## See also

[**Structures and Enumeration Types**](https://learn.microsoft.com/windows/win32/wpd_sdk/structures-and-enumeration-types)

