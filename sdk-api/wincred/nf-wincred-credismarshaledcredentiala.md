# CredIsMarshaledCredentialA function

## Description

The **CredIsMarshaledCredential** function determines whether a specified user name string is a marshaled credential previously marshaled by
[CredMarshalCredential](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credmarshalcredentiala).

## Parameters

### `MarshaledCredential` [in]

Pointer to a null-terminated string that contains the marshaled credential.

## Return value

This function returns **TRUE** if *MarshaledCredential* is a marshaled credential and **FALSE** if it is not.

## Remarks

> [!NOTE]
> The wincred.h header defines CredIsMarshaledCredential as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).