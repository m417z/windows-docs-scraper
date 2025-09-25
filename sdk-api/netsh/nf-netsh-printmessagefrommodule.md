# PrintMessageFromModule function

## Description

The
**PrintMessageFromModule** function displays localized output to the NetShell console.

## Parameters

### `hModule` [in]

A handle to the module from which the string should be loaded.

### `dwMsgId` [in]

The identifier of the message to print.

### `...`

The arguments to fill into the message.

## Return value

Returns the number of characters printed. Returns zero upon failure.

## Remarks

Use this function when the format string, identified by the *dwMsgId* parameter, must be localized.

## See also

[PrintError](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-printerror)

[PrintMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-printmessage)