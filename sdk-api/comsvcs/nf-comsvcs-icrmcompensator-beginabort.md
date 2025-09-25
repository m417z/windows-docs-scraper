# ICrmCompensator::BeginAbort

## Description

Notifies the CRM Compensator of the abort phase of the transaction completion and that records are about to be delivered.

## Parameters

### `fRecovery` [in]

Indicates whether this method is being called during recovery.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The abort phase can be received during normal processing without a prepare phase should the client decide to initiate abort.

The CRM Compensator should not depend on any state to be maintained between the prepare phase and this phase; the CRM infrastructure is free to release the CRM Compensator between these two phases if it needs to do so. However, state is maintained between the Begin-Record-End calls, and the CRM Compensator always gets the [ICrmLogControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmlogcontrol) interface before delivery of any transaction outcome methods.

## See also

[ICrmCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmcompensator)