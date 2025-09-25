# WS_METADATA_STATE enumeration

## Description

The state of the metadata object.

## Constants

### `WS_METADATA_STATE_CREATED:1`

The initial state of the metadata object.

### `WS_METADATA_STATE_RESOLVED:2`

All references between metadata documents have been
resolved and no more metadata documents may be added
to the metadata object. See [WsGetMetadataEndpoints](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmetadataendpoints) for
more information.

### `WS_METADATA_STATE_FAULTED:3`

The metadata object not usable due to a previous error. See
See [WsGetMetadataEndpoints](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmetadataendpoints) and [WsReadMetadata](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmetadata) for more information.

## Remarks

The following diagram illustrates the functions that
cause state transitions in the metadata object.
:::image type="content" source="./images/MetadataStates.png" border="false" alt-text="Diagram of the state transitions for a Metadata object showing the functions that cause transitions between the Created, Faulted, and Resolved states.":::