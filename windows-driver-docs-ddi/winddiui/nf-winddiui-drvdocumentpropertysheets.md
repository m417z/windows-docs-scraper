## Description

A printer interface DLL's **DrvDocumentPropertySheets** function is responsible for creating property sheet pages that describe a print document's properties.

## Parameters

### `pPSUIInfo` [in, optional]

Caller-supplied pointer to a [**PROPSHEETUI_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_propsheetui_info) structure. Can be **NULL** (see the following Remarks section).

### `lParam`

Caller-supplied integer value that is dependent on the contents of the **Reason** member of the PROPSHEETUI_INFO structure, as listed in the following table.

| Reason value | Definition of *lParam* |
|---|---|
| PROPSHEETUI_REASON_INIT | Pointer to a [**DOCUMENTPROPERTYHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_documentpropertyheader) structure. |
| All other reason values | See the description of the *lParam* parameter for the [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui) function type. (The [**DOCUMENTPROPERTYHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_documentpropertyheader) structure's address is contained in the **lParamInit** member of the [**PROPSHEETUI_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_propsheetui_info) structure.) |

## Return value

If *pPSUIInfo* is **NULL**, and if either *lParam* -> **fMode** is zero or *lParam -*> **pdmOut** is **NULL**, this function should return the size, in bytes, of the printer's [**DEVMODEW**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure. Otherwise, the function's return value is the same as that described in the ReturnValue section of the [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui) function type. For more information, see the Remarks section.

## Remarks

All [printer interface DLLs](https://learn.microsoft.com/windows-hardware/drivers/print/printer-interface-dll) must provide a **DrvDocumentPropertySheets** function, which is defined using the [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui) function type. The function's purpose is to call the [ComPropSheet](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfncompropsheet) function, provided by [CPSUI](https://learn.microsoft.com/windows-hardware/drivers/print/common-property-sheet-user-interface), to specify property sheet pages containing user-modifiable properties for print documents.

If the value received for the *pPSUIInfo* parameter is not **NULL**, the NT-based operating system print spooler is calling the function indirectly, through CPSUI. The following rules apply:

- The function should perform operations as described for the [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui) function type.

- Flags in the **fMode** member of the [**DOCUMENTPROPERTYHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_documentpropertyheader) structure indicate which property sheet pages to display and whether the user should be allowed to modify a document's properties. The only flags that might be set are DM_IN_PROMPT (or DM_PROMPT), DM_ADVANCED, DM_NOPERMISSION, and DM_OUT_BUFFER (or DM_COPY).

If the value received for the *pPSUIInfo* parameter is **NULL**, the print spooler is calling the function directly, without going through CPSUI. In this case, the *lParam* parameter contains the address of a DOCUMENTPROPERTYHEADER structure, and the following rules apply:

- If the **fMode** member of the [**DOCUMENTPROPERTYHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_documentpropertyheader) structure is zero, or if the **pdmOut** member of the same structure is **NULL**, the function should return just the total size of the printer's [**DEVMODEW**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure, including public and private structure members, in the DOCUMENTPROPERTYHEADER structure's **cbOut** member.

- If the **fMode** member of the DOCUMENTPROPERTYHEADER structure is not zero, the function should perform the operations indicated by the **fMode** flags. The only flags that might be set are DM_IN_BUFFER (or DM_MODIFY), and DM_OUT_BUFFER (or DM_COPY).

## See also

[**DOCUMENTPROPERTYHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_documentpropertyheader)

[DrvDevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdevicepropertysheets)

[IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets)