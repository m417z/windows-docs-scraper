# LPDISPLAYVAL callback function

## Description

The **LPDISPLAYVAL** function specification defines a callback function prototype. The [IValidate::SetDisplay](https://learn.microsoft.com/windows/desktop/api/evalcom2/nf-evalcom2-ivalidate-setdisplay) method enables an authoring tool to receive ICE status messages through the registered callback function.

## Parameters

### `pContext`

A pointer to an application context passed to the [SetDisplay](https://learn.microsoft.com/windows/desktop/api/evalcom2/nf-evalcom2-ivalidate-setdisplay) method.

This parameter can be used for error checking.

### `uiType` [in]

Specifies the type of message sent by the ICE.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ieUnknown**<br><br>0 | Unknown ICE message. |
| **ieError**<br><br>1 | ICE error message. |
| **ieWarning**<br><br>2 | ICE warning message. |
| **ieInfo**<br><br>3 | ICE information message. |

### `szwVal` [in]

The name of the ICE reporting the message, or an error reported by evalcom2 during validation.

### `szwDescription` [in]

The message text.

### `szwLocation` [in]

The location of the error.

This parameter can be **NULL** if the error does not refer to an actual database table or row. Specify the location of the error using the following format: Table\tColumn\tPrimaryKey1[\tPrimaryKey2\ . . .].

## Return value

| Return code/value | Description |
| --- | --- |
| ****TRUE****<br><br>1 | Validation procedure should continue. |
| ****FALSE****<br><br>0 | Validation was canceled. The callback function return **FALSE** to stop validation. |

## See also

[IValidate](https://learn.microsoft.com/windows/desktop/api/evalcom2/nn-evalcom2-ivalidate)

[Using Evalcom2](https://learn.microsoft.com/windows/desktop/Msi/using-evalcom2)

[Validation Callback Functions](https://learn.microsoft.com/windows/desktop/Msi/validation-callback-functions)