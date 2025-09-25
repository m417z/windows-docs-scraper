# IUIAutomationCacheRequest::AddPattern

## Description

Adds a control pattern to the cache request.

## Parameters

### `patternId` [in]

Type: **PATTERNID**

The identifier of the control pattern to add to the cache request. For a list of control pattern IDs, see [Control Pattern Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-controlpattern-ids).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Adding a control pattern that is already in the cache request has no effect.

## See also

[IUIAutomationCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcacherequest)