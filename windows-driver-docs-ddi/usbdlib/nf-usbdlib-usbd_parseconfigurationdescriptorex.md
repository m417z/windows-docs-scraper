# USBD_ParseConfigurationDescriptorEx function

## Description

The **USBD_ParseConfigurationDescriptorEx** routine searches a given configuration descriptor and returns a pointer to an interface that matches the given search criteria.

## Parameters

### `ConfigurationDescriptor` [in]

Pointer to a USB configuration descriptor that contains the interface for which to search.

### `StartPosition` [in]

Pointer to the address within the configuration descriptor, provided at *ConfigurationDescriptor*, to begin searching from. To search from the beginning of the configuration descriptor, the parameters *ConfigurationDescriptor* and *StartPosition* must be the same address.

### `InterfaceNumber` [in]

Specifies the device-defined index of the interface to be retrieved. This should be set to -1 if it should not be a search criterion.

### `AlternateSetting` [in]

Specifies the device-defined alternate-setting index of the interface to be retrieved. If the caller does not wish the alternate setting value to be a search criterion, this parameter should be set to -1.

### `InterfaceClass` [in]

Specifies the device- or USB-defined identifier for the interface class of the interface to be retrieved. If the caller does not wish the interface class value to be a search criterion, this parameter should be set to -1.

### `InterfaceSubClass` [in]

Specifies the device- or USB-defined identifier for the interface subclass of the interface to be retrieved. If the caller does not wish the interface subclass value to be a search criterion, this parameter should be set to -1.

### `InterfaceProtocol` [in]

Specifies the device- or USB-defined identifier for the interface protocol of the interface to be retrieved. If the caller does not wish the interface protocol value to be a search criterion, this parameter should be set to -1.

## Return value

**USBD_ParseConfigurationDescriptorEx** returns a pointer to the first interface descriptor that matches the given search criteria. If no interface matches the search criteria, it returns **NULL**.

## Remarks

Callers can specify more than one of the search criteria (InterfaceNumber, AlternateSetting, InterfaceClass, InterfaceSubClass, and InterfaceProtocol) when using this routine to find an interface within a configuration descriptor. For example code, see [USBD_CreateConfigurationRequestEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createconfigurationrequestex).

When this routine parses the configuration descriptor looking for the interface descriptor that matches the search criteria, it returns the first match, terminating the search. Callers should specify as many search criteria as are necessary to find the desired interface.

## See also

[USB device driver programming reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/)

[USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor)