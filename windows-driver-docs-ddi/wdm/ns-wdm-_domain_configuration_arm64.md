# _DOMAIN_CONFIGURATION_ARM64 structure

## Description

Contains information required to configure a domain for an ARM64 system.

## Members

### `Ttbr0`

The base address of translation table 0.

### `Ttbr1`

The base address of translation table 0.

### `Mair0`

Memory attribute indirection registers 0.

### `Mair1`

Memory attribute indirection registers 1.

### `InputSize0`

Desired input address width for TTBR0.

### `InputSize1`

Desired input address width for TTBR1.

### `CoherentTableWalks`

Enables or disables coherent translation table walks. This is available starting in Windows 10, version 1809.

### `TranslationEnabled`

Enables or disables translations. If not enabled, all transactions bypass S1 translations. This is available starting in Windows 10, version 1809.

## Remarks

## See also