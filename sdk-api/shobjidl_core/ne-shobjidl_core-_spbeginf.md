# _SPBEGINF enumeration

## Description

Used by [IActionProgress::Begin](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iactionprogress-begin), these constants specify certain UI operations that are to be enabled or disabled.

## Constants

### `SPBEGINF_NORMAL:0`

Indicates default progress behavior.

### `SPBEGINF_AUTOTIME:0x2`

Indicates that the progress UI should automatically update a text field with the amount of time remaining until the action completes.

### `SPBEGINF_NOPROGRESSBAR:0x10`

Indicates that the UI should not display a progress bar.

### `SPBEGINF_MARQUEEPROGRESS:0x20`

Indicates that the UI should use a marquee-style progress bar.

### `SPBEGINF_NOCANCELBUTTON:0x40`

Indicates that the UI should not include a **Cancel** button.

## See also

[IActionProgress](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iactionprogress)

[IActionProgress::Begin](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iactionprogress-begin)