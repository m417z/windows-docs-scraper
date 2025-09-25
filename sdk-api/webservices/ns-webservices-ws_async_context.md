# WS_ASYNC_CONTEXT structure

## Description

Used with the Async Model to specify the asynchronous callback and
a pointer which will be passed to the asynchronous callback.

## Members

### `callback`

The callback function to call if the operation completes asynchronously.
This field may not be **NULL**.

### `callbackState`

A pointer to user-defined data which will passed to the asynchronous callback
function if the operation completes asynchronously.