# NETISO_FLAG enumeration

## Description

The **NETISO_FLAG** enumerated type specifies whether binaries should be returned for app containers.

## Constants

### `NETISO_FLAG_FORCE_COMPUTE_BINARIES:0x1`

Specifies that all binaries will be computed before the app container is returned.

This flag should be set if the caller requires up-to-date and complete information on app container binaries. If this flag is not set, returned data may be stale or incomplete.

### `NETISO_FLAG_MAX:0x2`

Maximum value for testing purposes.

## Remarks

By default, binaries are not returned. **NETISO_FLAG_FORCE_COMPUTE_BINARIES** must be set in order for these to be returned.