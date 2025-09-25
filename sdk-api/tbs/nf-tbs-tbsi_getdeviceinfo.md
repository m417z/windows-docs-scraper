# Tbsi_GetDeviceInfo function

## Description

Obtains the version of the TPM on the computer.

## Parameters

### `Size` [in]

Size of the memory location.

### `Info` [out]

A pointer to a [TPM_DEVICE_INFO](https://learn.microsoft.com/windows/desktop/api/tbs/ns-tbs-tpm_device_info) structure is returned containing the version information about the TPM. The location must be large enough to hold four 32-bit values.

## Return value

If the function succeeds, the function returns TBS_SUCCESS.

If the function fails, it returns a TBS return code that indicates the error.

| Return code/value | Description |
| --- | --- |
| **TBS_SUCCESS**<br><br>0 (0x0) | The function was successful. |
| **TBS_E_BAD_PARAMETER**<br><br>2150121474 (0x80284002) | One or more parameter values are not valid. |
| **TBS_E_TPM_NOT_FOUND**<br><br>2150121487 (0x8028400F) | A compatible Trusted Platform Module (TPM) Security Device cannot be found on this computer. |