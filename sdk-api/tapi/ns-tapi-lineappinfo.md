# LINEAPPINFO structure

## Description

The
**LINEAPPINFO** structure contains information about the application that is currently running. The
[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus) structure can contain an array of
**LINEAPPINFO** structures.

## Members

### `dwMachineNameSize`

Size of the computer name string including the **null** terminator, in bytes.

### `dwMachineNameOffset`

Offset from the beginning of the
[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus) structure to a string specifying the name of the computer on which the application is executing. The size of the field is specified by **dwMachineNameSize**.

### `dwUserNameSize`

Size of the user name string including the **null** terminator, in bytes.

### `dwUserNameOffset`

Offset from the beginning of the
[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus) structure to a string specifying the user name under whose account the application is running. The size of the field is specified by **dwUserNameSize**.

### `dwModuleFilenameSize`

Size of the module file name string, in bytes.

### `dwModuleFilenameOffset`

Offset from the beginning of
[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus) to a string specifying the module file name of the application. This string can be used in a call to
[lineHandoff](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linehandoff) to perform a directed handoff to the application. The size of the field is specified by **dwModuleFilenameSize**.

### `dwFriendlyNameSize`

Size of the display name string, in bytes.

### `dwFriendlyNameOffset`

Offset from the beginning of
[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus) to the string provided by the application to
[lineInitialize](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitialize) or
[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa), which should be used in any display to the user. The size of the field is specified by **dwFriendlyNameSize**.

### `dwMediaModes`

Media types for which the application has requested ownership of new calls; zero if when it opened the line **dwPrivileges** did not include LINECALLPRIVILEGE_OWNER.

### `dwAddressID`

If the line handle was opened using LINEOPENOPTION_SINGLEADDRESS, contains the address identifier specified; set to 0xFFFFFFFF if the single address option was not used.

An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

## See also

[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus)

[TSPI_lineGetLineDevStatus](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetlinedevstatus)

[lineGetLineDevStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetlinedevstatus)

[lineHandoff](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linehandoff)

[lineInitialize](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitialize)

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)