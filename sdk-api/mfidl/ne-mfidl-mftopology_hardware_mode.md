# MFTOPOLOGY_HARDWARE_MODE enumeration

## Description

Specifies whether the topology loader will insert hardware-based Media Foundation transforms (MFTs) into the topology.

## Constants

### `MFTOPOLOGY_HWMODE_SOFTWARE_ONLY:0`

Use only software MFTs. Do not use hardware-based MFTs. This mode is the default, for backward compatibility with existing applications.

### `MFTOPOLOGY_HWMODE_USE_HARDWARE:1`

Use hardware-based MFTs when possible, and software MFTs otherwise. This mode is the recommended one.

### `MFTOPOLOGY_HWMODE_USE_ONLY_HARDWARE:2`

If hardware-based MFTs are available, the topoloader will insert
them. If not, the connection will fail.

Supported in Windows 8.1 and later.

## Remarks

This enumeration is used with the [MF_TOPOLOGY_HARDWARE_MODE](https://learn.microsoft.com/windows/desktop/medfound/mf-topology-hardware-mode) topology attribute.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)