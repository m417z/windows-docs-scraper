# ResUtilGetDwordValue function

## Description

Returns a numeric value from the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database).

## Parameters

### `hkeyClusterKey` [in]

Key identifying the location of the numeric value in the cluster database.

### `pszValueName` [in]

Pointer to a null-terminated Unicode string containing the name of the value to retrieve.

### `pdwOutValue` [out]

Pointer to the retrieved value.

### `dwDefaultValue` [in]

Value to return if the value pointed to by *pszValueName* is not found.

## Return value

If the operations succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The value pointed to by *ValueName* is not a numeric value. |

## Remarks

The **ResUtilGetDwordValue** utility function calls the [Cluster API](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-api) function [ClusterRegQueryValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregqueryvalue) to retrieve the value.

## See also

[ClusterRegQueryValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregqueryvalue)

[ResUtilGetBinaryValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetbinaryvalue)

[ResUtilGetExpandSzValue](https://learn.microsoft.com/windows/win32/api/resapi/nf-resapi-resutilgetexpandszvalue)

[ResUtilGetMultiSzValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nf-resapi-resutilgetmultiszvalue)

[ResUtilGetSzValue](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetszvalue)