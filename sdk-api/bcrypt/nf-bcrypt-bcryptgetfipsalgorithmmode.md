# BCryptGetFipsAlgorithmMode function

## Description

The **BCryptGetFipsAlgorithmMode** function determines whether Federal Information Processing Standard (FIPS) compliance is enabled.

## Parameters

### `pfEnabled` [out]

The address of a **BOOLEAN** variable that receives zero if FIPS compliance is not enabled, or a nonzero value if FIPS compliance is enabled.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_PARAMETER** | The *pfEnabled* parameter is not valid. |

## Remarks

**BCryptGetFipsAlgorithmMode** can be called either from user mode or kernel mode. Kernel mode callers must be executing at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly).