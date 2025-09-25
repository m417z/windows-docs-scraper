# GetWindowsAccountDomainSid function

## Description

The **GetWindowsAccountDomainSid** function receives a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) and returns a SID representing the domain of that SID.

## Parameters

### `pSid` [in]

A pointer to the SID to examine.

### `pDomainSid` [out, optional]

Pointer that **GetWindowsAccountDomainSid** fills with a pointer to a SID representing the domain.

### `cbDomainSid` [in, out]

A pointer to a **DWORD** that **GetWindowsAccountDomainSid** fills with the size of the domain SID, in bytes.

## Return value

Returns **TRUE** if successful.

Otherwise, returns **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).