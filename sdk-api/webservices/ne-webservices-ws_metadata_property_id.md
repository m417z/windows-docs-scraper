# WS_METADATA_PROPERTY_ID enumeration

## Description

Each metadata property is of type [WS_METADATA_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_metadata_property), is identified by an ID, and has an associated value. If a property is not specified when the metadata is created,
then its default value is used.

## Constants

### `WS_METADATA_PROPERTY_STATE:1`

This property is used with [WsGetMetadataProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmetadataproperty).

The accompanying **value** member of the [WS_METADATA_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_metadata_property) structure contains the current [WS_METADATA_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_metadata_state) of the metadata object.

### `WS_METADATA_PROPERTY_HEAP_PROPERTIES:2`

This property is used with [WsCreateMetadata](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemetadata) to specify
properties of the [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) object used by the metadata
object to store information about the metadata that was read.

The accompanying **value** member of the [WS_METADATA_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_metadata_property) structure contains a [WS_HEAP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_heap_properties) structure.

The following heap properties may be specified:

* [WS_HEAP_PROPERTY_MAX_SIZE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_heap_property_id). If not specified, the
  default value used is 256k bytes.
* [WS_HEAP_PROPERTY_TRIM_SIZE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_heap_property_id). If not specified, the
  default value used is 32k bytes.

### `WS_METADATA_PROPERTY_POLICY_PROPERTIES:3`

This property is used with [WsCreateMetadata](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemetadata) to specify
properties of the [WS_POLICY](https://learn.microsoft.com/windows/desktop/wsw/ws-policy) objects that are associated
with the metadata object.

The accompanying **value** member of the [WS_METADATA_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_metadata_property) structure contains a [WS_POLICY_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_policy_properties) structure that specifies the
set of policy properties.

See [WS_POLICY_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_policy_property_id) for more information on the
set of properties that may be specified here.

### `WS_METADATA_PROPERTY_HEAP_REQUESTED_SIZE:4`

This property is used with [WsGetMetadataProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmetadataproperty).

The accompanying **value** member of the [WS_METADATA_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_metadata_property) is a **SIZE_T** specifying the number of bytes allocated from the heap associated with the
metadata object.

### `WS_METADATA_PROPERTY_MAX_DOCUMENTS:5`

This property is used with [WsCreateMetadata](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemetadata).

The accompanying **value** member of the [WS_METADATA_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_metadata_property) is a **ULONG** specifying the maximum number of documents that may be added to
the metadata object using [WsReadMetadata](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmetadata).

The default value is 32.

### `WS_METADATA_PROPERTY_HOST_NAMES:6`

This property is used with [WsCreateMetadata](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemetadata).

The accompanying **value** member of the [WS_METADATA_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_metadata_property) is a [WS_HOST_NAMES](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_host_names) structure.

This property may only be specified if [WS_METADATA_PROPERTY_VERIFY_HOST_NAMES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_metadata_property_id) is **TRUE**.

See [WsGetMissingMetadataDocumentAddress](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmissingmetadatadocumentaddress) for more information
on verifying host names.

If the property is not specified, then the list of host names is empty.

### `WS_METADATA_PROPERTY_VERIFY_HOST_NAMES:7`

This property is used with [WsCreateMetadata](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemetadata).

The accompanying **value** member of the [WS_METADATA_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_metadata_property) is a **BOOL** that specifies whether or not host names should be verified.

See [WsGetMissingMetadataDocumentAddress](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmissingmetadatadocumentaddress) for more information
on verifying host names.

The default value is **TRUE**.

Setting this value to **FALSE** may cause an application to use
an address returned from [WsGetMissingMetadataDocumentAddress](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmissingmetadatadocumentaddress) that is from a host that it is not willing to accept metadata from.