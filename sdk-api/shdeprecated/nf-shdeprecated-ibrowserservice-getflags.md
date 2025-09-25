# IBrowserService::GetFlags

## Description

Deprecated. Retrieves the current set of browser flags.

## Parameters

### `pdwFlags` [out]

Type: **DWORD***

A pointer to an object of type **DWORD** that represents the current set of flags. A combination of the following values.

#### BSF_REGISTERASDROPTARGET (0x00000001)

0x00000001. The browser is registered as a drop target for navigation.

#### BSF_THEATERMODE (0x00000002)

0x00000002. The browser is in theater mode.  **Not supported by**: Internet Explorer 7 or Windows Vista.

#### BSF_NOLOCALFILEWARNING (0x00000010)

0x00000010. Display a no local file warning.

#### BSF_UISETBYAUTOMATION (0x00000100)

0x00000100. The browser's UI is set by automation.

#### BSF_RESIZABLE (0x00000200)

0x00000200. The browser can be resized. **Not supported by** : Internet Explorer 7 or Windows Vista.

#### BSF_CANMAXIMIZE (0x00000400)

0x00000400. The browser can be maximized. **Not supported by**: Internet Explorer 7 or Windows Vista.

#### BSF_TOPBROWSER (0x00000800)

0x00000800. The browser is the top browser window.

#### BSF_NAVNOHISTORY (0x00001000)

0x00001000. The current location should be added to the history.

#### BSF_HTMLNAVCANCELED (0x00002000)

0x00002000. Navigation was canceled.

#### BSF_DONTSHOWNAVCANCELPAGE (0x00004000)

0x00004000. Do not display a page explaining that the navigation was canceled.

#### BSF_SETNAVIGATABLECODEPAGE (0x00008000)

0x00008000. Set a navigable code page.

#### BSF_DELEGATEDNAVIGATION (0x00010000)

0x00010000. Navigation has been delegated.

#### BSF_TRUSTEDFORACTIVEX (0x00020000)

0x00020000. Trust ActiveX objects.

#### BSF_MERGEDMENUS (0x00040000)

0x00040000. Indicates that this browser instance has merged menus.  **Not supported by**: Internet Explorer 7 or Windows Vista.

#### BSF_FEEDNAVIGATION (0x00080000)

0x00080000. Set on navigation to a feed.

#### BSF_FEEDSUBSCRIBED (0x00100000)

0x00100000. Set on navigation to a subscribed feed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.