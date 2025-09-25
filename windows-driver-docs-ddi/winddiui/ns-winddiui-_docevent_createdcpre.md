# _DOCEVENT_CREATEDCPRE structure

## Description

The DOCEVENT_CREATEDCPRE structure contains a set of values used in certain calls to [DrvDocumentEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentevent) and [IPrintOemUI2::DocumentEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui2-documentevent).

## Members

### `pszDriver`

Reserved for system use. Set to zero.

### `pszDevice`

Pointer to the first byte of a Unicode string that contains either the device name or the port name, depending on whether print spooling is enabled or disabled. If the print job is being sent directly to the printer (spooling is disabled), this member contains the printer name. If a print job is being spooled, this member contains the port name.

### `pdm`

Pointer to a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure passed to either CreateIC or CreateDC (both described in the Microsoft Windows SDK documentation). This member can be **NULL**.

### `bIC`

Specifies whether the DEVMODEW structure pointed to by the **pdm** member is being passed to CreateIC or CreateDC. If **TRUE**, CreateIC is being called. If **FALSE**, CreateDC is being called.

## Remarks

The DOCEVENT_CREATEDCPRE structure is defined for Windows XP and later.

This structure is used in conjunction with a call to [DrvDocumentEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentevent) or [IPrintOemUI2::DocumentEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui2-documentevent), in which the *iEsc* parameter is set to DOCUMENTEVENT_CREATEDCPRE. Before calling either of these functions, the caller must fill in the members of this structure.

## See also

[DrvDocumentEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentevent)

[IPrintOemUI2::DocumentEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui2-documentevent)