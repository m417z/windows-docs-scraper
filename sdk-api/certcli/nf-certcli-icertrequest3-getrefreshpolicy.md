# ICertRequest3::GetRefreshPolicy

## Description

The **GetRefreshPolicy** method returns a value that indicates whether a client's cached certificate enrollment policy is out of date and needs to be refreshed.

## Parameters

### `pValue` [out, retval]

A pointer to a **VARIANT_BOOL** variable to receive the refresh indicator.

## Return value

### C++

If the method succeeds, the method returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **BOOL** that indicates whether the client's policy service is out of date.

## Remarks

The **GetRefreshPolicy** method returns **TRUE** only when the enrollment server returns a fault. Before calling the **GetRefreshPolicy** method you must contact the enrollment server. If a fault is returned, then call the **GetRefreshPolicy** method from same instance of [ICertRequest3](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest3) to determine whether the cached policy is out of date and needs to be refreshed.