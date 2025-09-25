# DrtCreateNullSecurityProvider function

## Description

The **DrtCreateNullSecurityProvider** function creates a null security provider. This security provider does not require nodes to authenticate keys.

## Parameters

### `ppSecurityProvider` [out]

Pointer to the [DRT_SETTINGS](https://learn.microsoft.com/windows/win32/api/drt/ns-drt-drt_settings) structure.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | The system cannot allocate memory for the provider. |
| **DRT_E_INVALID_ARG** | *ppDrtSecurityProvider* is **NULL**. |

## See also

[DRT_SECURITY_PROVIDER](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_security_provider)

[DrtDeleteNullSecurityProvider](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtdeletenullsecurityprovider)