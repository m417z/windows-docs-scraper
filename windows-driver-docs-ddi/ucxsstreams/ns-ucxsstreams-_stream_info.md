# _STREAM_INFO structure

## Description

This structure stores information about a stream associated with a bulk endpoint.

## Members

### `Size`

The size in bytes of this structure.

### `WdfQueue`

A handle to the framework queue object that contains streams.

### `StreamId`

The stream identifier. The open-static streams request obtains stream identifiers that are assigned by the USB driver stack.