# IComponent::GetResultViewType

## Description

The **IComponent::GetResultViewType** method
determines what the result pane view should be.

## Parameters

### `cookie` [in]

A value that specifies the snapin-provided unique identifier for the scope item. For more details about
cookies in MMC, see [Cookies](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/cookies).

### `ppViewType` [out]

A pointer to the address of a string that specifies the view to display for the specified
*cookie*. The callee (snap-in) allocates the view type string using the COM API function
[CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and the caller (MMC) frees it using
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

The string that is returned depends on the view type:

#### Standard list

For standard list views, MMC does not use this value. If the snap-in uses only standard list views, the
snap-in can set *ppViewType* to **NULL**. MMC uses standard
list views as the default view type.

#### Taskpad

For a taskpad view that uses MMC taskpad templates, *ppViewType* should point to
the address of a string that contains the resource path to the taskpad template and a group name that
identifies the taskpad. Be aware that MMC passes the group name in calls to
[IExtendTaskPad](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendtaskpad) methods to enable the snap-in to
identify the particular taskpad that is being displayed (this is important if the snap-in has multiple
taskpads).

The string should have the following form:

"res://*filepath*/*template*#*groupname*"

where *filepath* is the full path to the MMC executable
(MMC.exe), *template* is the file name of the template
that is stored as a resource within the file specified by *filepath*, and
*groupname* is the name that identifies the taskpad.

MMC supplies the following HTML files as templates:

| Resource file | Description |
| --- | --- |
| default.htm | Template for standard taskpad |
| listpad.htm | Template for "vertical" list view taskpad |
| horizontal.htm | Template for "horizontal" list view taskpad |

For example, the following string specifies that MMC.exe has a path of
c:\Windows\System32\mmc.exe, the standard taskpad is displayed (default.htm), and
the group name is tpad1: "res://c:\\Windows\\System32\\mmc.exe/default.htm#tpad1".

For a taskpad view that uses a custom HTML page, *ppViewType* should point to the
address of a string that contains the resource path to the custom taskpad's HTML file and a group name that
identifies the taskpad. The string has the same form as the string for an MMC taskpad
template—except the *filepath* should specify the path to the
snap-in's DLL that stores the custom HTML page as a resource.

#### Custom OCX

For a custom view provided by an OLE custom control (OCX),
*ppViewType* should point to the address of a string that contains the string
representation of the custom control's **CLSID**. The string must begin with an
open curly brace ({) and end with a close curly brace (}). The following string represents the Calendar
control and could be returned in the *ppViewType* parameter to display the Calendar
control in the result pane: "{8E27C92B-1264-101C-8A2F-040224009C02}".

MMC allows a single instance of each OCX type per snap-in instance per view. If the
**MMC_VIEW_OPTIONS_CREATENEW** option is not selected, MMC will display the cached
OCX instance for any of the snap-in's scope items that request this OCX view. If
the **MMC_VIEW_OPTIONS_CREATENEW** option is selected, MMC will destroy the cached
OCX and create a new one every time a item requests the OCX view.

#### Custom webpage

For a custom view provided by a webpage, *ppViewType* should point to the
address of a string that contains the URL for the page. The following string represents the URL for the
Microsoft website and could be returned in the *ppViewType* parameter to display the
website in the result pane: "www.microsoft.com".

### `pViewOptions` [out]

A pointer to the value that provides the console with options specified by the owning snap-in. This value
can be a combination of the following:

#### MMC_VIEW_OPTIONS_CREATENEW (0x0010)

For a custom OCX view. In MMC 1.2, the OCX is always cached. If this flag is not
specified, MMC 1.2 displays the cached OCX instance for any of the snap-in's scope items that
request this OCX view. If this flag is specified, MMC 1.2 destroys the cached OCX
and creates (then caches) a new one every time an item requests the OCX view. In MMC 2.0, the
OCX will be cached only if this flag is not set. In MMC 2.0, the snap-in can release any
OCXs when the node is deselected if this flag is set.

Once the snap-in has specified its OCX caching option for a node (either by using or not using
the **MMC_VIEW_OPTIONS_CREATENEW** flag), it must not change the option choice for this
instance of the snap-in.

#### MMC_VIEW_OPTIONS_EXCLUDE_SCOPE_ITEMS_FROM_LIST (0x00000040)

New in MMC 1.2. In a standard list view, this option tells MMC to hide scope items in the view. Scope
items are automatically hidden in virtual list views.

#### MMC_VIEW_OPTIONS_FILTERED (0x0008)

Notifies MMC that the snap-in supports filtered views. See
[Adding Filtered Views](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/adding-filtered-views).

#### MMC_VIEW_OPTIONS_LEXICAL_SORT (0x00000080)

New in MMC 1.2. In a standard list view, this option tells MMC to lexically sort all scope items
(including extensions) first, followed by all result items. The
[IResultDataCompare](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdatacompare) and
[IResultDataCompareEx](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdatacompareex) interfaces are ignored when
this option is set.

#### MMC_VIEW_OPTIONS_MULTISELECT (0x0004)

Allows multiple item selections in the result pane view.

#### MMC_VIEW_OPTIONS_NOLISTVIEWS (0x0001)

Tells the console to refrain from presenting standard list view choices in the
**View** menu. Allows the snap-in to display only its own custom views in the result
pane.

#### MMC_VIEW_OPTIONS_NONE (0)

No view options selected. This is the default view option.

#### MMC_VIEW_OPTIONS_OWNERDATALIST (0x0002)

A value that specifies that the result pane list view should be a virtual list.

#### MMC_VIEW_OPTIONS_USEFONTLINKING (0x0020)

Use font linking on result items (for multilingual support). See Remarks for details.

If *ppViewType* is a custom view type, the view options that affect the standard
list views are applied by MMC when the view is switched from a custom view to a standard list view.

## Return value

This method can return one of these values.

## Remarks

The callee (snap-in) allocates the view type string using COM API function
[CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and the caller (MMC) frees it using
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

MMC calls **GetResultViewType** when a
snap-in scope item is selected. When switching from a standard list view to a custom view, the snap-in must call
[IConsole2::SelectScopeItem](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814792(v=vs.85)) to reselect the item
and force MMC to call **GetResultViewType**
again. This enables the snap-in to specify the appropriate custom OCX or webpage so that MMC can load
it. When switching from a custom view to a standard list view, MMC automatically calls
**GetResultViewType** and sets the appropriate
list view type.

Given a Unicode string, the font linking feature determines the best font for that displays that string. For
example, if you were populating a list view with server names and knew that half would be in Japanese and half in
Russian, then you would set the font linking view options and MMC would determine an appropriate font. The default
is not to use font linking, because there is a small performance hit when MMC searches for the appropriate
font.

A [cookie](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/cookies) is a pointer to a structure that contains information
unique to a specific item. It is passed in through the **lParam** member of a
[SCOPEDATAITEM](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-scopedataitem) structure.

## See also

[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)