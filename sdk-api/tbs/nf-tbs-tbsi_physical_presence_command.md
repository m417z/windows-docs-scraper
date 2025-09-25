# Tbsi_Physical_Presence_Command function

## Description

Passes a physical presence ACPI command through TBS to the driver.

## Parameters

### `hContext` [in]

The context of the ACPI command.

### `pabInput` [in]

A pointer to a buffer that contains the input to the ACPI command.

The input to the ACPI command is defined in the *TCG Physical Presence Interface Specification* at https://www.trustedcomputinggroup.org. The buffer should contain *Arg2* and *Arg3* values as defined in this document. The values for *Arg0* and *Arg1* are static and automatically added. For example, if this method is used for Get Physical Presence Interface Version, then *Arg2* is the integer value 1 and *Arg3* is empty, so the buffer should just contain an integer value of 1. If this method is used for "Submit TPM Operation Request to Pre-OS Environment", then *Arg2* is the integer value 2 and *Arg3* will be the integer for the specified operation, such as 1 for enable or 2 for disable.

### `cbInput` [in]

The length, in bytes, of the input buffer.

### `pabOutput` [out]

A pointer to a buffer to contain the output of the ACPI command.

The buffer will contain the return value from the command as defined in the [TCG Physical Presence Interface Specification](https://trustedcomputinggroup.org).

### `pcbOutput` [in, out]

A pointer to an unsigned long integer that, on input, specifies the size, in bytes, of the output buffer. If the function succeeds, this parameter, on output, receives the size, in bytes, of the data pointed to by *pabOutput*. If the function fails, this parameter does not receive a value.

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

## Remarks

For more information, see [TCG Physical Presence Interface Specification](https://trustedcomputinggroup.org).