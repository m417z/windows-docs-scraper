## Description

The **BindDevice** method binds a printer to a bidirectional printer communication (bidi communication) request. This method is similar to the [OpenPrinter](https://learn.microsoft.com/windows-hardware/drivers/print/openprinter) function.

## Parameters

### `pszDeviceName` [in]

A pointer to a null-terminated string that contains the name of the printer or print server. If **NULL**, this parameter indicates the local print server.

### `dwAccess` [in]

The access privileges for the printer. This parameter can be one of the following values.

| Value | Description |
|---|---|
| **BIDI_ACCESS_ADMINISTRATOR** | Permits users to perform all administrative tasks and basic printing operations except for SYNCHRONIZE. This is the same as PRINTER_ALL_ACCESS in [OpenPrinter](https://learn.microsoft.com/windows-hardware/drivers/print/openprinter). |
| **BIDI_ACCESS_USER** | Permits users to perform basic printing operations. This is the same as PRINTER_ACCESS_USE in [OpenPrinter](https://learn.microsoft.com/windows-hardware/drivers/print/openprinter). |

## Return value

The method returns one of the following values.

| Return code | Description |
|---|---|
| **S_OK** | The operation was successful. |
| **E_HANDLE** | The interface handle is invalid. |
| **None of the above** | The **HRESULT** contains an error code that corresponds to the last error. |

## See also

[Bidirectional Communication Interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/_print/)

[Bidirectional Communication Schema](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema)

[IBidiSpl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nn-bidispl-ibidispl2)

[OpenPrinter](https://learn.microsoft.com/windows-hardware/drivers/print/openprinter)

[Print Spooler Components](https://learn.microsoft.com/windows-hardware/drivers/print/print-spooler-components)