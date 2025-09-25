# CredGetTargetInfoW function

## Description

The **CredGetTargetInfo** function retrieves all known target name information for the named target computer. This executed locally and does not need any particular privilege. The information returned is expected to be passed to the
[CredReadDomainCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credreaddomaincredentialsa) and
[CredWriteDomainCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credwritedomaincredentialsa) functions. The information should not be used for any other purpose.

Authentication packages compute *TargetInfo* when attempting to authenticate to a *TargetName*. The authentication packages cache this target information to make it available to **CredGetTargetInfo**. Therefore, the target information will only be available from a recent attempt to authenticate a *TargetName*.

Authentication packages not in the LSA process can cache a *TargetInfo* for later retrieval by **CredGetTargetInfo** by calling [CredReadDomainCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credreaddomaincredentialsa) with the CRED_CACHE_TARGET_INFORMATION flag.

## Parameters

### `TargetName` [in]

Pointer to a null-terminated string that contains the name of the target computer for which information is to be retrieved.

### `Flags` [in]

Flags controlling the operation of the function. The following flag can be used:

CRED_ALLOW_NAME_RESOLUTION

If no target information can be found for *TargetName* name resolution is done on *TargetName* to convert it to other forms. If target information exists for any of those other forms, it is returned. Currently only DNS name resolution is done.

This is useful if the application does not call an authentication package directly. The application can pass the *TargetName* to another layer of software to authenticate to the server, and that layer of software might resolve the name and pass the resolved name to the authentication package. As such, there will be no target information for the original *TargetName*.

### `TargetInfo` [out]

Pointer to a single allocated block buffer to contain the target information. At least one of the returned members of *TargetInfo* will be non-NULL. Any pointers contained within the buffer are pointers to locations within this single allocated block. The single returned buffer must be freed by calling [CredFree](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credfree).

## Return value

The function returns **TRUE** on success and **FALSE** on failure. The [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function can be called to get a more specific status code. The following status code can be returned:

* ERROR_NOT_FOUND

  Target information for the named server is not available.

## See also

[CredFree](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credfree)

[CredReadDomainCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credreaddomaincredentialsa)

[CredWriteDomainCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credwritedomaincredentialsa)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

## Remarks

> [!NOTE]
> The wincred.h header defines CredGetTargetInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).