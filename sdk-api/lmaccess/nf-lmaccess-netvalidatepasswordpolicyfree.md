# NetValidatePasswordPolicyFree function

## Description

The **NetValidatePasswordPolicyFree** function frees the memory that the [NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy) function allocates for the *OutputArg* parameter, which is a [NET_VALIDATE_OUTPUT_ARG](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_output_arg) structure.

## Parameters

### `OutputArg` [in]

Pointer to the memory allocated for the *OutputArg* parameter by a call to the **NetValidatePasswordPolicy** function.

## Return value

If the function frees the memory, or if there is no memory to free from a previous call to **NetValidatePasswordPolicy**, the return value is NERR_Success.

If the function fails, the return value is a system error code. For a list of error codes, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

No special group membership is required to successfully execute this function.

## See also

[NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)