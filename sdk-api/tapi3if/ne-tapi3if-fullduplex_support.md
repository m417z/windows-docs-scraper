# FULLDUPLEX_SUPPORT enumeration

## Description

The
**FULLDUPLEX_SUPPORT** enum is used by applications interacting with legacy TSPs to indicate whether a specified terminal supports full duplex operations. This enum is returned by the
[ITLegacyWaveSupport::IsFullDuplex](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacywavesupport-isfullduplex) method.

## Constants

### `FDS_SUPPORTED:0`

Full duplex supported.

### `FDS_NOTSUPPORTED`

Full duplex not supported.

### `FDS_UNKNOWN`

The TSP cannot determine whether the device is full duplex.

## See also

[ITLegacyWaveSupport::IsFullDuplex](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacywavesupport-isfullduplex)