# SecPkgContext_Sizes structure

## Description

The **SecPkgContext_Sizes** structure indicates the sizes of important structures used in the message support functions. The
[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function uses this structure.

## Members

### `cbMaxToken`

Specifies the maximum size of the security token used in the authentication exchanges.

### `cbMaxSignature`

Specifies the maximum size of the signature created by the
[MakeSignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-makesignature) function. This member must be zero if [integrity](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) services are not requested or available.

### `cbBlockSize`

Specifies the preferred integral size of the messages. For example, eight indicates that messages should be of size zero mod eight for optimal performance. Messages other than this block size can be padded.

### `cbSecurityTrailer`

Size of the security trailer to be appended to messages. This member should be zero if the relevant services are not requested or available.

## See also

[MakeSignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-makesignature)

[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa)