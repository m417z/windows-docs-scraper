# _DOCEVENT_ESCAPE structure

## Description

The DOCEVENT_ESCAPE structure is a container for values used as parameters for the **ExtEscape** function.

## Members

### `iEscape`

Specifies the value of the **ExtEscape** function's *nEscape* parameter.

### `cjInput`

Specifies the value of the **ExtEscape** function's *cbInput* parameter.

### `pvInData`

Specifies the value of the **ExtEscape** function's *lpszInData* parameter.

## Remarks

The DOCEVENT_ESCAPE structure is defined for Windows XP and later.

This structure is used in conjunction with a call to [DrvDocumentEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentevent) or [IPrintOemUI2::DocumentEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui2-documentevent), in which the *iEsc* parameter is set to DOCUMENTEVENT_ESCAPE. Before calling either of these functions, the caller must fill in the members of this structure.

Refer to the Microsoft Windows SDK documentation for a description of the **ExtEscape** function and the three parameters that correspond to the members of this structure.

## See also

[DrvDocumentEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentevent)

[IPrintOemUI2::DocumentEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui2-documentevent)