# WsVerifyXmlNCName function

## Description

Verifies whether the input string is a valid XML NCName.

## Parameters

### `ncNameChars`

The string to be verified.

### `ncNameCharCount` [in]

The length of the *ncNameChars* string.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The string is not a valid NCName. |