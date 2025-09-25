# LsaQueryCAPs function

## Description

Returns the Central Access Policies (CAPs) for the specified IDs.

## Parameters

### `CAPIDs`

A pointer to a variable that contains an array of pointers to CAPIDs that identify the CAPs being queried.

### `CAPIDCount` [in]

The number of IDs in the *CAPIDs* parameter.

### `CAPs` [out]

Receives a pointer to an array of pointers to [CENTRAL_ACCESS_POLICY](https://learn.microsoft.com/windows/desktop/api/ntlsa/ns-ntlsa-central_access_policy) structures representing the queried CAPs.

### `CAPCount` [out]

The number of [CENTRAL_ACCESS_POLICY](https://learn.microsoft.com/windows/desktop/api/ntlsa/ns-ntlsa-central_access_policy) structure pointers returned in the *CAPs* parameter.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code, which can be one of the [LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).