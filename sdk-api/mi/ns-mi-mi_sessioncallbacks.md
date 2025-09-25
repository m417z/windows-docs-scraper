## Description

A container for callback function pointers that handle logging and error messages.

## Members

### `callbackContext`

A client-specific context that is passed to all of the callbacks. This is used to correlate the callback to the associated operation.

### `writeError`

The CIM extension callback for errors. The session version of this function is informative only. The session will fail to create and will return an error. All parameters are valid only for the lifetime of the callback.

### `writeMessage`

The CIM extension callback for receiving logging from the session creation. All parameters are valid only for the lifetime of the callback.

## Remarks

This is the structure that holds all callback function pointers. Fill in the ones
you want to receive. All callbacks are CIM extensions for tracking
logging and error messages.