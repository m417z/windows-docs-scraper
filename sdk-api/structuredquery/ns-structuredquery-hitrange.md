# HITRANGE structure

## Description

Identifies the range of matching data when query search conditions match indexed data.

## Members

### `iPosition`

Type: **ULONG**

The beginning of the hit range.

### `cLength`

Type: **ULONG**

The length of the hit range.

## Remarks

The **HITRANGE** structure is useful for identifying where a search term matches the content from returned results, and for hit highlighting in user interfaces.