# Tbsi_Get_OwnerAuth function

## Description

Retrieves the owner authorization of the TPM if the information is available in the local registry.

## Parameters

### `hContext` [in]

TBS handle obtained from a previous call to the [Tbsi_Context_Create](https://learn.microsoft.com/windows/desktop/api/tbs/nf-tbs-tbsi_context_create) function.

### `ownerauthType` [in]

Unsigned 32-bit integer indicating the type of owner authentication.

| Value | Meaning |
| --- | --- |
| **TBS_OWNERAUTH_TYPE_FULL**<br><br>1 | The owner authorization is full. |
| **TBS_OWNERAUTH_TYPE_ADMIN**<br><br>2 | **Note** TPM 1.2 only<br><br>The owner authorization is an administrator. |
| **TBS_OWNERAUTH_TYPE_USER**<br><br>3 | **Note** TPM 1.2 only<br><br>The owner authorization is a user. |
| **TBS_OWNERAUTH_TYPE_ENDORSEMENT**<br><br>4 | **Note** TPM 1.2 only<br><br>The owner authorization is an endorsement authorization. |
| **TBS_OWNERAUTH_TYPE_ENDORSEMENT_20**<br><br>12 | **Note** TPM 2.0 and later<br><br>The owner authorization is an endorsement authorization. |
| **TBS_OWNERAUTH_TYPE_STORAGE_20**<br><br>13 | **Note** TPM 2.0 and later<br><br>The owner authorization is an administrator. |

### `pOutputBuf` [out, optional]

A pointer to a buffer to receive the TPM owner authorization information.

### `pOutputBufLen` [in, out]

An integer that, on input, specifies the size, in bytes, of the output buffer. On successful return, this value is set to the actual size of the TPM ownerAuth, in bytes.

## Return value

If the function succeeds, the function returns **TBS_SUCCESS**.

If the function fails, it returns a TBS return code that indicates the error.

| Return code/value | Description |
| --- | --- |
| **TBS_SUCCESS**<br><br>0 (0x0) | The function was successful. |
| **TBS_E_OWNERAUTH_NOT_FOUND**<br><br>2150121493 (0x80284015) | The requested TPM ownerAuth value was not found. |
| **TBS_E_BAD_PARAMETER**<br><br>2150121474 (0x80284002) | The requested TPM ownerAuth value does not match the TPM version. |

## Remarks

There are additional authorization values, also known as delegation blobs, derived from the full TPM ownerAuth that allow a subset of the TPM functionality to be executed. The administrator can configure the level of ownerAuth that should be locally stored in the registry through Group Policy and the same can be obtained from this API call.

If Active Directory backup of ownerAuth is enabled through Group Policy, the default level of ownerAuth is set as Delegated which means that the full owner auth is removed from the local registry and stored in Active Directory. Only delegation blobs are locally stored in the registry in that case. Although, the level of ownerAuth storage can be explicitly configured to Full resulting in the TPM ownerAuth being locally available in the registry.