# WSD_THIS_MODEL_METADATA structure

## Description

Provides model-specific information relating to the device.

## Members

### `Manufacturer`

Reference to a [WSD_LOCALIZED_STRING_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_localized_string_list) structure that contains the manufacturer name. The name should be set to fewer than 2048 characters.

### `ManufacturerUrl`

The URL to a Web site for the device manufacturer. The URL should have fewer than 2048 characters.

### `ModelName`

Reference to a [WSD_LOCALIZED_STRING_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_localized_string_list) structure that specifies model names. This is a list of localized friendly names that should be set to fewer than 256 characters.

### `ModelNumber`

The model number. This should be set to fewer than 256 characters.

### `ModelUrl`

The URL to a Web site for this device model. The URL should have fewer than 2048 characters.

### `PresentationUrl`

An HTML page for this device. This can be relative to a base URL set by XML Base. The URL should have fewer than 2048 characters.

### `Any`

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that specifies extension content allowed by the XML **ANY** keyword.

## Remarks

**WSD_THIS_MODEL_METADATA** specifies manufacturer metadata that is common to all instances of a specific model.

Model metadata follows this form:

``` syntax
<wsd:ThisModel>
    <wsd:Manufacturer>
        A. Datum Corporation
    </wsd:Manufacturer>
    <wsd:ManufacturerURL>
        http://www.adatum.com
    </wsd:ManufacturerURL>
    <wsd:ModelName>
        WebWeigh
    </wsd:ModelName>
    <wsd:ModelNumber>
        9-23492-83049
    </wsd:ModelNumber>
    <wsd:ModelURL>
        http://www.adatum.com/WebWeighOwner.html
    </wsd:ModelURL>
    <wsd:PresentationURL>
        presentation/menu.html
    </wsd:PresentationURL>
</wsd:ThisModel>
```