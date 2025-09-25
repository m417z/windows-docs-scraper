# CredUIConfirmCredentialsW function

## Description

The **CredUIConfirmCredentials** function is called after
[CredUIPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforcredentialsa) or
[CredUICmdLinePromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduicmdlinepromptforcredentialsa), to confirm the validity of the credential harvested. **CredUIConfirmCredentials** must be called if the CREDUI_FLAGS_EXPECT_CONFIRMATION flag was passed to the "prompt" function, either [CredUIPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforcredentialsa) or [CredUICmdLinePromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduicmdlinepromptforcredentialsa), and the "prompt" function returned NO_ERROR.

After calling the "prompt" function and before calling **CredUIConfirmCredentials**, the caller must determine whether the credentials are actually valid by using the credentials to access the resource specified by *pszTargetName*. The results of that validation test are passed to **CredUIConfirmCredentials** in the *bConfirm* parameter.

## Parameters

### `pszTargetName` [in]

Pointer to a **null**-terminated string that contains the name of the target for the credentials, typically a domain or server application name. This must be the same value passed as *pszTargetName* to [CredUIPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforcredentialsa) or [CredUICmdLinePromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduicmdlinepromptforcredentialsa)

### `bConfirm` [in]

Specifies whether the credentials returned from the prompt function are valid. If **TRUE**, the credentials are stored in the credential manager as defined by [CredUIPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforcredentialsa) or [CredUICmdLinePromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduicmdlinepromptforcredentialsa). If **FALSE**, the credentials are not stored and various pieces of memory are cleaned up.

## Return value

Status of the operation is returned. The caller can check this status to determine whether the credential confirm operation succeeded. Most applications ignore this status code because the application's connection to the resource has already been done. The operation can fail because the credential was not found on the list of credentials awaiting confirmation, or because the attempt to write or delete the credential failed. Failure to find the credential on the list can occur because the credential was never queued or as a result of too many credentials being queued. Up to five credentials can be queued before older ones are discarded as newer ones are queued.

| Return code | Description |
| --- | --- |
| **NO_ERROR - (zero)** | Confirm operation succeeded. |
| **ERROR_NOT_FOUND** | The subject credential could not be found on the confirmation waiting list. |
| **ERROR_INVALID_PARAMETER** | An attempt to confirm a waiting credential failed because the credential contained data that was not valid or was inconsistent. |

## Remarks

> [!NOTE]
> The wincred.h header defines CredUIConfirmCredentials as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).