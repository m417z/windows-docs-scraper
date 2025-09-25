## Description

The **IPSEC_SA_CONTEXT_CALLBACK0** function is used to add custom behavior to the IPsec security association (SA) context subscription process.

## Parameters

### `context` [in, out]

Type: **void***

Optional context pointer. It contains the value of the *context* parameter of the [IPsecSaContextSubscribe0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-ipsecsacontextsubscribe0) function.

### `change` [in]

Type: **const [IPSEC_SA_CONTEXT_CHANGE0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_sa_context_change0)\***

The IPsec SA context information.

## Remarks

Call [IPsecSaContextSubscribe0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-ipsecsacontextsubscribe0) to register this callback function.

## See also

[IPsecSaContextSubscribe0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-ipsecsacontextsubscribe0)