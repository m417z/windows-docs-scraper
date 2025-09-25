# ICrmLogControl::RegisterCompensator

## Description

The CRM Worker uses this method to register the CRM Compensator with the CRM infrastructure. It must be the first method called by the CRM Worker, and it can be called successfully only once. If the CRM Worker receives a "recovery in progress" error code on calling this method, it should call this method again until it receives success.

## Parameters

### `lpcwstrProgIdCompensator` [in]

The ProgId of the CRM Compensator. The CLSID of the CRM Compensator in string form is also accepted.

### `lpcwstrDescription` [in]

The description string to be used by the monitoring interfaces.

### `lCrmRegFlags` [in]

Flags from the [CRMREGFLAGS](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-crmregflags) enumeration that control which phases of transaction completion should be received by the CRM Compensator and whether recovery should fail if in-doubt transactions remain after recovery has been attempted.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | A **NULL** pointer was provided as an argument. |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **XACT_E_NOTRANSACTION** | The component creating the CRM clerk does not have a transaction. |
| **XACT_E_RECOVERYINPROGRESS** | Recovery of the CRM log file is still in progress. |
| **XACT_E_RECOVERY_FAILED** | Recovery of the CRM log file failed because in-doubt transactions remain. |
| **XACT_E_WRONGSTATE** | This method was called in the wrong state; either before [RegisterCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmlogcontrol-registercompensator) or when the transaction is completing (CRM Worker). |
| **E_OUTOFMEMORY** | An out of memory error has occurred. |
| **E_NOINTERFACE** | The CRM Compensator does not support at least one of the required interfaces ([ICrmCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmcompensator) or [ICrmCompensatorVariants](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmcompensatorvariants)). |

## Remarks

The *lCrmRegFlags* parameter enables the implementer to decide which phases of transaction completion the CRM Compensator wants to receive. Some CRM Compensators might perform no work in the prepare phase and therefore have no need to receive prepare notifications; it can improve performance to specify that no prepare phase is required in this case.

It is recommended that CRM Workers and CRM Compensators be developed as "Both" threaded components (Threading Model = Any Apartment). However, in some cases this might not be possible due to language constraints (for example, when developing CRMs with Visual Basic). Apartment-threaded CRM Compensators (Threading Model = Single Thread Apartment) will deadlock in the prepare phase unless their synchronization property is set to "not supported". Another alternative for Apartment-threaded CRM Compensators is to skip the prepare phase if it is not necessary.

In scenarios with multiple Distributed Transaction Coordinators (DTCs), it is possible that a DTC transaction can go into the in-doubt state. Normally, this is because an interruption occurred during a transaction and the originator of the transaction cannot be contacted to find out the outcome of the transaction. In this case, the CRM infrastructure cannot determine the outcome of the transaction. A CRM implementer can decide whether new transactions should be allowed in this case.

The "fail if in-doubts remain" flag is used as follows: By specifying the "fail if in-doubts remain" flag on **RegisterCompensator**, if in-doubt transactions remain after recovery, the call to **RegisterCompensator** fails with a "recovery failed" error code. If the "fail if in-doubts remain" flag is not specified, the recovery succeeds, new transactions are allowed, and the in-doubt transactions remain in the CRM log file. The CRM infrastructure attempts to resolve these in-doubt transactions again on the next recovery (when the application server process is restarted).

## See also

[ICrmLogControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmlogcontrol)