# WSD_SYNCHRONOUS_RESPONSE_CONTEXT structure

## Description

Provides a context for handling the response to a two-way request.

## Members

### `hr`

The result code of the last operation performed using this response context.

### `eventHandle`

The event handle to be signaled when the response is ready.

### `messageParameters`

A pointer to an [IWSDMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdmessageparameters) object that contains transport information associated with the response.

### `results`

The body of the response message.