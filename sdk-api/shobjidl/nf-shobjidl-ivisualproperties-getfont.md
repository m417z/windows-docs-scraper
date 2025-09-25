# IVisualProperties::GetFont

## Description

Gets the current attributes set on the font.

## Parameters

### `plf` [out]

Type: **LOGFONTW***

A pointer to a [LOGFONT](https://learn.microsoft.com/windows/win32/api/dimm/ns-dimm-logfonta) structure that, when this method returns successfully, receives the current attributes of the font.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.