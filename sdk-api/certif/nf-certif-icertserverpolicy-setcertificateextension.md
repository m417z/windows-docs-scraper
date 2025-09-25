# ICertServerPolicy::SetCertificateExtension

## Description

The **SetCertificateExtension** method adds a new extension to the certificate.

## Parameters

### `strExtensionName` [in]

Specifies the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for the extension to set. The string must be 31 or less nonnull characters in length.

### `Type` [in]

Specifies the type of extension being set. The *Type* parameter must agree with the data type of **pvarValue** that is set in the **vt** field of the **VARIANT** structure. The *Type* parameter can be set to one of the following types.

| Value | Meaning |
| --- | --- |
| **PROPTYPE_LONG** | Signed long data. |
| **PROPTYPE_DATE** | Date/time. |
| **PROPTYPE_BINARY** | The extension value is set as is and is assumed to be ASN.1 encoded if necessary. |
| **PROPTYPE_STRING** | The extension value will be ASN.1 encoded as an IA5 string before it is placed in the new certificate.<br><br>**Note** You should use **PROPTYPE_STRING** for an extension value that consists of a single URL only if you want the URL to be automatically encoded as an IA5 string. Otherwise, encode the URL as an IA5 string yourself and pass the encoded value as **PROPTYPE_BINARY**. |

### `ExtFlags` [in]

Specifies the flags for the extension being set. Use a value of zero if no flag is to be set, or use one of the following flag values. You can join these flags together by using the **OR** operator, and you can also join them by using the **OR** operator with policy private extension flags (the high 8 bits of the EXTENSION_POLICY_MASK field).

**Note** When *ExtFlags* is set to EXTENSION_DISABLE_FLAG, the extension will be disabled in the server log and will not be added to the certificate.

| Value | Meaning |
| --- | --- |
| **EXTENSION_CRITICAL_FLAG** | This is a critical extension. |
| **EXTENSION_DISABLE_FLAG** | Extension will not be used. |

### `pvarValue` [in]

Specifies the value associated with the extension. Note the value's **VARIANT** type must agree with the *Type* parameter, as shown in the following table.

| Value | Meaning |
| --- | --- |
| **PROPTYPE_LONG** | VT_I4 |
| **PROPTYPE_DATE** | VT_DATE |
| **PROPTYPE_BINARY** | VT_BSTR |
| **PROPTYPE_STRING** | VT_BSTR |

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Use extensions to include additional information with the certificate, such as supplemental subject or usage information. For more information, see [Extension Handlers](https://learn.microsoft.com/windows/desktop/SecCrypto/extension-handlers).

Call the **SetCertificateExtension** method from your implementation of the [ICertPolicy2::VerifyRequest](https://learn.microsoft.com/windows/desktop/api/certpol/nf-certpol-icertpolicy-verifyrequest) method. You must call
the [ICertServerPolicy::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext) method before calling the **SetCertificateExtension** method.

## See also

[ICertServerPolicy](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverpolicy)

[ICertServerPolicy::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext)