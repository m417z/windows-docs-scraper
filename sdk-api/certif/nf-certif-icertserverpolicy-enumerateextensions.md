# ICertServerPolicy::EnumerateExtensions

## Description

The **EnumerateExtensions** method retrieves the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of the current extension and moves the internal enumeration pointer to the next extension.

## Parameters

### `pstrExtensionName` [out]

A pointer to a **BSTR** that contains the OID of the current extension.

## Return value

### C++

If the method succeeds, the method returns S_OK, and the *pstrExtensionName* parameter contains the OID of the current extension. A value of S_FALSE is returned if the last extension was already enumerated.

To use this method, create a variable of **BSTR** type, set the variable equal to **NULL**, and pass the address of this variable as *pstrExtensionName*.

When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

Returns a string that contains the OID of the extension, or an empty string if the last extension was already enumerated.

## Remarks

This method enumerates certificate extensions recorded in the database, even those that are disabled and do not appear in the certificate. To determine whether an extension is disabled, use
[GetCertificateExtensionFlags](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-getcertificateextensionflags) to test the extension's EXTENSION_DISABLE_FLAG bit.

When done enumerating, call the [EnumerateExtensionsClose](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateextensionsclose) method to free resources used by the enumeration calls.

#### Examples

``` syntax
#include <windows.h>
#include <stdio.h>
#include <Certif.h>

BSTR     bstrExt = NULL;
VARIANT  varExt;
LONG     ExtFlags;
HRESULT  hr;

VariantInit(&varExt);

// Enumerate the extensions.
while (S_OK ==
      (hr = pCertServerPol->EnumerateExtensions(&bstrExt)))
{
  // Retrieve the extension data.
  if (FAILED(pCertServerPol->GetCertificateExtension(
                             bstrExt,
                             PROPTYPE_BINARY,
                             &varExt)))
      printf("Failed GetCertificateExtension\n");
  else
  {
     // Retrieve the extension flags.
    if (FAILED(pCertServerPol->GetCertificateExtensionFlags(
                               &ExtFlags)))
        printf("Failed GetCertificateExtensionFlags\n");
    else
        // This sample will display the extension OID string,
        // the extension flags (in hex) and
        // the length of the BSTR binary ASN-encode extension.
        printf("Extension: %ws\tFlags:%x\tLength:%u\n",
               bstrExt,
               ExtFlags,
               SysStringByteLen(varExt.bstrVal));
  }
}
// Determine if hr was S_FALSE, meaning the enumeration
// was completed, or some other error.
if (S_FALSE != hr)
    printf("Failed EnumerateExtensions - %x\n", hr);
// Free BSTR resource.
if (NULL != bstrExt)
    SysFreeString(bstrExt);
// Free VARIANT resource.
    VariantClear(&varExt);

```

## See also

[EnumerateExtensionsClose](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateextensionsclose)

[EnumerateExtensionsSetup](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateextensionssetup)

[GetCertificateExtension](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-getcertificateextension)

[GetCertificateExtensionFlags](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-getcertificateextensionflags)

[ICertServerPolicy](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverpolicy)