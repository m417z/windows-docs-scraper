# INetDiagHelper::GetCacheTime

## Description

The **GetCacheTime** method specifies the time when cached results of a diagnosis and repair operation have expired.

## Parameters

### `pCacheTime` [out]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete this operation. |
| **E_INVALIDARG** | One or more parameters has not been provided correctly. |
| **E_NOTIMPL** | This optional method is not implemented. |
| **E_ACCESSDENIED** | The caller does not have sufficient privileges to perform the diagnosis or repair operation. |
| **E_ABORT** | The diagnosis or repair operation has been canceled. |

Helper Class Extensions may return HRESULTS that are specific to the failures encountered in the function.

## Remarks

This method is not required when building a Helper Class Extension.

The default behavior is to return the current time so that the results will not be cached. Setting a cache time can increase diagnosis efficiency since NDF will not call on the extension to re-diagnose an issue unless the cache time has expired.

The **FILETIME** structure is a 64-bit value representing the number of 100-nanosecond intervals since January 1, 1601 (UTC).

## See also

[INetDiagHelper](https://learn.microsoft.com/windows/desktop/api/ndhelper/nn-ndhelper-inetdiaghelper)