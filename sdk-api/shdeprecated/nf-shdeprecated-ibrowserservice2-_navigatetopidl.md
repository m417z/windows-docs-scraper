# IBrowserService2::_NavigateToPidl

## Description

Deprecated. Navigates the base class to a new location synchronously.

## Parameters

### `pidl` [in]

Type: **LPCITEMIDLIST**

The PIDL identifying the new location.

### `grfHLNF` [in]

Type: **DWORD**

The value or values from the [HLNF](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa740922(v=vs.85)) enumeration. The following values are also supported.

#### HLNF_CALLERUNTRUSTED

0x00200000. The navigation was possibly initiated through a webpage by scripting code already on the system.

#### HLNF_TRUSTEDFORACTIVEX

0x00400000. The navigation allows ActiveX prompts.

#### HLNF_DISABLEWINDOWRESTRICTIONS

0x00800000. The new window is created by a URL in a zone that has the window restrictions security mitigation disabled.

#### HLNF_TRUSTFIRSTDOWNLOAD

0x01000000. The new window is the result of a user-initiated action. If the destination attempts a download on entry, it should be trusted.

#### HLNF_UNTRUSTEDFORDOWNLOAD

0x02000000. Internet Explorer is navigating to an untrusted non-HTML file. Do not download the file.

#### SHHLNF_NOAUTOSELECT

0x04000000. This navigation should not automatically select the history folder.

#### SHHLNF_WRITENOHISTORY

0x08000000. This navigation should not be recorded in the history.

#### HLNF_EXTERNALNAVIGATE

0x10000000.

#### HLNF_ALLOW_AUTONAVIGATE

0x20000000.

#### HLNF_NEWWINDOWSMANAGED

0x80000000. If this navigation results in a new window, the new window should be subject to the Pop-up Manager.

### `dwFlags` [in]

Type: **DWORD**

Not used.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBrowserService2](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nn-shdeprecated-ibrowserservice2)

[NavigateToPidl](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice-navigatetopidl)