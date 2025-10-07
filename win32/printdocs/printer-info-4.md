# PRINTER\_INFO\_4 structure

The **PRINTER\_INFO\_4** structure specifies general printer information.

The structure can be used to retrieve minimal printer information on a call to [**EnumPrinters**](https://learn.microsoft.com/windows/win32/printdocs/enumprinters). Such a call is a fast and easy way to retrieve the names and attributes of all locally installed printers on a system and all remote printer connections that a user has established.

## Members

**pPrinterName**

Pointer to a null-terminated string that specifies the name of the printer (local or remote).

**pServerName**

Pointer to a null-terminated string that is the name of the server.

**Attributes**

Specifies information about the returned data.

| Value | Meaning |
|-----------------------------|----------------------------------|
| PRINTER\_ATTRIBUTE\_LOCAL | The printer is a local printer. |
| PRINTER\_ATTRIBUTE\_NETWORK | The printer is a remote printer. |

## Remarks

The **PRINTER\_INFO\_4** structure provides an easy and extremely fast way to retrieve the names of the printers installed on a local machine, as well as the remote connections that a user has established. When [**EnumPrinters**](https://learn.microsoft.com/windows/win32/printdocs/enumprinters) is called with a **PRINTER\_INFO\_4** data structure, that function queries the registry for the specified information, then returns immediately. This differs from the behavior of **EnumPrinters** when called with other levels of **PRINTER\_INFO\_xxx** data structures. In particular, when **EnumPrinters** is called with a level 2 (**PRINTER\_INFO\_2** ) data structure, it performs an **OpenPrinter** call on each remote connection. If a remote connection is down, if the remote server no longer exists, or if the remote printer no longer exists, the function must wait for RPC to time out and consequently fail the **OpenPrinter** call. This can take a while. Passing a **PRINTER\_INFO\_4** structure lets an application retrieve a bare minimum of required information; if more detailed information is desired, a subsequent **EnumPrinter** level 2 call can be made.

**Attributes** can also contain values that are defined in the **Attributes** field of **PRINTER\_INFO\_2**.

Some printer configurations, such as printer connections to some non-Windows-based print servers, might return both **PRINTER\_ATTRIBUTE\_LOCAL** and **PRINTER\_ATTRIBUTE\_NETWORK**.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_PRINTER\_INFO\_4W** (Unicode) and **\_PRINTER\_INFO\_4A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter)

[**EnumPrinters**](https://learn.microsoft.com/windows/win32/printdocs/enumprinters)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**PRINTER\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-1)

[**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2)

[**PRINTER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-3)

