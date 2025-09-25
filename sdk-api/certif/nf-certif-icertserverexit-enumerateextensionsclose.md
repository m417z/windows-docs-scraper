# ICertServerExit::EnumerateExtensionsClose

## Description

The **EnumerateExtensionsClose** method frees any resources connected with extension enumeration.

All applications that use [ICertServerExit::EnumerateExtensionsSetup](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-enumerateextensionssetup) and [ICertServerExit::EnumerateExtensions](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-enumerateextensions) should call **EnumerateExtensionsClose** when finished enumerating.

## See also

**CCertServerExit**

[ICertServerExit](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverexit)