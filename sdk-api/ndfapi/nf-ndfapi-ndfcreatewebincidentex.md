# NdfCreateWebIncidentEx function

## Description

The **NdfCreateWebIncidentEx** function diagnoses web connectivity problems concerning a specific URL. This function allows for more control over the underlying diagnosis than the [NdfCreateWebIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcreatewebincident) function.

## Parameters

### `url` [in]

Type: **LPCWSTR**

The URL with which there is a connectivity issue.

### `useWinHTTP` [in]

Type: **BOOL**

**TRUE** if diagnosis will be performed using the WinHTTP APIs; **FALSE** if the WinInet APIs will be used.

### `moduleName` [in]

Type: **LPWSTR**

The module name to use when checking against application-specific filtering rules (for example, "C:\Program Files\Internet Explorer\iexplorer.exe"). If **NULL**, the value is autodetected during the diagnosis.

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

## See also

[NdfCreateWebIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcreatewebincident)