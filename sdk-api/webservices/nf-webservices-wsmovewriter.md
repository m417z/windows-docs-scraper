# WsMoveWriter function

## Description

Moves the current position of the writer as specified by the moveTo parameter.

## Parameters

### `writer` [in]

The writer to move.

### `moveTo` [in]

The relative position to move the writer.

### `found`

If this is non-**NULL**, then whether or not the new position could be moved to is returned here.

If this is **NULL**, and the position could not be moved to, then the function will return **WS_E_INVALID_FORMAT**.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |

## Remarks

This can only be used on a writer that is set to an [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer).

If the found parameter is not **NULL**, then it will indicate there whether or not it could
move to the requested node and return NOERROR.

If the found parameter is **NULL**, and the requested node is not found, it will return **WS_E_INVALID_FORMAT**.

Once positioned, the writer will then insert new data before the position specified.