# ICertServerExit::EnumerateAttributesClose

## Description

The **EnumerateAttributesClose** method frees any resources connected with [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) enumeration.

All applications that use
[ICertServerExit::EnumerateAttributesSetup](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-enumerateattributessetup) or
[ICertServerExit::EnumerateAttributes](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-enumerateattributes) should call **EnumerateAttributesClose** when finished enumerating.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICertServerExit](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverexit)

[ICertServerExit::EnumerateAttributes](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-enumerateattributes)

[ICertServerExit::EnumerateAttributesSetup](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-enumerateattributessetup)