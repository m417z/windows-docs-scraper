# IComponent2::GetResultViewType2

## Description

The
**GetResultViewType2** method retrieves the result view type. This method supersedes the
[IComponent::GetResultViewType](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-getresultviewtype) method.

## Parameters

### `cookie` [in]

A value that specifies the snapin-provided unique identifier for the scope item. For more details about cookies in MMC, see [Cookies](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/cookies).

### `pResultViewType` [in, out]

A pointer to the
[RESULT_VIEW_TYPE_INFO](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-result_view_type_info) structure for the result view. If your snap-in implements
[IComponent2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent2), the **pstrPersistableViewDescription** member of the **RESULT_VIEW_TYPE_INFO** structure must contain a valid view description string; otherwise, MMC will not initialize your snap-in. The **pstrPersistableViewDescription** member must be allocated by
[CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). The snap-in must not free **pstrPersistableViewDescription**, as it will be freed by MMC.

## Return value

If successful, the return value is S_OK. Other return values indicate an error code.

## Remarks

During result view creation, MMC calls the snap-in's **IComponent2::GetResultViewType2** method. When the user revisits the result view named by the **pstrPersistableViewDescription** member of **pResultViewType*, MMC will call the snap-in's
[IComponent2::RestoreResultView](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent2-restoreresultview) method, at which time the snap-in can provide snap-in-specific details (if any) for the restored result view. The user revisits the result view by means of the MMC **Back/Forward** buttons or the loading of a saved console file. For more information about the use of the **IComponent2::GetResultViewType2** and **IComponent2::RestoreResultView** methods, see
[Restoring Result Views](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/restoring-result-views).

If the snap-in is implementing an OCX (ActiveX control) view, then the snap-in creates the OCX and provides MMC with the OCX
[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer in the [RESULT_VIEW_TYPE_INFO](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-result_view_type_info) structure (specifically, the structure's **pUnkControl** member). The snap-in has control over the OCX creation, so the snap-in can address licensing or security issues as required. During the call to
**GetResultViewType2**, the snap-in can also initialize the OCX (the snap-in will not receive a [MMCN_INITOCX](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-initocx) notification).

## See also

[IComponent2::RestoreResultView](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent2-restoreresultview)

[RESULT_VIEW_TYPE_INFO](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-result_view_type_info)

[Restoring Result Views](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/restoring-result-views)