# BCryptCloseAlgorithmProvider function

## Description

The **BCryptCloseAlgorithmProvider** function closes a CNG algorithm provider.

**Note:** Callers targeting Windows 10 and later should consider using [CNG Algorithm Pseudo-handles](https://learn.microsoft.com/windows/win32/seccng/cng-algorithm-pseudo-handles) instead of opening and closing CNG algorithm providers. See remarks of the CNG Algorithm Pseudo-handle documentation for restrictions.

## Parameters

### `hAlgorithm` [in, out]

A handle that represents the algorithm provider to close. This handle is obtained by calling the [BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider) function.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. No flags are defined for this function.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_HANDLE** | The algorithm handle specified by the *hAlgorithm* parameter is not valid, or is a pseudo-handle which cannot be closed. |

## Remarks

**BCryptCloseAlgorithmProvider** can be called either from user mode or kernel mode. Kernel mode callers must be executing at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/win32/SecGloss/i-gly).

To call this function in kernel mode, use `Cng.lib`, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use `Ksecdd.lib`.

## See also

[BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider)

[CNG Algorithm Pseudo-handles](https://learn.microsoft.com/windows/win32/seccng/cng-algorithm-pseudo-handles)