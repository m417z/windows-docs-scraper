# IVersionInfo::GetBuildVersion

## Description

Clients call **IVersionInfo::GetBuildVersion** to retrieve build information for a specified component.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `ulSub` [in]

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The ordinal position of the component in the tree.

### `pdwMajor` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The major build version of the component specified in *ulSub*.

### `pdwMinor` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The minor build version of the component specified in *ulSub*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK. If not successful, returns a standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values).