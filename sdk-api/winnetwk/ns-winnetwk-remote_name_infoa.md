# REMOTE_NAME_INFOA structure

## Description

The **REMOTE_NAME_INFO** structure contains information about the remote form of a universal name. It is used by the
[NPGetUniversalName](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npgetuniversalname) function.

## Members

### `lpUniversalName`

Pointer to the universal name if the provider supports universal names. Otherwise, this points to **NULL**.

### `lpConnectionName`

Pointer to a string containing the remote name used to make the connection. This string does not have a trailing backslash.

### `lpRemainingPath`

Pointer to the remaining path that must to be concatenated to a drive letter after a connection is established by means of **lpConnectionName**, to refer to the object specified during the call to [NPGetUniversalName](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npgetuniversalname). This string has a backslash at the start of the path.

## Remarks

> [!NOTE]
> The winnetwk.h header defines REMOTE_NAME_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).