# ICrmMonitorClerks::Description

## Description

Retrieves the description of the CRM Compensator for the specified index.

## Parameters

### `Index` [in]

The index of the required CRM clerk as a numeric **Variant**, or the instance CLSID as a **Variant** string.

### `pItem` [out]

The description string originally provided by [ICrmLogControl::RegisterCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmlogcontrol-registercompensator).

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | A **NULL** pointer was provided as an argument. |
| **E_INVALIDARG** | One of the arguments is incorrect. |

## See also

[ICrmMonitorClerks](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmmonitorclerks)