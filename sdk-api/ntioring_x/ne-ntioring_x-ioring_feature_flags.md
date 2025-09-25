## Description

Represents feature support for the an I/O ring API version.

## Constants

### `IORING_FEATURE_FLAGS_NONE`

None.

### `IORING_FEATURE_UM_EMULATION`

I/O ring support is emulated in User Mode. When this flag is set there is no underlying kernel support for I/O ring. However, a user mode emulation layer is available to provide application compatibility, without the benefit of kernel support. This provides application compatibility at the expense of performance, allowing apps to make a choice at run-time. As of the current release, Microsoft does not provide an emulated I/O ring implementation. This value is provided to support potential emulated future emulated implementations.

### `IORING_FEATURE_SET_COMPLETION_EVENT`

Registration of a completion queue event is supported. For more information, see [SetIoRingCompletionEvent](https://learn.microsoft.com/windows/win32/api/ioringapi/nf-ioringapi-setioringcompletionevent).

## Remarks

## See also