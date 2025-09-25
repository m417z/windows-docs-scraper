# NdfCreateDNSIncident function

## Description

The **NdfCreateDNSIncident** function diagnoses name resolution issues in resolving a specific host name.

## Parameters

### `hostname` [in]

Type: **LPCWSTR**

The host name with which there is a name resolution issue.

### `queryType`

Type: **WORD**

The numeric representation of the type of record that was queried when the issue occurred. For more information and a complete listing of record set types and their numeric representations, see the windns.h header file.

This parameter should be set to **DNS_TYPE_ZERO** for generic DNS resolution diagnosis.

### `handle` [out]

Type: **NDFHANDLE***

Handle to the Network Diagnostics Framework incident.

## Return value

Type: **HRESULT**

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_ABORT** | The underlying diagnosis or repair operation has been canceled. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete this operation. |
| **NDF_E_BAD_PARAM** | One or more parameters are invalid. |