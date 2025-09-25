# ICertServerPolicy::GetRequestProperty

## Description

The **GetRequestProperty** method retrieves a specific property from a request.

## Parameters

### `strPropertyName` [in]

Specifies the name of the property to retrieve. This parameter can be set to a name property or a request property.

Name properties include a stock set of certificate properties that are always valid and can be retrieved by calling this method. For information about these properties, see
[Name Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/name-properties).

Request properties are unique to requests and include the following possible values.

| Value | Meaning |
| --- | --- |
| **RequestID**<br><br>Signed long | Internal requestID. |
| **RawRequest**<br><br>Binary | Raw request bytes. |
| **RequestAttributes**<br><br>String | Attribute string (may be truncated). |
| **RequestType**<br><br>Signed long | Indicates PKCS #10 or KeyGen request. For more information about this property, see Remarks. |
| **SubmittedWhen**<br><br>Date/time | When arrived. |
| **RequesterName**<br><br>String | The name of the requester in the form "*DomainName*\*UserID*". |

**Note** There are additional request properties that cannot be accessed by **GetRequestProperty** because they are not set until after the policy module finishes processing the request.In addition, other properties may be set by a specific request type, request extensions, or by named attributes set in the header of a request.

### `PropertyType` [in]

Specifies the property type. The *PropertyType* parameter can be one of the following types.

| Value | Meaning |
| --- | --- |
| **PROPTYPE_LONG** | Signed long data. |
| **PROPTYPE_DATE** | Date/time. |
| **PROPTYPE_BINARY** | Binary data. |
| **PROPTYPE_STRING** | [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string data. |

### `pvarPropertyValue` [out]

A pointer to the **VARIANT** that contains the request property type.

## Return value

### C++

If the method succeeds, the method returns S_OK, and the *pvarPropertyValue* parameter contains the request property.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the request property.

## Remarks

The
[SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext) method must be called prior to calling this method. The call to **SetContext** specifies which request is used as the current context.

Requests hold all the associated states for the request and the eventual granted certificate that is not a part of the certificate. Thus, data such as revocation times and disposition data are kept in the request data object.

The **RequestType** property can be set to one of the following values.

| Value | Meaning |
| --- | --- |
| CR_IN_PKCS | The request is a PKCS #7 renewal or registration request. |
| CR_IN-PKCS10 | The request is a PKCS #10 request. |
| CR_IN_KEYGEN | The request is a Keygen request (Netscape format). |

#### Examples

```cpp
BSTR      bstrPropName = NULL;
VARIANT   varProp;

VariantInit( &varProp );

bstrPropName = SysAllocString(L"RequestID");

// Retrieve the request property.
// pCertServerPolicy has been used to call SetContext previously.
hr = pCertServerPolicy->GetRequestProperty( bstrPropName,
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

[ICertServerPolicy](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverpolicy)

[ICertServerPolicy::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext)

[Name Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/name-properties)