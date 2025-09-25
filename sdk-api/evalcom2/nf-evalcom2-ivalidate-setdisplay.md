# IValidate::SetDisplay

## Description

The **SetDisplay** method enables an authoring tool to obtain ICE status messages through a callback function.

## Parameters

### `pDisplayFunction` [in]

 Specifies a callback function that conforms to the [LPDISPLAYVAL](https://learn.microsoft.com/windows/desktop/api/evalcom2/nc-evalcom2-lpdisplayval) specification.

### `pContext` [in]

A pointer to an application context that is passed to the callback function. This parameter can be used for error checking. The *pContext* parameter can be **NULL**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pDisplayFunction* is invalid. |

## See also

[IValidate](https://learn.microsoft.com/windows/desktop/api/evalcom2/nn-evalcom2-ivalidate)

[Using Evalcom2](https://learn.microsoft.com/windows/desktop/Msi/using-evalcom2)

[Validation Callback Functions](https://learn.microsoft.com/windows/desktop/Msi/validation-callback-functions)