# tag_WBEM_GET_TEXT_FLAGS enumeration

## Description

Contains flags which controls how the text is returned.

## Constants

### `WBEMPATH_COMPRESSED:0x1`

Obsolete. Do not use.

### `WBEMPATH_GET_RELATIVE_ONLY:0x2`

Returns the relative path, skips server and namespaces.

### `WBEMPATH_GET_SERVER_TOO:0x4`

Returns the entire path, including server and namespace.

### `WBEMPATH_GET_SERVER_AND_NAMESPACE_ONLY:0x8`

Returns only the server and namespace portion of the path. Ignores the class or key portion.

### `WBEMPATH_GET_NAMESPACE_ONLY:0x10`

Returns only the namespace portion of the path.

### `WBEMPATH_GET_ORIGINAL:0x20`

Returns whatever was passed in using
[SetText](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbempath-settext) method.