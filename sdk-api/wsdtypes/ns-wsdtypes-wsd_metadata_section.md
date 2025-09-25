# WSD_METADATA_SECTION structure

## Description

Represents a section of metadata in a generic form.

**Note** Only one of the **Data**, **MetadataReference**, or **Location** members should be specified.

## Members

### `Dialect`

The format and version of the metadata section.

| Value | Meaning |
| --- | --- |
| **http://schemas.xmlsoap.org/ws/2006/02/devprof/ThisModel** | The metadata section contains model-specific information relating to the device. If the **Data** member is specified, then its type is [WSD_THIS_MODEL_METADATA](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_this_model_metadata). |
| **http://schemas.xmlsoap.org/ws/2006/02/devprof/ThisDevice** | The metadata section contains metadata that is unique to a specific device. If the **Data** member is specified, then its type is [WSD_THIS_DEVICE_METADATA](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_this_device_metadata). |
| **`http://schemas.xmlsoap.org/ws/2006/02/devprof/Relationship`** | The metadata section contains metadata about the relationship between two or more services. If the **Data** member is specified, then its type is [WSD_RELATIONSHIP_METADATA](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_relationship_metadata). |

### `Identifier`

The dialect-specific identifier for the scope/domain/namespace of the metadata section.

### `Data`

Reference to a binary representation of the metadata. The type of metadata is specified by **Dialect**. This member is ignored if **Dialect** does not have a value of `http://schemas.xmlsoap.org/ws/2006/02/devprof/ThisModel`, `http://schemas.xmlsoap.org/ws/2006/02/devprof/ThisDevice`, or `http://schemas.xmlsoap.org/ws/2006/02/devprof/Relationship`.

### `MetadataReference`

Reference to a [WSD_ENDPOINT_REFERENCE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_endpoint_reference) structure used identify the endpoint from which metadata can be retrieved.

### `Location`

A URI that specifies the location from which metadata can be retrieved.

### `Any`

Reference to a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that specifies extension content allowed by the XML **ANY** keyword.