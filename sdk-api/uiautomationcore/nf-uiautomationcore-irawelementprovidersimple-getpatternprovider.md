# IRawElementProviderSimple::GetPatternProvider

## Description

Retrieves a pointer to an object that provides support for a control pattern on a Microsoft UI Automation element.

## Parameters

### `patternId` [in]

Type: **PATTERNID**

The identifier of the control pattern. For a list of control pattern IDs, see [Control Pattern Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-controlpattern-ids).

### `pRetVal` [out, retval]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

Receives a pointer to the object that supports the control pattern,
or **NULL** if the control pattern is not supported.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)