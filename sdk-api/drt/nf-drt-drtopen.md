# DrtOpen function

## Description

The **DrtOpen** function creates a local Distributed Routing Table instance against criteria specified by the [DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings) structure.

## Parameters

### `pSettings` [in]

Pointer to the [DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings) structure which specifies the settings used for the creation of the DRT instance.

### `hEvent` [in]

Handle to the event signaled when an event occurs.

### `pvContext` [in, optional]

User defined context data which is passed to the application via events.

### `phDrt` [out]

The new handle associated with the DRT. This is used in all future operations on the DRT instance.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | *phDrt* is **NULL**. |
| **DRT_E_INVALID_SETTINGS** | *pSettings* is **NULL** or the **dwSize** member value of [DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings) is not equal to the size of the **DRT_SETTINGS** object. |
| **DRT_E_INVALID_KEY_SIZE** | *cbKey* is not equal to 256 bits. |
| **DRT_E_INVALID_MAX_ADDRESSES** | The **ulMaxRoutingAddresses** member of [DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings) specifies less than 1 or more than 20 as the maximum number of addresses. |
| **DRT_E_INVALID_TRANSPORT_PROVIDER** | The **hTransport** member in [DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings) is **NULL** or some fields of the Transport are **NULL** |
| **DRT_E_INVALID_SECURITY_MODE** | The **eSecurityMode** member of [DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings) specifies an invalid security mode. |
| **DRT_E_INVALID_SECURITY_PROVIDER** | The **pSecurityProvider** member of [DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings) is **NULL**. |
| **DRT_E_INVALID_BOOTSTRAP_PROVIDER** | The **pBootstrapProvider** member of [DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings) is **NULL** or some fields of the bootstrap provider are **NULL**. |
| **DRT_E_INVALID_INSTANCE_PREFIX** | The size of the **pwzDrtInstancePrefix** specified in [DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings) is larger than the maximum prefix length (128). |
| **E_OUTOFMEMORY** | The system cannot allocate memory for this operation. |
| **DRT_E_BOOTSTRAPPROVIDER_IN_USE** | The bootstrap provider is already attached. |
| **DRT_E_SECURITYPROVIDER_IN_USE** | The security provider is already attached. |
| **DRT_TRANSPORTPROVIDER_IN_USE** | The transport provider is already attached. |
| **DRT_E_INVALID_CERT_CHAIN** | The certification chain is invalid. |
| **DRT_E_CAPABILITY_MISMATCH** | Local certificate cannot be **NULL** in DRT_SECURE_MEMBERSHIP and DRT_SECURE_CONFIDENTIALPAYLOAD security. |
| **DRT_E_TRANSPORT_SHUTTING_DOWN** | Transport is shutting down. |
| **DRT_E_TRANSPORT_ALREADY_BOUND** | Transport is already bound. |
| **DRT_S_RETRY** | Bootstrap provider failed to locate other nodes, but may be successful in a second attempt. |
| **DRT_E_TRANSPORT_INVALID_ARGUMENT** | Transport provider parameter is **NULL** or invalid. |
| **DRT_E_TRANSPORTPROVIDER_NOT_ATTACHED** | Transport is not attached. |
| **E_FAIL** | An unexpected fatal error occurred. |

## Remarks

 After **DrtOpen** is called, the DRT will begin the bootstrapping procedure and move to the **DRT_ACTIVE** or **DRT_ALONE** state, depending on the success of the bootstrap.

## See also

[DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings)

[DrtClose](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtclose)