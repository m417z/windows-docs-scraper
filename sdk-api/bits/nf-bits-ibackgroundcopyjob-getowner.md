# IBackgroundCopyJob::GetOwner

## Description

Retrieves the identity of the job's owner.

## Parameters

### `pVal` [out]

Null-terminated string that contains the string version of the SID that identifies the job's owner. Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *ppOwner* when done.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Job owner's identity was successfully retrieved. |
| **E_INVALIDARG** | The *ppOwner* parameter cannot be **NULL**. |

## Remarks

To convert the string format of the SID into a domain\user-name format, which is suitable for display in a user interface, call the following functions:

* To convert the string SID to a SID, call the
  [ConvertStringSidToSid](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertstringsidtosida) function.
* To retrieve the domain and user name associated with the SID, call the
  [LookupAccountSid](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountsida) function.

## See also

[IBackgroundCopyJob::TakeOwnership](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-takeownership)