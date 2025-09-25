# StorPortRegistryWriteAdapterKey function

## Description

The **StorPortRegistryReadAdapterKey** routine is called by the miniport driver to read the hardware or device registry adapter keys located in registry at HKLM/CurrentControlSet/Enum/*Instance path*/DeviceParameters/... these keys are read from in the [INF DDInstall.HW Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-ddinstall-hw-section).

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device. The miniport driver must be running at IRQL PASSIVE_LEVEL when it calls this routine.

### `SubKeyName` [in, optional]

The miniport subkey.

### `ValueName` [in]

The name of the Value under the key.

### `ValueType` [in]

One of the following registry data types.

| Type | Meaning |
| ---- | ------- |
| REG_SZ | Unicode null-terminated string. |
| REG_EXPAND_SZ | Unicode null-terminated string with environment variable references. |
| REG_BINARY | Binary data. |
| REG_DWORD | 32-bit double word. |
| REG_DWORD_LITTLE_ENDIAN | 32-bit double word with a little-endian format. |
| REG_DWORD_BIG_ENDIAN | 32-bit double word with a big-endian format. |
| REG_LINK | Unicode string that specifies a symbolic link. |
| REG_MULTI_SZ | Multiple Unicode strings. |
| REG_RESOURCE_LIST | Resource list in the resource map. |
| REG_FULL_RESOURCE_DESCRIPTOR | Resource list in the hardware description. |
| REG_RESOURCE_REQUIREMENTS_LIST | Resource requirement list. |
| REG_QWORD | 64-bit quadlet number. |
| REG_QWORD_LITTLE_ENDIAN | 64-bit quadlet number with a little-endian format. |

### `ValueData` [in, out]

Pointer to the data that contains the registry data to be read. The data is converted from UNICODE to a NULL-terminated ASCII string.

### `ValueDataLength` [in, out]

Specifies the size of the data pointed to by **ValueData**.

## Return value

Returns STOR_STATUS_SUCCESS when the operation is successful, otherwise the appropriate error code.

## See also

[**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize)