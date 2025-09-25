# OleUICanConvertOrActivateAs function

## Description

Determines if there are any OLE object classes in the registry that can be used to convert or activate the specified CLSID from.

## Parameters

### `rClsid` [in]

The CLSID of the class for which the information is required.

### `fIsLinkedObject` [in]

**TRUE** if the original object is a linked object; **FALSE** otherwise.

### `wFormat` [in]

Format of the original class.

## Return value

This function returns **TRUE** if the specified class can be converted to another class; **FALSE** otherwise.

## Remarks

**OleUICanConvertOrActivateAs** searches the registry for classes that include wFormat in their \Conversion\Readable\Main, \Conversion\ReadWriteable\Main, and \DataFormats\DefaultFile entries.

This function is useful for determining if a **Convert...** menu item should be disabled. If the CF_DISABLEDISPLAYASICON flag is specified in the call to [OleUIConvert](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiconverta), then the **Convert...** menu item should be enabled only if **OleUICanConvertOrActivateAs** returns **TRUE**.

## See also

[OleUIConvert](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiconverta)