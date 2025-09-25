# ICrmCompensator::BeginCommit

## Description

Notifies the CRM Compensator of the commit phase of the transaction completion and that records are about to be delivered.

## Parameters

### `fRecovery` [in]

Indicates whether this method is being called during recovery (TRUE) or normal processing (FALSE).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The commit or abort phases are received by the compensator without a prepare phase during recovery. Also, the abort phase can be received during normal processing without a prepare phase if the client decides to initiate abort.

The CRM Compensator should not depend on any state to be maintained between the prepare and commit/abort phases; the CRM infrastructure is free to release the CRM Compensator between these two phases if it needs to do so. However, state is maintained between the Begin-Record-End calls, and the CRM Compensator always gets the [ICrmLogControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmlogcontrol) interface before delivery of any transaction outcome methods.

## See also

[ICrmCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmcompensator)