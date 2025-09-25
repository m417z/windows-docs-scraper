# CERT_QC_STATEMENTS_EXT_INFO structure

## Description

The **CERT_QC_STATEMENTS_EXT_INFO** structure contains a sequence of one or more statements that make up the Qualified Certificate (QC) statements extension for a QC.

## Members

### `cStatement`

A value that represents the size, in bytes, of the **rgStatement** array.

### `rgStatement`

An array of [CERT_QC_STATEMENT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_qc_statement) structures that contains the sequence of statements that make up the QC statements extension.

## See also

[RFC 3280](https://www.ietf.org/rfc/rfc3280.txt)

[RFC 3739](https://www.ietf.org/rfc/rfc3739.txt)