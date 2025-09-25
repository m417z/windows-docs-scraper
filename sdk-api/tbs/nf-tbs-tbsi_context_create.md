# Tbsi_Context_Create function

## Description

Creates a context handle that can be used to pass commands to TBS.

## Parameters

### `pContextParams` [in]

A parameter to a [TBS_CONTEXT_PARAMS](https://learn.microsoft.com/windows/win32/api/tbs/ns-tbs-tbs_context_params) structure that contains the parameters associated with the context.

### `phContext` [out]

A pointer to a location to store the new context handle.

## Return value

If the function succeeds, the function returns TBS_SUCCESS.

If the function fails, it returns a TBS return code that indicates the error.

| Return code/value | Description |
| --- | --- |
| **TBS_SUCCESS**<br><br>0 (0x0) | The function was successful. |
| **TBS_E_BAD_PARAMETER**<br><br>2150121474 (0x80284002) | One or more parameter values are not valid. |
| **TBS_E_INTERNAL_ERROR**<br><br>2150121473 (0x80284001) | An internal software error occurred. |
| **TBS_E_INVALID_CONTEXT_PARAM**<br><br>2150121479 (0x80284007) | A context parameter that is not valid was passed when attempting to create a TBS context. |
| **TBS_E_INVALID_OUTPUT_POINTER**<br><br>2150121475 (0x80284003) | A specified output pointer is not valid. |
| **TBS_E_SERVICE_DISABLED**<br><br>2150121488 (0x80284010) | The TBS service has been disabled. |
| **TBS_E_SERVICE_NOT_RUNNING**<br><br>2150121480 (0x80284008) | The TBS service is not running and could not be started. |
| **TBS_E_SERVICE_START_PENDING**<br><br>2150121483 (0x8028400B) | The TBS service has been started but is not yet running. |
| **TBS_E_TOO_MANY_TBS_CONTEXTS**<br><br>2150121481 (0x80284009) | A new context could not be created because there are too many open contexts. |
| **TBS_E_TPM_NOT_FOUND**<br><br>2150121487 (0x8028400F) | A compatible Trusted Platform Module (TPM) Security Device cannot be found on this computer. |

## Remarks

The [TBS_CONTEXT_PARAMS](https://learn.microsoft.com/windows/win32/api/tbs/ns-tbs-tbs_context_params) structure can be provided, with the version field set to TPM_VERSION_12.
Applications interacting with version 2.0 TPM will pass a pointer to a [TBS_CONTEXT_PARAMS2](https://learn.microsoft.com/windows/win32/api/tbs/ns-tbs-tbs_context_params2) structure, with the version field set to TPM_VERSION_20. Set the reserved field to 0, and the **includeTPm20** field to 1. If the application is prepared to interact with a version 1.2 TPM as well (in case the system has no version 2.0 TPM), set the **includeTpm12** field to 1.

If no TPM is present on the system, or the TPM version does not match those requested by the caller, **Tbsi_Context_Create** will return the TBS_E_TPM_NOT_FOUND (0x8028400) error code. Application programs must check for both versions and be able to interact with either TPM.