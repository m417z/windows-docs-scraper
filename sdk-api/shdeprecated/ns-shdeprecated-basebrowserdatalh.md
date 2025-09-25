# BASEBROWSERDATALH structure

## Description

Contains protected members of the base class. **BASEBROWSERDATA** defines the browser state and is used with [IBrowserService2::GetBaseBrowserData](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice2-getbasebrowserdata) and [IBrowserService2::PutBaseBrowserData](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice2-putbasebrowserdata).

## Members

### `_hwnd`

Type: **HWND**

The handle of the browser's top-level window.

### `_ptl`

Type: **[ITravelLog](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nn-shdeprecated-itravellog)***

A pointer to the browser's [ITravelLog](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nn-shdeprecated-itravellog).

### `_phlf`

Type: **[IHlinkFrame](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa767938(v=vs.85))***

A pointer to the browser's [IHlinkFrame](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa767938(v=vs.85)).

**Note** This member is only valid on first navigation from an hlink element-compatible application such as Word.

### `_pautoWB2`

Type: **[IWebBrowser2](https://learn.microsoft.com/windows/desktop/api/exdisp/nn-exdisp-iwebbrowser2)***

A pointer to the browser's [IWebBrowser2](https://learn.microsoft.com/windows/desktop/api/exdisp/nn-exdisp-iwebbrowser2) object.

### `_pautoEDS`

Type: **[IExpDispSupport](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nn-shdeprecated-iexpdispsupport)***

A pointer to the browser's [IExpDispSupport](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nn-shdeprecated-iexpdispsupport) object.

### `_pautoSS`

Type: **[IShellService](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nn-shdeprecated-ishellservice)***

A pointer to the browser's [IShellService](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nn-shdeprecated-ishellservice) object.

### `_eSecureLockIcon`

Type: **int**

One of the following values to indicate the security lock icon.

#### SECURELOCK_NOCHANGE (-1)

No change in security encryption status.

#### SECURELOCK_SET_UNSECURE (0)

Default. 0x0000. No security encryption present.

#### SECURELOCK_SET_MIXED

There are multiple security encryption methods present.

#### SECURELOCK_SET_SECUREUNKNOWNBIT

The security encryption level is not known.

#### SECURELOCK_SET_SECURE40BIT

There is 40-bit security encryption present.

#### SECURELOCK_SET_SECURE56BIT

There is 56-bit security encryption present.

#### SECURELOCK_SET_FORTEZZA

There is Fortezza security encryption present.

#### SECURELOCK_SET_SECURE128BIT

There is 128-bit security encryption present.

#### SECURELOCK_FIRSTSUGGEST

A security encryption setting should be suggested.

#### SECURELOCK_SUGGEST_UNSECURE (SECURELOCK_FIRSTSUGGEST)

No security encryption has been suggested.

#### SECURELOCK_SUGGEST_MIXED

Mixed security encryption methods have been suggested.

#### SECURELOCK_SUGGEST_SECUREUNKNOWNBIT

Unknown security encryption method has been suggested.

#### SECURELOCK_SUGGEST_SECURE40BIT

40-bit security encryption has been suggested.

#### SECURELOCK_SUGGEST_SECURE56BIT

56-bit security encryption has been suggested.

#### SECURELOCK_SUGGEST_FORTEZZA

Fortezza security encryption has been suggested.

#### SECURELOCK_SUGGEST_SECURE128BIT

128-bit security encryption has been suggested.

### `_fCreatingViewWindow`

Type: **UINT**

A view window is being created by the browser.

### `_uActivateState`

Type: **UINT**

The browser view is in an activated state.

### `_pidlViewState`

### `_pctView`

Type: **[IOleCommandTarget](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-iolecommandtarget)***

A cached pointer to the [IOleCommandTarget](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-iolecommandtarget) object associated with the [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) object pointed to by **_psv**.

### `_pidlCur`

Type: **PCIDLIST_ABSOLUTE**

A PIDL of the current navigated location of the browser. This value is the same retrieved by [IBrowserService::GetPidl](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice-getpidl).

### `_psv`

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to the [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) of the current location. This **IShellView** is bound to **_pidlCur** through [IShellFolder::CreateViewObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-createviewobject).

### `_psf`

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to the [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) of the current location. This **IShellFolder** is bound to **_pidlCur**.

### `_hwndView`

Type: **HWND**

A handle to the window returned by [_psv->CreateViewWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview-createviewwindow).

### `_pszTitleCur`

Type: **LPWSTR**

A pointer to a buffer containing the Unicode title text for the current location.

### `_pidlPending`

Type: **PCIDLIST_ABSOLUTE**

The PIDL of the pending target location. Once navigation is complete, this value moves to **_pidlCur**.

### `_psvPending`

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

The [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) of the pending target location. Once navigation is complete, this value moves to **_psv**.

### `_psfPending`

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

The [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) of the pending target location. Once navigation is complete, this value moves to **_psf**.

### `_hwndViewPending`

Type: **HWND**

A handle to the pending target location's view window. Once navigation is complete, this value moves to **_hwndView**.

### `_pszTitlePending`

Type: **LPWSTR**

A pointer to a buffer containing the Unicode title text for the pending target location. Once navigation is complete, this value moves to **_pszTitleCur**.

### `_fIsViewMSHTML`

Type: **BOOL**

A value of type **BOOL** that indicates whether the browser is hosting folder content or web content.

#### TRUE

The browser is hosting web content.

#### FALSE

The browser is hosting folder content.

### `_fPrivacyImpacted`

Type: **BOOL**

A value of type **BOOL** that indicates whether there is a privacy concern with the browser's content.

#### TRUE

There is a privacy concern with the browser's content.

#### FALSE

There is not a privacy concern with the browser's content.

### `_clsidView`

Type: **CLSID**

### `_clsidViewPending`

Type: **CLSID**

### `_hwndFrame`

Type: **HWND**

### `_lPhishingFilterStatus`

Type: **LONG**

**Windows Vista with Service Pack 1 (SP1) and later or Windows Internet Explorer 7 and later only**. 0 if the phishing filter is off; 1 if it is on.

#### - _pidlNewShellView

Type: **PCIDLIST_ABSOLUTE**

A temporary placeholder for **_pidlPending** on first navigation to the pending location.