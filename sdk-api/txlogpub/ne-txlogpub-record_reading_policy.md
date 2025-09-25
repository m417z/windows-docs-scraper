# RECORD_READING_POLICY enumeration

## Description

Specifies a hint about the order in which records are to be read from a log.

## Constants

### `RECORD_READING_POLICY_FORWARD:1`

Indicates that records will be read in order of increasing LSN (from least recent to most recent).

### `RECORD_READING_POLICY_BACKWARD:2`

Indicates that records will be read in order of decreasing LSN (from most recent to least recent).

### `RECORD_READING_POLICY_RANDOM:3`

Indicates that records may be read in any order.

## See also

[ILog::SetAccessPolicyHint](https://learn.microsoft.com/windows/desktop/api/txlogpub/nf-txlogpub-ilog-setaccesspolicyhint)