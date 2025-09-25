# Tbsi_Revoke_Attestation function

## Description

Invalidates the PCRs if the ELAM driver detects a policy-violation (a rootkit, for example).

## Return value

| Return code/value | Description |
| --- | --- |
| **TBS_SUCCESS**<br><br>0 (0x0) | The function succeeded. |
| **TBS_E_INTERNAL_ERROR**<br><br>2150121473 (0x80284001) | An internal software error occurred. <br><br>**Note** If TBS_E_INTERNAL_ERROR is returned, the system event log may contain event ID 16385 from the TBS event source with error code 0x80070032. This may indicate that the hardware platform does not provide a TCG event log to the operating system. Sometimes this can be resolved by installing a BIOS upgrade from the platform manufacturer. |

## Remarks

This function is callable from kernel mode.

You must run this function with administrative rights. This function extends PCR[12] by an unspecified value and increment the event counter in the TPM. Both actions are necessary, so the trust is broken in all quotes that are created from here on forward. Since the PCRs are reset on hibernation and the extend to PCR[12] then will disappear, a gap in the event counter will indicate a broken chain of logs.

As a result, the WBCL files will not reflect the current state of the TPM for the remainder of the time that the TPM is powered up and remote systems will not be able to form trust in the security state of the system. Note that anti-malware systems will probably perform additional remediation or alerts, but the invalidation step is crucial if attestation is supported.

When the computer goes to hibernation and subsequently resumes, the previous PCR extent will be lost, and the broken trust will not be reflected in the PCR measurements anymore. To address this, the **Tbsi_Revoke_Attestation** function also increments the monotonic Event Counter located in the TPM. Further TPM attestation validations will notice a gap in the archived WBCL logs’ boot counter values. Upon discovery of such a gap, attestation validation code should fail the validation, just as it would if other required events were not present in the log. Note that the counter in the TPM cannot be rolled back you can't construct the missing WBCL after the fact.