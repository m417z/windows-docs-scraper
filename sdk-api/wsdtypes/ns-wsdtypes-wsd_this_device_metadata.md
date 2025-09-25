# WSD_THIS_DEVICE_METADATA structure

## Description

Specifies metadata that is unique to a specific device.

## Members

### `FriendlyName`

Reference to a [WSD_LOCALIZED_STRING_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_localized_string_list) structure that contains the list of localized friendly names for the device. It should be set to fewer than 256 characters.

### `FirmwareVersion`

The firmware version of the device. It should be set to fewer than 256 characters.

### `SerialNumber`

The serial number of the device. It should be set to fewer than 256 characters.

### `Any`

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that provides an extensible space for devices to add custom metadata to the device specific section. For example, you can use this to add a user-defined name for the device.

## Remarks

ThisDevice metadata follows this form:

``` syntax
<wsd:ThisDevice>
    <wsd:FriendlyName>
        A. Datum WebWeigh Scale
    </wsd:FriendlyName>
    <wsd:FirmwareVersion>
        2.53c
    </wsd:FirmwareVersion>
    <wsd:SerialNumber>
        923450982349058
    </wsd:SerialNumber>
 </wsd:ThisDevice>
```