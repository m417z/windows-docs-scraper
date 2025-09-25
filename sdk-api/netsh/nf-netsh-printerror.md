# PrintError function

## Description

The
**PrintError** function displays a system or application error message to the NetShell console.

## Parameters

### `hModule` [in]

A handle to the module from which the string should be loaded, or null for system error messages.

### `dwErrId` [in]

The identifier of the message to print.

### `...`

The arguments used to fill into the message.

## Return value

Returns the number of characters printed. Returns zero upon failure.

## See also

[PrintMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-printmessage)

[PrintMessageFromModule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-printmessagefrommodule)