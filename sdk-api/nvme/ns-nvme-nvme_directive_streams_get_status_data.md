# NVME_DIRECTIVE_STREAMS_GET_STATUS_DATA structure

## Description

Contains the identifiers of streams that are currently open.

## Members

### `OpenStreamCount`

The number of currently open streams.

### `StreamIdentifiers`

An array of stream IDs that indicate which streams are currently open.

The array is of size **NVME_STREAMS_GET_STATUS_MAX_IDS**.

## Remarks

## See also