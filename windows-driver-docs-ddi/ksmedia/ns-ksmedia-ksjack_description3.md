## Description

This topic describes the **KSJACK_DESCRIPTION3** structure.

## Members

### `ConfigId`

Defines the **ULONG** member **ConfigId**.

## Remarks

This is a driver defined bitmask or enum describing the current configuration. Changing this value causes audioendpointbuilder to refresh the cache to ensure that the published endpoint matches the current config.

## See also