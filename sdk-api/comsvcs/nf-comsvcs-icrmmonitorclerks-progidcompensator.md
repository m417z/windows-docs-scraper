# ICrmMonitorClerks::ProgIdCompensator

## Description

Retrieves the ProgId of the CRM Compensator for the specified index.

## Parameters

### `Index` [in]

The index of the required CRM clerk as a numeric **Variant**, or the instance CLSID as a **Variant** string.

### `pItem` [out]

The ProgId of the CRM Compensator.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | A **NULL** pointer was provided as an argument. |
| **E_INVALIDARG** | One of the arguments is incorrect. |

## See also

[ICrmMonitorClerks](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmmonitorclerks)