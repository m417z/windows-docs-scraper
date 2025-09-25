## Description

Gets a value from the [ACPI_PLD_PANEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpitabl/ne-acpitabl-_acpi_pld_panel) enumeration indicating the location of the capture device, relative to the display provided to [MFCreateRelativePanelWatcher](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-mfcreaterelativepanelwatcher).

## Parameters

### `panel`

Receives a pointer to a **ULONG** value from the **ACPI_PLD_PANEL** enumeration.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
|--------------|------------------------|
|S_OK | The function succeeded.|

## Remarks

## See also