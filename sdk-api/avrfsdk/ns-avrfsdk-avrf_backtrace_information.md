# AVRF_BACKTRACE_INFORMATION structure

## Description

Contains information about backtraces performed.

## Members

### `Depth`

The number of traces that have been collected.

### `Index`

A unique identifier associated with the entire set of returned addresses.

### `ReturnAddresses`

An array of addresses returned traces. The number cannot exceed AVRF_MAX_TRACES, which is defined as 32.

## See also

[Resource Enumeration](https://learn.microsoft.com/windows/desktop/DevNotes/resource-enumeration)

[VerifierEnumerateResource](https://learn.microsoft.com/windows/desktop/api/avrfsdk/nf-avrfsdk-verifierenumerateresource)