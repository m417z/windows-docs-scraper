# CERT_REVOCATION_CRL_INFO structure

## Description

Contains information updated by a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) revocation type handler. The **CERT_REVOCATION_CRL_INFO** structure is used with both base and delta CRLs.

## Members

### `cbSize`

Size, in bytes, of the structure.

### `pBaseCrlContext`

### `pDeltaCrlContext`

### `pCrlEntry`

A pointer to an entry in either the base CRL or the delta CRL.

### `fDeltaCrlEntry`

**TRUE** if **pCrlEntry** points to an entry in the delta CRL. **FALSE** if **pCrlEntry** points to an entry in the base CRL.

### `pBaseCRLContext`

A pointer to a base CRL context.

### `pDeltaCRLContext`

A pointer to a delta CRL context.