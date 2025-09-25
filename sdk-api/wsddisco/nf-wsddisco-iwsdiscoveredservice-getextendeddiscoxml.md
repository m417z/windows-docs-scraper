# IWSDiscoveredService::GetExtendedDiscoXML

## Description

Retrieves custom or extensible data provided in the header or body of the SOAP message.

## Parameters

### `ppHeaderAny` [out]

Custom data added to the header portion of the SOAP message. For details, see [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element). Do not deallocate the output structure.

### `ppBodyAny` [out]

Custom data added to the body portion of the SOAP message. For details, see [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element). Do not deallocate the output structure.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |

## Remarks

Some devices may add custom data to the header and body portions of the SOAP message to convey additional information in the discovery phase.

The resulting pointer values are only valid for the lifetime of the [IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice) object.

## See also

[IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice)