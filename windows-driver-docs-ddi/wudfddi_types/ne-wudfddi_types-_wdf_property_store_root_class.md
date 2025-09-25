# _WDF_PROPERTY_STORE_ROOT_CLASS enumeration

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WDF_PROPERTY_STORE_ROOT_CLASS** enumeration identifies the registry keys that UMDF property stores represent.

## Constants

### `WdfPropertyStoreRootClassHardwareKey`

The property store represents a device's [hardware key](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers).

### `WdfPropertyStoreRootClassSoftwareKey`

The property store represents a driver's [software key](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers).

### `WdfPropertyStoreRootClassDeviceInterfaceKey`

The property store represents the key for an instance of a [device interface class](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers).

### `WdfPropertyStoreRootClassLegacyHardwareKey`

The property store represents the [DEVICEMAP key](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers), which is used by only a few older drivers.

## Remarks

The **WDF_PROPERTY_STORE_ROOT_CLASS** enumeration is used in the [WDF_PROPERTY_STORE_ROOT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wdf_property_store_root) structure.

## See also

[WDF_PROPERTY_STORE_ROOT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wdf_property_store_root)