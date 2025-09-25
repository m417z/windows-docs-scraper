# IoWMISuggestInstanceName function

## Description

The **IoWMISuggestInstanceName** routine is used to request that WMI suggest a base name which a driver can use to build WMI instance names for the device.

## Parameters

### `PhysicalDeviceObject` [in, optional]

If supplied, points to the driver's physical device object.

### `SymbolicLinkName` [in, optional]

If supplied, points to the symbolic link name returned from [IoRegisterDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdeviceinterface).

### `CombineNames` [in]

If **TRUE** then the suggested names returned will combine the *PhysicalDeviceObject* and *SymbolicLinkName* information.

### `SuggestedInstanceName` [out]

A pointer to a buffer which upon successful completion will contain a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) which contains the suggested instance name. The caller is responsible for freeing this buffer when it is no longer needed.

## Return value

**IoWMISuggestInstanceName** returns a status code from the following list:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Indicates that WMI was able to successfully complete this function. |
| **STATUS_UNSUCCESSFUL** | Indicates that the WMI services are not available. |
| **STATUS_INSUFFICIENT_RESOURCES** | Indicates that insufficient resources were available to provide the caller with a buffer containing the Unicode string. |
| **STATUS_NO_MEMORY** | Indicates that insufficient resources were available to provide the caller with a buffer containing the Unicode string. |

## Remarks

If the *CombineNames* parameter is **TRUE** then both *PhysicalDeviceObject* and *SymbolicLinkName* must be specified. Otherwise, only one of them should be specified.

## See also

[IoWMIAllocateInstanceIds](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiallocateinstanceids)