## Description

The DOCUMENTPROPERTYHEADER structure is used as an input parameter to a printer interface DLL's [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function.

## Members

### `cbSize`

Size, in bytes, of the DOCUMENTPROPERTYHEADER structure.

### `Reserved`

Reserved. Must be zero.

### `hPrinter`

Printer handle.

### `pszPrinterName`

Pointer to a NULL-terminated string representing the printer's name.

### `pdmIn`

Pointer to an input [**DEVMODEW**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure that the [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function should copy into the printer interface DLL's internal **DEVMODEW** structure (before the property sheet is displayed, if applicable). If DM_IN_BUFFER or DM_MODIFY is not set in **fMode**, this pointer is **NULL**.

### `pdmOut`

Pointer to an output **DEVMODEW** structure into which the [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function should copy the printer interface DLL's internal **DEVMODEW** contents (after the property sheet has been displayed, if applicable). If DM_OUT_BUFFER or DM_COPY is not set in **fMode**, this pointer is **NULL**.

### `cbOut`

Specifies the size, in bytes, of the buffer to which **pdmOut** points. For more information, see the following Remarks section.

### `fMode`

One or more of the bit flags listed in the following table. (The flags are defined in header files Wingdi.h and Winddiui.h.)

| Flag | Definition |
|---|---|
| No flags set (that is, **fMode** is 0). | The [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function should return the size, in bytes, of its DEVMODEW structure, including all public and private members, in the **cbOut** member. |
| DM_ADVANCED | If set, the [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function should only create the Advanced document page. If not set, the [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function should create both the PageSetup and Advanced document pages. (See the description of the **pDlgPage** member of the [COMPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_compropsheetui) structure.) |
| DM_IN_BUFFER or DM_MODIFY | The caller has supplied a DEVMODEW structure pointer in **pdmIn**, and the [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function should update its internal DEVMODEW structure to reflect the contents of the supplied DEVMODEW. |
| DM_IN_PROMPT or DM_PROMPT | The [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function should create its property sheet pages. (This flag is never set if the [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function's *pPSUIInfo* parameter is **NULL**.) |
| DM_NOPERMISSION | The printer interface DLL's [\_CPSUICALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-_cpsuicallback)-typed callback should not allow the user to modify properties on the displayed property sheet pages. |
| DM_OUT_BUFFER or DM_COPY | The caller has supplied a DEVMODEW structure pointer in **pdmOut**, and the [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function should copy the contents of its internal DEVMODEW structure into the supplied DEVMODEW. |
| DM_PROMPT_NON_MODAL | The [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function should create its property sheet pages, and launch a non-modal UI. (This flag is never set if the [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function's *pPSUIInfo* parameter is **NULL**.) |
| DM_USER_DEFAULT | Not used. |
| DM_OUT_DEFAULT or DM_UPDATE | Not used. |

## Remarks

The input value in the **cbOut** member is not necessarily equal to the size of the buffer pointed to by the **pdmOut** member. For example, when the *pPSUInfo* parameter of the [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function is **NULL**, and if either the **fMode** member of the DOCUMENTPROPERTYHEADER structure is zero, or the **pdmOut** member of the same structure is **NULL**, a driver should write the total size of the printer's [**DEVMODEW**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure (including the public and private structure members) in the **cbOut** member. In such a case, a driver should treat the **cbOut** member as a "write-only" member. Thus, your driver should not use **cbOut** member as the size of the buffer pointed to by the **pdmOut** member if the DrvDocumentPropertySheets function has been called. The "plotter" sample that ships with the Windows Driver Kit (WDK) demonstrates how to use the **cbOut** member correctly.

## See also

[**COMPROPSHEETUI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_compropsheetui)

[**DEVMODEW**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew)

[DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets)

[MSPLOT Plotter Driver Sample](https://github.com/microsoftarchive/msdn-code-gallery-microsoft/tree/master/Official%20Windows%20Driver%20Kit%20Sample/Windows%20Driver%20Kit%20(WDK)%208.1%20Samples/%5BC%2B%2B%5D-windows-driver-kit-81-cpp/WDK%208.1%20C%2B%2B%20Samples/MSPLOT%20Plotter%20Driver%20Sample/C%2B%2B)