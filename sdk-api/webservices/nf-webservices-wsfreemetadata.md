# WsFreeMetadata function

## Description

Releases the memory resource associated with a metadata object.

## Parameters

### `metadata` [in]

A pointer to the metadata object to release. The pointer must reference a valid [WS_METADATA](https://learn.microsoft.com/windows/desktop/wsw/ws-metadata) object returned
by [WsCreateMetadata](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemetadata) and the referenced value may not be **NULL**.

## Remarks

Any [WS_POLICY](https://learn.microsoft.com/windows/desktop/wsw/ws-policy) objects that
were retrieved using the metadata object will also be freed.