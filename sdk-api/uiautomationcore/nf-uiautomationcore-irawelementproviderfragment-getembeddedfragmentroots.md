# IRawElementProviderFragment::GetEmbeddedFragmentRoots

## Description

Retrieves an array of root fragments that are embedded in the Microsoft UI Automation tree rooted at the current element.

## Parameters

### `pRetVal` [out, retval]

Type: **SAFEARRAY****

Receives an array of pointers to the root fragments, or **NULL** (see Remarks). This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method returns an array of fragments only if the current element is hosting another automation framework.
Most providers return **NULL**.

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

**Conceptual**

[IRawElementProviderFragment](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragment)

**Reference**