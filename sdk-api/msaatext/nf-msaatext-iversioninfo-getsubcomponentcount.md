# IVersionInfo::GetSubcomponentCount

## Description

Clients call **IVersionInfo::GetSubcomponentCount**
to determine the number of subcomponents for which version information is returned.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `ulSub` [in]

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The ordinal position of the component in the tree.

### `ulCount` [out]

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The number of subcomponents that this component will expose version information about.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK. If not successful, returns a standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values).