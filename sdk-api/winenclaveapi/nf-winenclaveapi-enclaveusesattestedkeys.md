## Description

This method returns whether the Enclave uses safe attested keys.

## Return value

A **BOOLEAN** value set to `true` if the Enclave uses safe attested keys.

## Remarks

Since remote attestation of the Master key is still not supported the function verifies that:

- No Boot, Kernel or Hypervisor Debugger is ever enabled (which can interfere with the secure keys).
- The Master and encryption keys are safely provisioned by the Trusted Platform Module (TPM).

## See also