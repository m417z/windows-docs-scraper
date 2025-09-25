# WSManGetErrorMessage function

## Description

Retrieves the error messages associated with a particular error and language codes.

## Parameters

### `apiHandle` [in]

Specifies the API handle returned by a [WSManInitialize](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmaninitialize) call. This parameter cannot be **NULL**.

### `flags`

Reserved for future use. Must be zero.

### `languageCode` [in, optional]

Specifies the language code name that should be used to localize the error. For more information about the language code names, see the RFC 3066 specification from the Internet Engineering Task Force at [http://www.ietf.org/rfc/rfc3066.txt](https://www.ietf.org/rfc/rfc3066.txt). If a language code is not specified, the user interface language of the thread is used.

### `errorCode`

Specifies the error code for the requested error message. This error code can be a hexadecimal or decimal error code from a WinRM, WinHTTP, or other Windows operating system feature.

### `messageLength`

Specifies the number of characters that can be stored in the output message buffer, including the **null** terminator. If this parameter is zero, the *message* parameter must be **NULL**.

### `message` [out]

Specifies the output buffer to store the message in. This buffer must be allocated and deallocated by the client. The buffer must be large enough to store the message and the **null** terminator. If this parameter is **NULL**, the *messageLength* parameter must be **NULL**.

### `messageLengthUsed` [out]

Specifies the actual number of characters written to the output buffer, including the **null** terminator. This parameter cannot be **NULL**. If either the *messageLength* or *message* parameters are zero, the function will return **ERROR_INSUFFICIENT_BUFFER** and this parameter will be set to the number of characters needed to store the message, including the **null** terminator.

## Return value

This method returns zero on success. Otherwise, this method returns an error code.