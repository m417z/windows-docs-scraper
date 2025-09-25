# CTL_VERIFY_USAGE_PARA structure

## Description

The **CTL_VERIFY_USAGE_PARA** structure contains parameters used by
[CertVerifyCTLUsage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyctlusage) to establish the validity of a CTL's usage.

## Members

### `cbSize`

Size of this structure in bytes.

### `ListIdentifier`

[BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) that specifies a **ListIdentifier** of a [CTL](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to be found or verified. Normally the **cbData** member of the **ListIdentifier** BLOB will be zero, indicating that a CTL with any **ListIdentifier** can be a match.

To match only CTLs with no **ListIdentifier**, the **cbData** member of the **ListIdentifier** BLOB is set to CTL_FIND_NO_LIST_ID_CBDATA.

If an issuer creates multiple CTLs for the same **SubjectUsage**, a **ListIdentifier** can distinguish among them.

### `cCtlStore`

The count of stores to be searched for a matching CTL.

### `rghCtlStore`

Array of handles of stores to be searched to find a matching CTL.

### `cSignerStore`

Count of stores to be searched for acceptable CTL signers.

### `rghSignerStore`

Array of handles of stores to be searched for acceptable CTL signers.

## See also

[CertVerifyCTLUsage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyctlusage)