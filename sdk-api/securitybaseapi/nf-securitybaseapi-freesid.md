# FreeSid function

## Description

The **FreeSid** function frees a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) previously allocated by using the
[AllocateAndInitializeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-allocateandinitializesid) function.

## Parameters

### `pSid` [in]

A pointer to the
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure to free.

## Return value

If the function succeeds, the function returns **NULL**.

If the function fails, it returns a pointer to the [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure represented by the *pSid* parameter.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[AllocateAndInitializeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-allocateandinitializesid)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)