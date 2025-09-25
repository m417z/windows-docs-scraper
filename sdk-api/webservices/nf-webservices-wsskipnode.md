# WsSkipNode function

## Description

Advances the reader in the input stream. If the current node is an element,
all of the children of that element are skipped, and the reader is positioned
on the node following its end element. Otherwise, the reader is positioned
on the next node in the same manner as [WsReadNode](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadnode).

## Parameters

### `reader` [in]

The reader which is to skip to the next node.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |

## Remarks

If there is an error parsing the input, the function will return **WS_E_INVALID_FORMAT**.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

This function can fail for any of the reasons listed in [WsReadNode](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadnode).