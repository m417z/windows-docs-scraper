# D2D1_DEBUG_LEVEL enumeration

## Description

Indicates the type of information provided by the [Direct2D Debug Layer](https://learn.microsoft.com/windows/win32/Direct2D/direct2ddebuglayer-overview).

## Constants

### `D2D1_DEBUG_LEVEL_NONE:0`

Direct2D does not produce any debugging output.

### `D2D1_DEBUG_LEVEL_ERROR:1`

Direct2D sends error messages to the debug layer.

### `D2D1_DEBUG_LEVEL_WARNING:2`

Direct2D sends error messages and warnings to the debug layer.

### `D2D1_DEBUG_LEVEL_INFORMATION:3`

Direct2D sends error messages, warnings, and additional diagnostic information that can help improve performance to the debug layer.

### `D2D1_DEBUG_LEVEL_FORCE_DWORD:0xffffffff`

## Remarks

To receive debugging messages, you must install the [Direct2D Debug Layer](https://learn.microsoft.com/windows/win32/Direct2D/direct2ddebuglayer-overview).

## See also

[D2D1_FACTORY_OPTIONS](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_factory_options)

[Direct2D Debug Layer](https://learn.microsoft.com/windows/win32/Direct2D/direct2ddebuglayer-overview)