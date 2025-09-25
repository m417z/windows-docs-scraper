# IBidiSpl2::UnbindDevice

## Description

The **UnbindDevice** method releases a printer from a bidirectional printer communication (bidi communication) request.

## Return value

The method returns one of the following values.

| Value | Description |
|---|---|
| **S_OK** | The operation was successful. |
| **E_HANDLE** | The interface handle is invalid. |
| **None of the above** | The **HRESULT** contains an error code that corresponds to the last error. |

## See also

[Bidirectional Communication Interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/_print/)

[Bidirectional Communication Schema](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema)

[IBidiSpl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nn-bidispl-ibidispl2)

[Print Spooler Components](https://learn.microsoft.com/windows-hardware/drivers/print/print-spooler-components)