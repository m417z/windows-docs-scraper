# IVersionInfo::GetComponentDescription

## Description

Clients call this method to retrieve a description of the component.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `ulSub` [in]

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The ordinal position of the component in the tree.

### `pImplStr` [out]

Type: **BSTR***

String of the form of "Company, suite, component, version." This is for human consumption and is not expected to be
parsed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK. If not successful, returns a standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values).