# PrintMessage function

## Description

The
**PrintMessage** function displays output to the NetShell console.

## Parameters

### `pwszFormat` [in]

A string to be output to the NetShell console.

### `...`

The arguments used to fill into the message.

## Return value

Returns the number of characters printed. Returns zero upon failure.

## Remarks

Use the
**PrintMessage** function when the message to be output is not required to be localized.

## See also

[PrintError](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-printerror)

[PrintMessageFromModule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-printmessagefrommodule)