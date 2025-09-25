# IoGetDeviceInterfaceAlias function

## Description

The **IoGetDeviceInterfaceAlias** routine returns the alias device interface of the specified device interface instance, if the alias exists.

## Parameters

### `SymbolicLinkName` [in]

Pointer to the name of the device interface instance for which to retrieve an alias. The caller typically received this string from a call to [IoGetDeviceInterfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceinterfaces) or in a PnP notification structure.

### `AliasInterfaceClassGuid` [in]

Pointer to a GUID specifying the interface class of the alias to retrieve.

### `AliasSymbolicLinkName` [out]

Specifies a pointer to a **NULL** Unicode string. On successful return, *AliasSymbolicLinkName*.**Buffer** points to a string containing the name of the alias. The caller must free the Unicode string with [RtlFreeUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring) when it is no longer needed.

## Return value

**IoGetDeviceInterfaceAlias** returns STATUS_SUCCESS if the call was successful. Possible error return values are described following.

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_NAME_NOT_FOUND** | Possibly indicates that there is no alias of the specified interface class. |
| **STATUS_OBJECT_PATH_NOT_FOUND** | Possibly indicates that there is no alias of the specified interface class. |
| **STATUS_INVALID_HANDLE** | Possibly indicates an invalid *SymbolicLinkName* or an invalid *AliasClassGuid*. |

## Remarks

Device interfaces are considered aliases if they are exposed by the same underlying device and have identical interface reference strings, but are of different interface classes.

The *SymbolicLinkName* parameter specifies a device interface instance for a particular device, belonging to a particular interface class, with a particular reference string. **IoGetDeviceInterfaceAlias** returns another device interface instance for the same device and reference string, but of a different interface class, if it exists.

For example, the function driver for a fault-tolerant volume could register and set two device interfaces, one of the fault-tolerant-volume interface class and one of the volume interface class. Another driver could call **IoGetDeviceInterfaceAlias** with the symbolic link for one of the interfaces and ask whether the other interface exists by specifying its interface class.

Two device interfaces with **NULL** reference strings are aliases if they are exposed by the same underlying device and have different interface class GUIDs.

Callers of **IoGetDeviceInterfaceAlias** must be running at IRQL = PASSIVE_LEVEL in the context of a system thread.

## See also

[IoRegisterDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdeviceinterface)

[RtlFreeUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring)