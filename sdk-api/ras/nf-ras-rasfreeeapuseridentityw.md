# RasFreeEapUserIdentityW function

## Description

Use the
**RasFreeEapUserIdentity** function to free the memory buffer returned by
[RasGetEapUserIdentity](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgeteapuseridentitya).

## Parameters

### `pRasEapUserIdentity` [in]

Pointer to the
[RASEAPUSERIDENTITY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377247(v=vs.85)) structure returned by the
[RasGetEapUserIdentity](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgeteapuseridentitya) function.
**RasFreeEapUserIdentity** frees the memory occupied by this structure.

## Remarks

**RasFreeEapUserIdentity** can be called with the *pRasEapUserIdentity* parameter equal to **NULL**.

> [!NOTE]
> The ras.h header defines RasFreeEapUserIdentity as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASEAPUSERIDENTITY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377247(v=vs.85))

[RasGetEapUserIdentity](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgeteapuseridentitya)