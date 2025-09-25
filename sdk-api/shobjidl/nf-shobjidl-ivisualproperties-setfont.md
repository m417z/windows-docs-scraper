# IVisualProperties::SetFont

## Description

Sets attributes of the font.

## Parameters

### `plf` [in]

Type: **const LOGFONTW***

A pointer to a [LOGFONT](https://learn.microsoft.com/windows/win32/api/dimm/ns-dimm-logfonta) structure that contains the attributes to set.

### `bRedraw` [in]

Type: **BOOL**

**TRUE** if the item should be redrawn after the new attributes are set; otherwise **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.