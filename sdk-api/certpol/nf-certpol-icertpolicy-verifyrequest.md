# ICertPolicy::VerifyRequest

## Description

The **VerifyRequest** method notifies the policy module that a new request has entered the system. The policy module can then interact with that request by passing *Context* as a parameter when retrieving or setting properties on the request or associated certificate.

The returned disposition value indicates whether the request has been accepted, denied, or has been sent to the administration queue for later evaluation.

## Parameters

### `strConfig` [in]

Represents the name of the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

### `Context` [in]

Identifies the request and associated certificate under construction. The certificate server passes the context to this method.

### `bNewRequest` [in]

If set to **TRUE**, specifies that the request is new. If set to **FALSE**, the request is being resubmitted to the policy module as a result of an
[ICertAdmin::ResubmitRequest](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin-resubmitrequest) call. A value of **FALSE** can be used to indicate that the administrator wants the request to be issued or that request properties set by the administrator should be examined.

Note that **TRUE** is defined (in a Microsoft header file) for C/C++ programmers as one, while Visual Basic defines the **True** keyword as negative one. As a result, Visual Basic developers must use one (instead of **True**) to set this parameter to **TRUE**. However, to set this parameter to **FALSE**, Visual Basic developers can use zero or **False**.

### `Flags` [in]

This parameter is reserved and must be set to zero.

### `pDisposition` [out, retval]

A pointer to the disposition value. The method sets one of the following dispositions.

| Value | Meaning |
| --- | --- |
| **VR_INSTANT_BAD** | Deny the request. |
| **VR_INSTANT_OK** | Accept the request. |
| **VR_PENDING** | Add the request to the queue to accept or deny the request at a later time. |

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value specifies the disposition, which must be one of the following values.

| Return code | Description |
| --- | --- |
| **VR_INSTANT_BAD** | Deny the request. |
| **VR_INSTANT_OK** | Accept the request. |
| **VR_PENDING** | Add the request to the queue to accept or deny the request at a later time. |

## Remarks

**VerifyRequest** is free to spawn off other processes or access an external database to do the request verification. If the verification requires out-of-band processing or human intervention, **VerifyRequest** can notify another process or leave any notice of the incoming request required. After the out-of-band processing is complete, a call to
[ResubmitRequest](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin-resubmitrequest) can be made, or the provided administration tool can be used to resubmit the request to the Policy Module. The policy module can examine the request again, access any necessary external data, and return a value to indicate the certificate should be issued or denied.

When you write custom policy modules, you must implement **VerifyRequest** functionality in your modules.

#### Examples

The following example shows a possible implementation of the **VerifyRequest** method.

```cpp
#include <windows.h>
#include <stdio.h>
#include <Certpol.h>

STDMETHODIMP CCertPolicy::VerifyRequest(
             BSTR const strConfig,
             LONG Context,
             LONG bNewRequest,
             LONG Flags,
             LONG __RPC_FAR *pDisposition)
{
    HRESULT            hr;
    long               nDisp = VR_INSTANT_BAD;
    ICertServerPolicy *pServer = NULL;
    BSTR               bstrPropName = NULL;
    VARIANT            varProp;

    // Verify that pointer is not NULL.
    if ( NULL == pDisposition )
    {
        hr = E_POINTER;  // E_POINTER is #defined in Winerror.h
        goto error;
    }

    // Set disposition to pending.
    *pDisposition = VR_PENDING;

    // Obtain a pointer to the CertServerPolicy interface.
    hr = CoCreateInstance( CLSID_CCertServerPolicy,
                           NULL,
                           CLSCTX_INPROC_SERVER,
                           IID_ICertServerPolicy,
                           (void **) &pServer);
    if (FAILED( hr ))
    {
        printf("Failed CoCreateInstance for pServer - %x\n", hr );
        goto error;
    }

    // Set the context to refer to this request.
    hr = pServer->SetContext(Context);
    if (FAILED( hr ))
    {
        printf("Failed SetContext(%u) - %x\n", Context, hr );
        goto error;
    }

    // This policy will perform a database check on the CN.
    // Set the property name to Subject.Commonname.
    bstrPropName = SysAllocString(L"Subject.Commonname");
    if ( NULL == bstrPropName )
    {
        hr = E_OUTOFMEMORY;  // #defined in Winerror.h
        printf("Failed SysAllocString (no memory)\n" );
        goto error;
    }

    // Retrieve the certificate property for the CN.
    // Actual implementations may want to examine other properties.
    VariantInit( &varProp );
    hr = pServer->GetCertificateProperty( bstrPropName,
                                          PROPTYPE_STRING,
                                          &varProp );
    if (FAILED(hr))
    {
        printf("Failed GetCertificateProperty - %x\n", hr);
        goto error;
    }

    // For this simple sample, merely check CN in a database.
    // (Implementation not shown, as it is application-specific).
    hr = MyDatabaseCheck( varProp.bstrVal );
    if ( S_OK == hr )
        *pDisposition = VR_INSTANT_OK;   // Accepted.
    else
        *pDisposition = VR_INSTANT_BAD;  // Denied.

error:

    // Free resources.
    if (NULL != pServer)
        pServer->Release();

    VariantClear( &varProp );

    if ( NULL != bstrPropName )
        SysFreeString( bstrPropName );

    return(hr);
}
```

## See also

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)

[ICertPolicy](https://learn.microsoft.com/windows/desktop/api/certpol/nn-certpol-icertpolicy)

[ICertPolicy2](https://learn.microsoft.com/windows/desktop/api/certpol/nn-certpol-icertpolicy2)