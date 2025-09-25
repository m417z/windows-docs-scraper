# CLS_LSN structure

## Description

Represents a valid log address.

## Members

### `Internal`

The log sequence number (LSN).

## Remarks

The LSN is the valid address that is unique to a client, and returned after the client appends a record to the log. The address remains valid if the system does not fail, or its marshaled log buffer is flushed successfully to disk.

In log streams, LSNs increase monotonically. You cannot compare LSNs between log streams.

## See also

[LsnCreate](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-lsncreate)