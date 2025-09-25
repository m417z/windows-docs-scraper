# WS_REPEATING_HEADER_OPTION enumeration

## Description

This enum is used to specify whether a header is expected
to appear more than once in a message.

## Constants

### `WS_REPEATING_HEADER:1`

The header may appear more than once in the message.

### `WS_SINGLETON_HEADER:2`

The header may appear at most once in the message.
When this option is specified, the function
ensures that the specified header appears
at most once in the message.