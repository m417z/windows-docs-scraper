# WICComponentSigning enumeration

## Description

Specifies the component signing status.

## Constants

### `WICComponentSigned:0x1`

A signed component.

### `WICComponentUnsigned:0x2`

An unsigned component

### `WICComponentSafe:0x4`

A component is safe.

Components that do not have a binary component to sign, such as a pixel format, should return this value.

### `WICComponentDisabled:0x80000000`

A component has been disabled.

### `WICCOMPONENTSIGNING_FORCE_DWORD:0x7fffffff`