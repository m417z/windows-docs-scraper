# IPropertyPageSite::TranslateAccelerator

## Description

Passes a keystroke to the property frame for processing.

## Parameters

### `pMsg` [in]

A pointer to the [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure to be processed.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **S_FALSE** | The page site did not process the message. |
| **E_NOTIMPL** | The page site does not support keyboard processing. |

## See also

[IPropertyPageSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypagesite)