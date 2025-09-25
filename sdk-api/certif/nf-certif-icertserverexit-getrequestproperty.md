# ICertServerExit::GetRequestProperty

## Description

The **GetRequestProperty** method returns a named property from a request.

Note that the request is used to hold all associated states for the request and the eventual granted certificate that is not a part of the certificate. Thus, data such as revocation times and disposition data are kept in the request data object.

## Parameters

### `strPropertyName` [in]

Specifies the property to retrieve. There is a stock set of certificate properties, referred to as the name properties, that are always valid and can be retrieved by calling this method. For information about these properties, see
[Name Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/name-properties).

Other properties valid for [certificate requests](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) include the request properties.

**Note** The request's **DistinguishedName** and **RawName** properties are accessible by **GetRequestProperty** only if the certificate is requested by using a PKCS #10 certificate request or another supported request format that contains encoded subject name information. Note that KeyGen requests do not contain encoded subject name information.

The following properties are unique to requests and can be accessed by using the **GetRequestProperty** method.

| Request property | Meaning |
| --- | --- |
| **Disposition**<br><br>Signed long | Current request disposition |
| **DispositionMessage**<br><br>String | Informational disposition message |
| **RawCACertificate**<br><br>Binary | Certificate for the issuing [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) |
| **RawRequest**<br><br>Binary | Raw request bytes |
| **RequestAttributes**<br><br>String | Attribute string (can be truncated) |
| **RequesterName**<br><br>String | The name of the requester in the form "*DomainName*\*UserID*" |
| **RequestID**<br><br>Signed long | Internal requestID |
| **RequestType**<br><br>Signed long | Indicates PKCS #10 or KeyGen request |
| **ResolvedWhen**<br><br>Date/time | When resolved |
| **StatusCode**<br><br>Signed long | Windows error for last operation |
| **SubmittedWhen**<br><br>Date/time | When arrived |

The **RequestType** property will be one of the following values.

| Value | Meaning |
| --- | --- |
| **CR_IN_PKCS7** | PKCS #7 renewal or registration request |
| **CR_IN_PKCS10** | PKCS #10 request |
| **CR_IN_KEYGEN** | Keygen request (Netscape format) |

In addition, other properties may be set by a specific request type, request extensions, or by named attributes set in the header of a request.

### `PropertyType` [in]

Specifies the property type. The type can be one of the following types.

| Value | Meaning |
| --- | --- |
| **PROPTYPE_LONG** | Signed long data |
| **PROPTYPE_DATE** | Date/time |
| **PROPTYPE_BINARY** | Binary data |
| **PROPTYPE_STRING** | Unicode string data |

### `pvarPropertyValue` [out]

A pointer to the **VARIANT** that will contain the request property type.

## Return value

### C++

If the method succeeds, the method returns S_OK, and **pvarPropertyValue* is set to the **VARIANT** that contains the request property value.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the request property value.

## Remarks

You must call
[ICertServerExit::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-setcontext) prior to using this method.

#### Examples

```cpp
BSTR      bstrPropName = NULL;
VARIANT   varProp;

VariantInit( &varProp );

bstrPropName = SysAllocString(L"RequestID");

// Retrieve the request property.
// pCertServerExit has been used to call SetContext previously.
hr = pCertServerExit->GetRequestProperty( bstrPropName,
                                          PROPTYPE_LONG,
                                          &varProp );
if (FAILED(hr))
{
    printf("Failed GetRequestProperty [%x]\n", hr);
    goto error;
}
else
{
    // Successfully retrieved property; use varProp as needed.
    // ...
}

// Done processing.
VariantClear( &varProp );
if ( NULL != bstrPropName )
    SysFreeString( bstrPropName );
```

## See also

[ICertServerExit](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverexit)

[ICertServerExit::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-setcontext)

[Name Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/name-properties)