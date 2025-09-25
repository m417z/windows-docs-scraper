## Description

Queries whether user-mode Hardware-enforced Stack Protection is available for the specified environment.

## Parameters

### `UserCetEnvironment`

The environment to query. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **USER_CET_ENVIRONMENT_WIN32_PROCESS**<br><br>0x00000000UL | The Win32 environment. |
| **USER_CET_ENVIRONMENT_SGX2_ENCLAVE**<br><br>0x00000002UL | The Intel Software Guard Extensions 2 (SGX2) enclave environment. |
| **USER_CET_ENVIRONMENT_VBS_ENCLAVE**<br><br>0x00000010UL | The virtualization-based security (VBS) enclave environment. |
| **USER_CET_ENVIRONMENT_VBS_BASIC_ENCLAVE**<br><br>0x00000011UL | The virtualization-based security (VBS) basic enclave environment. |

## Return value

TRUE if user-mode Hardware-enforced Stack Protection is available for the specified environment, FALSE otherwise.

## Remarks

## See also