# ICertServerPolicy::EnumerateAttributes

## Description

The **EnumerateAttributes** method retrieves the name of the current attribute and moves the internal enumeration pointer to the next attribute.

## Parameters

### `pstrAttributeName` [out]

A pointer to the attribute name.

## Return value

### C++

If the method succeeds, the method returns S_OK, and the *pstrAttributeName* parameter is set to a **BSTR** that contains the name of the attribute. A value of S_FALSE is returned if the last attribute was already enumerated.

To use this method, create a variable of **BSTR** type, set the variable equal to **NULL**, and then pass the address of this variable as *pstrAttributeName*.

When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

Returns a string that contains the name of the attribute, or an empty string if the last attribute was already enumerated.

## Remarks

Before calling the **EnumerateAttributes** method for the first time, call
the [EnumerateAttributesSetup](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateattributessetup) method to initialize the enumeration pointer to the first attribute.

 When done enumerating, call
the [EnumerateAttributesClose](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateattributesclose) method to free resources used by the enumeration calls.

## See also

[ICertServerPolicy](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverpolicy)

[ICertServerPolicy::EnumerateAttributesClose](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateattributesclose)

[ICertServerPolicy::EnumerateAttributesSetup](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateattributessetup)