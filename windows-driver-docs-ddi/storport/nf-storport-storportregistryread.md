# StorPortRegistryRead function

## Description

The **StorPortRegistryRead** routine reads the registry data for the indicated device and value.

## Parameters

### `HwDeviceExtension`

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device. The miniport driver must be running at IRQL PASSIVE_LEVEL when it calls this routine.

### `ValueName`

Pointer to a UCHAR that specifies the registry value name whose content is to be read.

### `Global`

Indicates, when nonzero, that the port driver reads the contents of the registry value specified by **ValueName** under the Parameters\Device subkey. The values under the Device key apply to all adapters in the system. When **Global** is zero, the port driver reads the contents of the registry value specified by **ValueName** under the Parameters\Device(d) subkey, where (d) is a decimal value that corresponds to the port number of a particular adapter. In this case, the data retrieved is adapter-specific.

### `Type`

Indicates the data type of registry value. This parameter must have one of the values in the following table.

| Registry value data type | Meaning |
| ------------------------ | ------- |
| REG_NONE | No data type specified. |
| REG_SZ | Indicates a **NULL**-terminated Unicode string. |
| REG_EXPAND_SZ | Indicates a **NULL**-terminated Unicode string that includes environment variables that must be expanded to obtain the complete string. For example, a path name might be stored as the following string: "%USERPROFILE%\Application Data ". In this example, the environment variable USERPROFILE must be expanded to obtain the actual pathname. |
| REG_BINARY | Indicates a raw binary data. |
| REG_DWORD | Indicates a 32-bit double word value. |
| REG_DWORD_LITTLE_ENDIAN | Indicates a 32-bit double word value, in little-endian order. This is identical to REG_DWORD. |
| REG_DWORD_BIG_ENDIAN | Indicates a 32-bit double word value, in big-endian order. |
| REG_LINK | Indicates a Unicode string containing a symbolic link. |
| REG_MULTI_SZ | Indicates a series of **NULL**-terminated strings. |
| REG_RESOURCE_LIST | Indicates that the registry value contains a list of hardware resources, also known as the "hardware resource map", that is stored under the HKEY_LOCAL_MACHINE\HARDWARE\ResourceMap hive. |
| REG_FULL_RESOURCE_DESCRIPTOR | Indicates that the registry value contains a description of hardware resources stored under the HKEY_LOCAL_MACHINE\HARDWARE\Description hive. |
| REG_RESOURCE_REQUIREMENTS_LIST | Indicates that the registry value contains a list of hardware resource requirements stored under the HKEY_LOCAL_MACHINE\HARDWARE\ResourceMap tree. |
| REG_QWORD | Indicates that the registry value contains a 64-bit number. |
| REG_QWORD_LITTLE_ENDIAN | Indicates that the registry value contains a 64-bit number. This is the same data type as REG_QWORD. |

### `Buffer`

Pointer to the buffer where the retrieved registry information is to be reported.

### `BufferLength`

Pointer to a ULONG that contains the size, in bytes, of the registry data returned.

## Return value

**StorPortRegistryRead** returns a Boolean value of **TRUE** if the data pointed to by **ValueName** is successfully converted into ASCII and copied into the buffer. This routine returns **FALSE** in the event of an error.

## Remarks

If **StorPortRegistryRead** returns **FALSE** with a nonzero value in the **BufferLength** parameter, the buffer that was passed was too small and the **BufferLength** parameter reflects the correct buffer size that should be used. If the routine returns **FALSE** with the **BufferLength** parameter set to zero, another error has occurred.

The buffer used in this routine is allocated by calling [**StorPortAllocateRegistryBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocateregistrybuffer) and freed by calling [**StorPortFreeRegistryBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportfreeregistrybuffer).

## See also

[**StorPortAllocateRegistryBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocateregistrybuffer)

[**StorPortFreeRegistryBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportfreeregistrybuffer)

[**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize)