# ICrmCompensator::SetLogControl

## Description

Delivers an [ICrmLogControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmlogcontrol) interface to the CRM Compensator so that it can write further log records during transaction completion. This method is the first method called on the CRM Compensator after it has been created.

## Parameters

### `pLogControl` [in]

A pointer to the [ICrmLogControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmlogcontrol) interface of the CRM clerk.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

CRM Compensator errors cause failfast of the server process, unless this has been specifically overridden (through a registry flag) for this particular CRM Compensator CLSID. See [COM+ CRM Registry Settings](https://learn.microsoft.com/windows/desktop/cossdk/com--crm-registry-settings) for more information.

## See also

[ICrmCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmcompensator)