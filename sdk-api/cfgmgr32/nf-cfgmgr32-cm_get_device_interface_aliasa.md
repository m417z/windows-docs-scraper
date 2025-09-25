# CM_Get_Device_Interface_AliasA function

## Description

The **CM_Get_Device_Interface_Alias** function returns the alias of the specified device interface instance, if the alias exists.

## Parameters

### `pszDeviceInterface` [in]

Pointer to the name of the device interface instance for which to retrieve an alias. The caller typically received this string from a call to [CM_Get_Device_Interface_List](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_interface_lista), or in a PnP notification structure.

### `AliasInterfaceGuid` [in]

Pointer to a GUID specifying the interface class of the alias to retrieve.

### `pszAliasDeviceInterface` [out]

Specifies a pointer to a buffer, that upon successful return, points to a string containing the name of the alias. The caller must free this string when it is no longer needed.

A buffer is required. Otherwise, the call will fail.

### `pulLength` [in, out]

Supplies the count of characters in *pszAliasDeviceInterface* and receives the number of characters required to hold the alias device interface.

On input, this parameter must be greater than 0.

### `ulFlags` [in]

Reserved. Do not use.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

| Return code | Description |
| --- | --- |
| **CR_NO_SUCH_DEVICE_INTERFACE** | Possibly indicates that there is no alias of the specified interface class. |
| **CR_OUT_OF_MEMORY** | There is not enough memory to complete the operation. |
| **CR_BUFFER_SMALL** | The buffer passed is too small. |

## Remarks

Device interfaces are considered aliases if they are exposed by the same underlying device and have identical interface reference strings, but are of different interface classes.

The *pszDeviceInterface* parameter specifies a device interface instance for a particular device, belonging to a particular interface class, with a particular reference string. **CM_Get_Device_Interface_Alias** returns another device interface instance for the same device and reference string, but of a different interface class, if it exists.

For example, the function driver for a fault-tolerant volume could register and set two device interfaces, one of the fault-tolerant-volume interface class and one of the volume interface class. Another driver could call **CM_Get_Device_Interface_Alias** with the symbolic link for one of the interfaces and ask whether the other interface exists by specifying its interface class.

Two device interfaces with **NULL** reference strings are aliases if they are exposed by the same underlying device and have different interface class GUIDs.