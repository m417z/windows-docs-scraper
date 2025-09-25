# ICertServerPolicy::SetCertificateProperty

## Description

Use the **SetCertificateProperty** method to set a property associated with a certificate.

## Parameters

### `strPropertyName` [in]

Specifies the property to set. You can set any of the
[Name Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/name-properties) associated with the certificate.

 In addition, you can set the following certificate properties.

| Value | Meaning |
| --- | --- |
| **NotBefore**<br><br>Date/time | The certificate is not valid before the given date. |
| **NotAfter**<br><br>Date/time | The certificate is not valid after the given date. |
| **GeneralFlags** | Set this property to 0x00000400 to prevent the request from being persisted in the CA database.<br><br>**Caution** Do not overwrite any mask values returned by [GetCertificateProperty](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-getcertificateproperty) when setting this property. Set the value by performing a bitwise **OR** with the existing values.<br><br>**Windows Storage Server 2003:** This field is not supported. |
| **CrossForest**<br><br>PROPTYPE_LONG | A Boolean value that specifies whether the CA should operate cross forest enrollment mode.<br><br>**Windows Server 2008 and Windows Server 2003:** Cross forest enrollment is not supported. Cross forest enrollment is supported beginning with Windows Server 2008 R2. |
| **RequesterSAMName**<br><br>PROPTYPE_STRING | Tells the CA to set the requester account name ("RequesterName") and distinguished name. |
| **RequesterUPN**<br><br>PROPTYPE_STRING | Tells the CA to convert the [user principal name](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN) of the requester to the requester name ("RequesterName") and to set the requester name and the requester distinguished name. |
| **RequesterDN**<br><br>PROPTYPE_STRING | Tells the CA to convert the FQDN 1779 name of the requester to the requester name and to set the requester name ("RequesterName") and the requester distinguished name. |

### `PropertyType` [in]

Specifies the type of the property being set. The *Type* parameter must agree with the data type of *pvarValue* that is set in the **vt** field of the **VARIANT** structure. The *Type* parameter can be set to one of the following types.

| Value | Meaning |
| --- | --- |
| **PROPTYPE_LONG** | Signed long data. |
| **PROPTYPE_DATE** | Date/time data. |
| **PROPTYPE_BINARY** | Binary data. |
| **PROPTYPE_STRING** | [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string data |

### `pvarPropertyValue` [in]

Specifies the value to set the property to.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

You must call
[ICertServerPolicy::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext) prior to using this method.

The NotBefore and NotAfter certificate properties constrain the lifetime during which a certificate is valid. The data type for these properties is a floating-point **VARIANT** date derived from COleDateTime in Automation.

The following restrictions apply when setting the NotBefore and NotAfter certificate properties with **SetCertificateProperty**:

* The NotBefore date cannot be set to a date earlier than the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) certificate's NotBefore date.
* The NotAfter date cannot be set to a date later than the CA certificate's NotAfter date.
* The NotBefore date cannot be set to a date earlier than it already is set, even if the new date is later than the CA certificate's NotBefore date.
* The NotAfter date cannot be set to a date later than it already is set, even if the new date is before the CA certificate's NotAfter date.

#### Examples

The following example calls the **SetCertificateProperty** method to set the NotBefore certificate property. The example assumes pServer is valid and the [ICertServerPolicy::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext) method has been called.

```cpp
HRESULT hr;
ICertServerPolicy *pServer;
SYSTEMTIME st;
BSTR bstrPropName;
VARIANT vPropValue;

bstrPropName = SysAllocString(L"NotBefore");
if (NULL == bstrPropName)
{
    printf("Unable to allocate memory.\n");
    return E_OUTOFMEMORY;
}

// Set the 'NotBefore' property to Noon on Jan. 1, 2000.
memset( &st, 0, sizeof(SYSTEMTIME));
st.wYear = 2000;
st.wMonth = 1;     // Jan.
st.wDay = 1;       // 1st day of month.
st.wHour = 12;     // Noon.

// Place the date into VARIANT required format.
VariantInit( &vPropValue );
vPropValue.vt = VT_DATE;
if ( !SystemTimeToVariantTime( &st, &vPropValue.date))
{
    printf("Unable to convert time.\n");
    SysFreeString(bstrPropName);
    return E_FAIL
}

// Set the NotBefore property in the certificate:
hr = pServer->SetCertificateProperty(bstrPropName,
                                     PROPTYPE_DATE,
                                     &vPropValue);
SysFreeString(bstrPropName);
VariantClear(&vPropValue);
if (FAILED(hr))
{
    printf("SetCertificateProperty failed [%x]\n", hr);
    return hr;
}
```

## See also

[ICertServerExit::GetCertificateProperty](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-getcertificateproperty)

[ICertServerPolicy](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverpolicy)

[ICertServerPolicy::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext)

[Name Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/name-properties)