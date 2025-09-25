# ICrmMonitorClerks::Item

## Description

Retrieves the instance CLSID of the CRM clerk for the specified index.

## Parameters

### `Index` [in]

The index of the required CRM clerk as a numeric **Variant**.

### `pItem` [out]

A pointer to **Variant** string returning the instance CLSID corresponding to this numeric index.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | A **NULL** pointer was provided as an argument. |
| **E_INVALIDARG** | One of the arguments is incorrect. |

## See also

[ICrmMonitorClerks](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmmonitorclerks)