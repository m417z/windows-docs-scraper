# SetShellNext function

## Description

[This function is available for use in the Windows XP operating system. It may be altered or unavailable in subsequent versions.]

Sets the **ShellNext** registry key with the specified value.

## Parameters

### `szShellNext` [in]

The string value.
The length is expected to be less than or equal to **MAX_PATH** characters.

## Return value

This function can return one of these values.

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The call is successful. |
| **ERROR_INVALID_PARAMETER** | *szShellNext* contains a **NULL** pointer or the string is zero in length. |

## See also

[CheckConnectionWizard](https://learn.microsoft.com/windows/desktop/api/icwcfg/nf-icwcfg-checkconnectionwizard)