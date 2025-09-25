# RESULT_VIEW_TYPE_INFO structure

## Description

The **RESULT_VIEW_TYPE_INFO** structure is introduced in MMC 2.0.

The **RESULT_VIEW_TYPE_INFO** structure is used in calls to
[IComponent2::GetResultViewType2](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent2-getresultviewtype2) and
[IComponent2::RestoreResultView](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent2-restoreresultview). A snap-in uses these two methods to include a result view in the navigational order maintained by MMC's
**Back**/**Forward** buttons.

## Members

### `pstrPersistableViewDescription`

Snap-in-provided identifier for this view type. When implementing [IComponent2::GetResultViewType2](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent2-getresultviewtype2), this member must contain a valid view description string; otherwise, MMC will not initialize your snap-in. Additionally, this value must be created by means of [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). It will be freed by MMC, not the snap-in.

### `eViewType`

[MMC_VIEW_TYPE](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_view_type) enumeration value specifying the view type. This member is the structure's union discriminator and determines which members of the union are valid. This member is one of the following values.

#### MMC_VIEW_TYPE_LIST

This view is a list view.

#### MMC_VIEW_TYPE_HTML

This view is an HTML view.

#### MMC_VIEW_TYPE_OCX

This view is an OCX (ActiveX control) view.

### `dwMiscOptions`

A value that specifies whether the view contains list views. If this value is **RVTI_MISC_OPTIONS_NOLISTVIEWS**, no list views are contained in the view (the console refrains from presenting standard list view choices on the **View** menu). Otherwise, this value is zero.

### `dwListOptions`

A value that specifies the list view options. Applies only when the **eViewType** member is **MMC_VIEW_TYPE_LIST**. This value can be one or more of the following values.

#### RVTI_LIST_OPTIONS_NONE

No view options selected. This is the default view option.

#### RVTI_LIST_OPTIONS_OWNERDATALIST

A value that specifies that the result pane list view should be a virtual list.

#### RVTI_LIST_OPTIONS_MULTISELECT

Allows multiple item selections in the result pane view.

#### RVTI_LIST_OPTIONS_FILTERED

Notifies MMC that the snap-in supports filtered views. See [Adding Filtered Views](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/adding-filtered-views).

#### RVTI_LIST_OPTIONS_USEFONTLINKING

Uses font linking on result items (for multilingual support). Font linking is a feature installed on systems with Microsoft Internet Explorer version 4.0 or later. Given a Unicode string, the font linking feature determines the best font for that displays that string. For example, to populate a list view with server names in both Japanese and Russian, you would set the font linking view options, and MMC would determine an appropriate font. In the default setting, font linking is not enabled because it can cause a short delay while MMC searches for the appropriate font.

#### RVTI_LIST_OPTIONS_EXCLUDE_SCOPE_ITEMS_FROM_LIST

Causes MMC to hide scope items in the view; this applies to standard list views. Scope items are hidden in virtual list views.

#### RVTI_LIST_OPTIONS_LEXICAL_SORT

Causes MMC to lexically sort all scope items (including extensions) first, followed by all result items; this applies to standard list views. The [IResultDataCompare](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdatacompare) and [IResultDataCompareEx](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdatacompareex) interfaces are ignored when this value is set.

#### RVTI_LIST_OPTIONS_ALLOWPASTE

Informs MMC that the result pane item is a drop target (see [Using Drag and Drop to Result Pane Items](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-drag-and-drop-to-result-pane-items)).

### `dwHTMLOptions`

Applies only when **eViewType** is **MMC_VIEW_TYPE_HTML**. This value is reserved for future use and must be zero.

### `pstrURL`

The URL for the HTML view. This parameter applies only when the **eViewType** member is **MMC_VIEW_TYPE_HTML**.

### `dwOCXOptions`

Applies only when the **eViewType** member is **MMC_VIEW_TYPE_OCX**. This value can be one or more of the following values.

**Note** Once the OCX caching option has been set (either by using or not using the **RVTI_OCX_OPTIONS_CACHE_OCX** flag), the option choice for this instance of the snap-in must not be changed.

#### RVTI_OCX_OPTIONS_NONE

No options are specified for the OCX view.

#### RVTI_OCX_OPTIONS_NOLISTVIEW

There is no list view in the OCX view.

#### RVTI_OCX_OPTIONS_CACHE_OCX

MMC will cache the OCX. If this value is specified, then the snap-in should maintain the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer for the OCX, so that if MMC calls [IComponent2::GetResultViewType2](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent2-getresultviewtype2) again, the snap-in returns the **IUnknown** pointer. MMC then identifies the cached OCX and reuses it.
Be aware that OCXs are cached for each [IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent) object, so the snap-in should create a different OCX for each **IComponent** object even if **RVTI_OCX_OPTIONS_CACHE_OCX** is set.

### `pUnkControl`

The [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer for the OCX. This parameter applies only when the **eViewType** member is **MMC_VIEW_TYPE_OCX**. When a snap-in implements [IComponent2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent2) and has an OCX in the result pane, the snap-in must create the OCX during the call to [IComponent2::GetResultViewType2](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent2-getresultviewtype2) and return the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer (through **pUnkControl**) to MMC. The snap-in must also initialize the OCX. MMC will not send a [MMCN_INITOCX](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-initocx) notification to the snap-in.

## See also

[IComponent2::GetResultViewType2](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent2-getresultviewtype2)

[IComponent2::RestoreResultView](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent2-restoreresultview)

[Restoring Result Views](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/restoring-result-views)

[Using Drag and Drop to Result Pane Items](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-drag-and-drop-to-result-pane-items)