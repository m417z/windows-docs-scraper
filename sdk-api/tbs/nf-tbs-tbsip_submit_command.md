# Tbsip_Submit_Command function

## Description

Submits a Trusted Platform Module (TPM) command to TPM Base Services (TBS) for processing.

## Parameters

### `hContext` [in]

The handle of the context that is submitting the command.

### `Locality` [in]

Used to set the locality for the TPM command. This must be one of the following values.

| Value | Meaning |
| --- | --- |
| **TBS_COMMAND_LOCALITY_ZERO**<br><br>0 (0x0) | Locality zero. This is the only locality currently supported. |
| **TBS_COMMAND_LOCALITY_ONE**<br><br>1 (0x1) | Locality one. |
| **TBS_COMMAND_LOCALITY_TWO**<br><br>2 (0x2) | Locality two. |
| **TBS_COMMAND_LOCALITY_THREE**<br><br>3 (0x3) | Locality three. |
| **TBS_COMMAND_LOCALITY_FOUR**<br><br>4 (0x4) | Locality four. |

### `Priority` [in]

The priority level that the command should have. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TBS_COMMAND_PRIORITY_LOW**<br><br>100 (0x64) | Used for low priority application use. |
| **TBS_COMMAND_PRIORITY_NORMAL**<br><br>200 (0xC8) | Used for normal priority application use. |
| **TBS_COMMAND_PRIORITY_SYSTEM**<br><br>400 (0x190) | Used for system tasks that access the TPM. |
| **TBS_COMMAND_PRIORITY_HIGH**<br><br>300 (0x12C) | Used for high priority application use. |
| **TBS_COMMAND_PRIORITY_MAX**<br><br>2147483648 (0x80000000) | Used for tasks that originate from the power management system. |

### `pabCommand` [in]

A pointer to a buffer that contains the TPM command to process.

### `cbCommand` [in]

The length, in bytes, of the command.

### `pabResult` [out]

A pointer to a buffer to receive the result of the TPM command. This buffer can be the same as *pabCommand*.

### `pcbResult` [in, out]

An integer that, on input, specifies the size, in bytes, of the result buffer. This value is set when the submit command returns. If the supplied buffer is too small, this parameter, on output, is set to the required size, in bytes, for the result.

## Return value

If the function succeeds, the function returns TBS_SUCCESS.

A command can be submitted successfully and still fail at the TPM. In this case, the failure code is returned as a standard TPM error in the result buffer.

If the function fails, it returns a TBS return code that indicates the error.

| Return code/value | Description |
| --- | --- |
| **TBS_SUCCESS**<br><br>0 (0x0) | The function was successful. |
| **TBS_E_BAD_PARAMETER**<br><br>2150121474 (0x80284002) | One or more parameter values are not valid. |
| **TBS_E_BUFFER_TOO_LARGE**<br><br>2150121486 (0x8028400E) | The input or output buffer is too large. |
| **TBS_E_INTERNAL_ERROR**<br><br>2150121473 (0x80284001) | An internal software error occurred. |
| **TBS_E_INSUFFICIENT_BUFFER**<br><br>2150121477 (0x80284005) | The specified output buffer is too small. |
| **TBS_E_INVALID_CONTEXT**<br><br>2150121476 (0x80284004) | The specified context handle does not refer to a valid context. |
| **TBS_E_INVALID_OUTPUT_POINTER**<br><br>2150121475 (0x80284003) | A specified output pointer is not valid. |
| **TBS_E_IOERROR**<br><br>2150121478 (0x80284006) | An error occurred while communicating with the TPM. |