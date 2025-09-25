# CERT_QC_STATEMENT structure

## Description

The **CERT_QC_STATEMENT** structure represents a single statement in a sequence of one or more statements for inclusion in a Qualified Certificate (QC) statements extension. This structure populates the **rgStatement** member of the [CERT_QC_STATEMENTS_EXT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_qc_statements_ext_info) structure.

## Members

### `pszStatementId`

A pointer to a string that contains the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for the defined statement.

The Wincrypt.h file defines the following [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs) for use with this member, but this member can be any OID as required by an application.

| Value | Meaning |
| --- | --- |
| **szOID_QC_EU_COMPLIANCE**<br><br>"0.4.0.1862.1.1" | European Union |
| **szOID_QC_SSCD**<br><br>"0.4.0.1862.1.4" | Secure Signature Creation Device |

### `StatementInfo`

An optional [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) that contains additional information that qualifies the defined statement. The **pszStatementId** member defines the syntax of this parameter.