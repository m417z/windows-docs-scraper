# NS_HELPER_ATTRIBUTES structure

## Description

The
**NS_HELPER_ATTRIBUTES** structure provides attributes of a helper.

## Members

### `dwVersion`

The version of the helper.

### `dwReserved`

Reserved. Must be zero.

### `_ullAlign`

### `guidHelper`

The GUID of the helper.

### `pfnStart`

A pointer to the
[NS_HELPER_START_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_helper_start_fn) entry point (the start function) of the helper.

### `pfnStop`

A pointer to the
[NS_HELPER_STOP_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_helper_stop_fn) entry point (the stop function) of the helper. Set to null if no stop function is implemented.

## See also

[NS_HELPER_START_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_helper_start_fn)

[NS_HELPER_STOP_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_helper_stop_fn)