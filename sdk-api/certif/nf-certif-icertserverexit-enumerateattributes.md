# ICertServerExit::EnumerateAttributes

## Description

The **EnumerateAttributes** method returns the name of the next request attribute within the current context, then increments the internal pointer to the following [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly).

Before calling **EnumerateAttributes**, an application calls
[ICertServerExit::EnumerateAttributesSetup](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-enumerateattributessetup). When done enumerating, an application calls
[ICertServerExit::EnumerateAttributesClose](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-enumerateattributesclose).

## Parameters

### `pstrAttributeName` [out]

A pointer to the enumerated attribute name.

## Return value

### C++

If the method succeeds, the method returns S_OK, and **pstrAttributeName* is set to the **BSTR** that contains the name of the enumerated [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly). A value of S_FALSE is returned if the last attribute was already enumerated.

To use this method, create a variable of **BSTR** type, set the variable equal to **NULL**, and pass the address of this variable as *pstrAttributeName*.

When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

Returns a string that contains the name of the enumerated attribute, or an empty string if the last attribute was already enumerated.

## See also

[ICertServerExit](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverexit)

[ICertServerExit::EnumerateAttributesClose](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-enumerateattributesclose)

[ICertServerExit::EnumerateAttributesSetup](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-enumerateattributessetup)

[ICertServerExit::GetRequestAttribute](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-getrequestattribute)