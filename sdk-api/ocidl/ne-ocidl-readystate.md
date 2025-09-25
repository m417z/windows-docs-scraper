# READYSTATE enumeration

## Description

**Note** This component is available for use in the Microsoft Windows 2000, Windows XP, and Windows Server 2003 operating systems. It may be altered or unavailable in subsequent versions.

The `ReadyState` property retrieves the ReadyState of the **MSWebDVD** object.

## Constants

### `READYSTATE_UNINITIALIZED:0`

Default initialization state.

### `READYSTATE_LOADING:1`

Object is loading its properties.

### `READYSTATE_LOADED:2`

Object has been initialized.

### `READYSTATE_INTERACTIVE:3`

Object is interactive, but not all its data is available.

### `READYSTATE_COMPLETE:4`

Object has received all its data.

## Remarks

This property is read-only with no default value.

Returns an integer value representing the control's ReadyState.

Any object embedded in a Web page exposes the `ReadyState` property.