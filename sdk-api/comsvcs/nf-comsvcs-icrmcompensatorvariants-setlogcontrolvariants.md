# ICrmCompensatorVariants::SetLogControlVariants

## Description

Delivers an [ICrmLogControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmlogcontrol) interface to the CRM Compensator. This method is the first method called on the CRM Compensator after it has been created.

## Parameters

### `pLogControl` [in]

A pointer to the [ICrmLogControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmlogcontrol) interface of the CRM clerk.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To write additional log records, use the [ICrmLogControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmlogcontrol) interface.

## See also

[ICrmCompensatorVariants](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmcompensatorvariants)