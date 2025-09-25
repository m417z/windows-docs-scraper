# IEnroll4::enumPendingRequestWStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **enumPendingRequestWStr** method enumerates pending [certificate requests](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) and retrieves a specified property from each. This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

## Parameters

### `lIndex` [in]

Specifies the ordinal position of the pending request whose property will be retrieved. Specify zero for the first request.

### `lDesiredProperty` [in]

Identifier for the property being retrieved. Specify one of the following values.

| Value | Meaning |
| --- | --- |
| **XEPR_CADNS** | DNS name for the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA). |
| **XEPR_CAFRIENDLYNAME** | Display name of the CA. |
| **XEPR_CANAME** | Name of the CA. |
| **XEPR_HASH** | Hash value of the request. |
| **XEPR_REQUESTID** | Certificate request ID. |

### `ppProperty` [out]

A pointer to a **VOID** that receives the value of the retrieved property.

## Return value

 If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

If the following values are specified for *lDesiredProperty*, this method returns E_NOTIMPL:

* XEPR_DATE
* XEPR_V1TEMPLATENAME
* XEPR_V2TEMPLATEOID
* XEPR_VERSION

If you specify any other value for *lDesiredProperty*, this method returns E_INVALIDARG.

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)