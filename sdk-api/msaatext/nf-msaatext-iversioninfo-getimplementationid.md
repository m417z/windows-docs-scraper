# IVersionInfo::GetImplementationID

## Description

Clients call **IVersionInfo::GetImplementationID** to retrieve a unique identifier for the component.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `ulSub` [in]

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The ordinal position of the component in the tree.

### `implid` [out]

Type: **GUID***

An implementation identifier for the component. The implementation identifier is unique for this component and is used only for comparing components.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK. If not successful, returns a standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values).