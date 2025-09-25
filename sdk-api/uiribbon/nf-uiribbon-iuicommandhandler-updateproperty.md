# IUICommandHandler::UpdateProperty

## Description

Responds to property update requests from the Windows Ribbon framework.

## Parameters

### `commandId` [in]

Type: **UINT32**

The ID for the Command, which is specified in the Markup resource file.

### `key` [in]

Type: **REFPROPERTYKEY**

The [Property Key](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-properties) to update.

### `currentValue` [in, optional]

Type: **const PROPVARIANT***

A pointer to the current value for *key*. This parameter can be **NULL**.

### `newValue` [out]

Type: **PROPVARIANT***

When this method returns, contains a pointer to the new value for
*key*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method should be allowed to return before any subsequent calls to the Ribbon framework are made.

The values of Command properties, such as [UI_PKEY_Enabled](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-properties-uipkey-enabled) or [UI_PKEY_Label](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-properties-uipkey-label), are set through calls to [SetUICommandProperty](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiframework-setuicommandproperty) or [InvalidateUICommand](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiframework-invalidateuicommand).

## See also

[IUICommandHandler](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicommandhandler)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)