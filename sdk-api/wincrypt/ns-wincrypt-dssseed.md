# DSSSEED structure

## Description

The **DSSSEED** structure holds the seed and counter values that can be used to verify the primes of the DSS public key.

## Members

### `counter`

A **DWORD** containing the counter value. If the counter value is 0xFFFFFFFF, the seed and counter values are not available.

### `seed`

A **BYTE** string containing the seed value.

## See also

[DSSPUBKEY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381982(v=vs.85))

[PUBLICKEYSTRUC](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-publickeystruc)

[RSAPUBKEY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-rsapubkey)