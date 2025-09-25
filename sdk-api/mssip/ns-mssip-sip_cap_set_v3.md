# SIP_CAP_SET_V3 structure

## Description

The **SIP_CAP_SET** structure defines the capabilities of a [subject interface package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIP).

## Members

### `cbSize`

Size, in bytes, of this structure.

### `dwVersion`

The SIP version. By default, this value is two (2).

### `isMultiSign`

A value of one (1) indicates that the SIP supports multiple embedded signatures. Otherwise, set this value to zero (0).

### `dwFlags`

### `dwReserved`

Reserved for future use. Set this value to zero (0).