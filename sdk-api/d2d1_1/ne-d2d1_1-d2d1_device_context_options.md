# D2D1_DEVICE_CONTEXT_OPTIONS enumeration

## Description

This specifies options that apply to the device context for its lifetime.

## Constants

### `D2D1_DEVICE_CONTEXT_OPTIONS_NONE:0`

The device context is created with default options.

### `D2D1_DEVICE_CONTEXT_OPTIONS_ENABLE_MULTITHREADED_OPTIMIZATIONS:1`

Distribute rendering work across multiple threads. Refer to [Improving the performance of Direct2D apps](https://learn.microsoft.com/windows/desktop/Direct2D/improving-direct2d-performance) for additional notes on the use of this flag.

### `D2D1_DEVICE_CONTEXT_OPTIONS_FORCE_DWORD:0xffffffff`