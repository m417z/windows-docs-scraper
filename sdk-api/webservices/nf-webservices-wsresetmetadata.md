# WsResetMetadata function

## Description

Resets a metadata object state to **WS_METADATA_STATE_CREATED**.
In this state the Metadata object can be reused. [WS_POLICY](https://learn.microsoft.com/windows/desktop/wsw/ws-policy) objects that were retrieved using the Metadata object will be released.

## Parameters

### `metadata` [in]

A pointer to the **Metadata** object to reset. The pointer must reference a valid [WS_METADATA](https://learn.microsoft.com/windows/desktop/wsw/ws-metadata).

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | The metadata was in an inappropriate state. |

## Remarks

Reusing a metadata instead of creating one from scratch may improve performance.
If called correctly, this function will not fail.