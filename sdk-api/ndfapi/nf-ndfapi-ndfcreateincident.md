# NdfCreateIncident function

## Description

The **NdfCreateIncident** function is used internally by application developers to test the NDF functionality incorporated into their application.

## Parameters

### `helperClassName` [in]

Type: **LPCWSTR**

The name of the helper class to be used in the diagnoses of the incident.

### `celt`

Type: **ULONG**

A count of elements in the attributes array.

### `attributes` [in]

Type: **[HELPER_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-helper_attribute)***

The applicable [HELPER_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-helper_attribute) structure.

### `handle` [out]

Type: **NDFHANDLE***

A handle to the Network Diagnostics Framework incident.

## Return value

Type: **HRESULT**

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete this operation. |
| **NDF_E_BAD_PARAM** | One or more parameters are invalid. |
| **NDF_E_NOHELPERCLASS** | *helperClassName* is **NULL**. |

## See also

[NdfCloseIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcloseincident)

[NdfCreateWinSockIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcreatewinsockincident)

[NdfExecuteDiagnosis](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfexecutediagnosis)