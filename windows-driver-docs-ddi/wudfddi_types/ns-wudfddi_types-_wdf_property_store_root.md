# _WDF_PROPERTY_STORE_ROOT structure

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WDF_PROPERTY_STORE_ROOT** structure contains information that identifies a UMDF property store.

## Members

### `LengthCb`

The length, in bytes, of this structure.

### `RootClass`

A [WDF_PROPERTY_STORE_ROOT_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_property_store_root_class)-typed value that identifies a property store.

### `Qualifier`

### `Qualifier.HardwareKey`

### `Qualifier.HardwareKey.ServiceName`

A pointer to a **NULL**-terminated character string that identifies a driver-specific subkey under a device's [hardware key](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers) in the registry. For more information about this member, see the following Remarks section.

### `Qualifier.DeviceInterfaceKey`

### `Qualifier.DeviceInterfaceKey.InterfaceGUID`

A pointer to a GUID that identifies a device interface. The driver must have previously called [IWDFDevice::CreateDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createdeviceinterface) to register the device interface.

### `Qualifier.DeviceInterfaceKey.ReferenceString`

A pointer to a **NULL**-terminated character string that identifies a reference string for a device interface. The driver must specify this member if it specified a reference string when it called [IWDFDevice::CreateDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createdeviceinterface). Otherwise, this member must be **NULL**.

### `Qualifier.LegacyHardwareKey`

### `Qualifier.LegacyHardwareKey.LegacyMapName`

A pointer to a **NULL**-terminated character string that identifies a subkey under the **HKEY_LOCAL_MACHINE\HARDWARE\DEVICEMAP** key in the registry. This key is used by only a few older drivers.

## Remarks

The **WDF_PROPERTY_STORE_ROOT** structure is used as input to [IWDFPropertyStoreFactory::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfpropertystorefactory-retrievedevicepropertystore) and [IWDFUnifiedPropertyStoreFactory::RetrieveUnifiedDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfunifiedpropertystorefactory-retrieveunifieddevicepropertystore).

UMDF property stores represent registry keys that drivers can access. Before your driver calls one of the above methods, it must initialize the **WDF_PROPERTY_STORE_ROOT** structure. The driver must zero the structure and then set the **LengthCb** member to the structure's length.

To open a [software key](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers), your driver must:

1. Set the structure's **LengthCb** member to the structure size.
2. Set the structure's **RootClass** member to **WdfPropertyStoreRootClassSoftwareKey**.

To open a device's [hardware key](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers), your driver must:

1. Set the structure's **LengthCb** member to the structure size.
2. Set the structure's **RootClass** member to **WdfPropertyStoreRootClassHardwareKey**.
3. Set a value for the **Qualifier.HardwareKey.ServiceName** member. This value must be one of the following:
   * **WDF_PROPERTY_STORE_HARDWARE_KEY_ROOT**, to open the **\Device Parameters** subkey under the device's hardware key. The driver can obtain only read access to this subkey.
   * **WDF_PROPERTY_STORE_HARDWARE_KEY_DEFAULT**, to open a subkey that matches the driver's service name, under the **\Device Parameters** subkey. The driver can obtain read or write access to this subkey. The driver can optionally create the subkey if it does not exist.
   * A driver-supplied character string, to open a subkey with a name that matches the character string, under the **\Device Parameters** subkey. The driver can obtain read or write access to this subkey. The driver can optionally create the subkey if it does not exist.

   If your driver creates a subkey under a device's hardware key, it is best to specify **WDF_PROPERTY_STORE_HARDWARE_KEY_DEFAULT** because UMDF creates a subkey that matches the driver's service name. Use of this name ensures that each driver creates a uniquely named subkey. The driver must not specify WDF or WUDF as the subkey name.

To open a [device interface key](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers), your driver must:

1. Set the structure's **LengthCb** member to the structure size.
2. Set the structure's **RootClass** member to **WdfPropertyStoreRootClassDeviceInterfaceKey**.
3. Set the **Qualifier.DeviceInterfaceKey.InterfaceGUID** member to the GUID that the driver specified to a previous call to [IWDFDevice::CreateDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createdeviceinterface).
4. Set the **Qualifier.DeviceInterfaceKey.ReferenceString** member to the reference string that the driver specified to a previous call to [IWDFDevice::CreateDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createdeviceinterface), or **NULL** if the driver did not specify a reference string.

The driver can obtain read or write access to the device interface key.

To open the [DEVICEMAP key](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers), your driver must:

1. Set the structure's **LengthCb** member to the structure size.
2. Set the structure's **RootClass** member to **WdfPropertyStoreRootClassLegacyHardwareKey**.
3. Set the **Qualifier.LegacyHardwareKey.LegacyMapName** member to a character string that specifies a subkey under the **HKEY_LOCAL_MACHINE\HARDWARE\DEVICEMAP** key in the registry.

The driver can obtain read or write access to the specified subkey under the **DEVICEMAP** key. The driver can optionally create the subkey if it does not exist. However, a driver that creates this subkey must specify the [WdfPropertyStoreCreateVolatile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_property_store_retrieve_flags) flag so that the system deletes the subkey each time that it restarts.

For more information about these registry keys, see [Using the Registry in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers).

## See also

[IWDFPropertyStoreFactory::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfpropertystorefactory-retrievedevicepropertystore)