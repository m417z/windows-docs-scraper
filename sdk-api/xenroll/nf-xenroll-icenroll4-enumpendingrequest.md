# ICEnroll4::enumPendingRequest

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **enumPendingRequest** method enumerates pending [certificate requests](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) and retrieves a specified property from each.
This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

## Parameters

### `lIndex` [in]

Specifies the ordinal position of the pending request whose property will be retrieved. Specify zero for the first request.

### `lDesiredProperty` [in]

The identifier for the property being retrieved. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **XEPR_CADNS** | The DNS name for the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA). |
| **XEPR_CAFRIENDLYNAME** | The display name of the CA. |
| **XEPR_CANAME** | The name of the CA. |
| **XEPR_HASH** | The hash value of the request. |
| **XEPR_REQUESTID** | The certificate request ID. |

### `pvarProperty` [out]

A pointer to a **VARIANT** that receives the value of the retrieved property.

When you have finished using the **VARIANT**, free it by calling the [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) function.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

If the following values are specified for *lDesiredProperty*, this method returns E_NOTIMPL:

* XEPR_DATE
* XEPR_V1TEMPLATENAME
* XEPR_V2TEMPLATEOID
* XEPR_VERSION

If you specify any other value for *lDesiredProperty* this method returns E_INVALIDARG.

### VB

Returns a **Variant** that contains a property from a pending request.

## Remarks

This method is disabled when the Certificate Enrollment Control is executed as a scripted control.