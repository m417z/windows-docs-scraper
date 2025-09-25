# D2D1_THREADING_MODE enumeration

## Description

Specifies the threading mode used while simultaneously creating the device, factory, and device context.

## Constants

### `D2D1_THREADING_MODE_SINGLE_THREADED`

Resources may only be invoked serially. Device context state is not protected from multi-threaded access.

### `D2D1_THREADING_MODE_MULTI_THREADED`

Resources may be invoked from multiple threads. Resources use interlocked reference counting and their state is protected.

### `D2D1_THREADING_MODE_FORCE_DWORD:0xffffffff`

## See also

[D2D1_CREATION_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_creation_properties)

[Multithreaded Direct2D Apps](https://learn.microsoft.com/windows/desktop/Direct2D/multi-threaded-direct2d-apps)