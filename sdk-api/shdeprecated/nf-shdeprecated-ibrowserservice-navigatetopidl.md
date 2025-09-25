# IBrowserService::NavigateToPidl

## Description

Deprecated. Navigates the browser to the location indicated by a pointer to an item identifier list (PIDL).

## Parameters

### `pidl` [in]

Type: **LPCITEMIDLIST**

The PIDL of the location.

### `grfHLNF` [in]

Type: **DWORD**

One or more of the following flags.

#### HLNF_NAVIGATINGBACK (0x00000004)

The navigation is to the previous destination in the browse context.

#### HLNF_NAVIGATINGFORWARD (0x00000008)

The navigation is to the next destination in the browse context.

#### HLNF_CALLERUNTRUSTED (0x00200000)

The navigation was possibly initiated through a webpage by scripting code already on the system.

#### HLNF_TRUSTEDFORACTIVEX (0x00400000)

The navigation allows Microsoft ActiveX prompts.

#### HLNF_DISABLEWINDOWRESTRICTIONS (0x00800000)

A new window is created by a URL in a zone with window restrictions security mitigation disabled.

#### HLNF_TRUSTFIRSTDOWNLOAD (0x01000000)

The new window is the result of a user-initiated action. If the destination attempts a download on entry, it should be trusted.

#### HLNF_UNTRUSTEDFORDOWNLOAD (0x02000000)

Microsoft Internet Explorer is navigating to an untrusted non-HTML file. Do not download the file.

#### HLNF_EXTERNALNAVIGATE (0x10000000)

#### HLNF_ALLOW_AUTONAVIGATE (0x20000000)

#### HLNF_NEWWINDOWSMANAGED (0x80000000)

If this navigation results in a new window, it should be subject to Pop-up Manager.

#### SHHLNF_WRITENOHISTORY (0x08000000)

The destination of the current navigation should not be placed into the browser's history record.

#### SHHLNF_NOAUTOSELECT (0x04000000)

The destination of the current navigation should not be automatically selected from the browser's history record.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBrowserService](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nn-shdeprecated-ibrowserservice)

[_NavigateToPidl](https://learn.microsoft.com/windows/win32/api/shdeprecated/nf-shdeprecated-ibrowserservice2-_navigatetopidl)