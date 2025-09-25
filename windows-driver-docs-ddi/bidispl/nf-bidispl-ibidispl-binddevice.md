## Description

The **BindDevice** method binds a printer to a bidi request. This method is similar to the [OpenPrinter](https://learn.microsoft.com/windows-hardware/drivers/print/openprinter) function.

## Parameters

### `pszDeviceName` [in]

A pointer to a null-terminated string that contains name of the printer or print server. If **NULL**, it indicates the local printer server.

### `dwAccess` [in]

The access privileges for the printer. This parameter can be one of the following values.

| Value | Description |
|---|---|
| BIDI_ACCESS_ADMINISTRATOR | Permits users to perform all administrative tasks and basic printing operations except for SYNCHRONIZE. This is the same as PRINTER_ALL_ACCESS in [OpenPrinter](https://learn.microsoft.com/windows-hardware/drivers/print/openprinter). |
| BIDI_ACCESS_USER | Permits users to perform basic printing operations. This is the same as PRINTER_ACCESS_USE in [OpenPrinter](https://learn.microsoft.com/windows-hardware/drivers/print/openprinter). |

## Return value

The method returns one of the following values. For more information about COM error codes, see [COM Error Codes](https://learn.microsoft.com/windows/win32/com/com-error-codes).

| Value | Description |
|---|---|
| **S_OK** | The operation was successfully carried out. |
| **E_HANDLE** | The interface handle was invalid. |
| **None of the above** | The **HRESULT** contains an error code corresponding to the last error. |

## See also

[Bidirectional Communication Interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/_print/)

[Bidirectional Communication Schema](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema)

[IBidiSpl](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nn-bidispl-ibidispl)

[OpenPrinter](https://learn.microsoft.com/windows-hardware/drivers/print/openprinter)