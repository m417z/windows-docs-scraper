# WICComponentEnumerateOptions enumeration

## Description

Specifies component enumeration options.

## Constants

### `WICComponentEnumerateDefault:0`

Enumerate any components that are not disabled. Because this value is 0x0, it is always included with the other options.

### `WICComponentEnumerateRefresh:0x1`

Force a read of the registry before enumerating components.

### `WICComponentEnumerateDisabled:0x80000000`

Include disabled components in the enumeration. The set of disabled components is disjoint with the set of default enumerated components

### `WICComponentEnumerateUnsigned:0x40000000`

Include unsigned components in the enumeration. This option has no effect.

### `WICComponentEnumerateBuiltInOnly:0x20000000`

At the end of component enumeration, filter out any components that are not Windows provided.

### `WICCOMPONENTENUMERATEOPTIONS_FORCE_DWORD:0x7fffffff`