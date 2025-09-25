# IValidate::SetStatus

## Description

The **SetStatus** method enables an authoring tool to receive information about the progress of validation through a registered callback function.

## Parameters

### `pStatusFunction` [in]

Specifies a callback function that conforms to the [LPEVALCOMCALLBACK](https://learn.microsoft.com/windows/desktop/api/evalcom2/nc-evalcom2-lpevalcomcallback) specification. The *pStatusFunction* can be **NULL**.

### `pContext`

A pointer to an application context that is passed to the callback function. This parameter can be used for error checking. The *pContext* can be **NULL**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IValidate](https://learn.microsoft.com/windows/desktop/api/evalcom2/nn-evalcom2-ivalidate)

[Using Evalcom2](https://learn.microsoft.com/windows/desktop/Msi/using-evalcom2)

[Validation Callback Functions](https://learn.microsoft.com/windows/desktop/Msi/validation-callback-functions)