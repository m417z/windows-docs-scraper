# IComponent2::RestoreResultView

## Description

The
**RestoreResultView** method restores the result view. This method enables a snap-in to restore snap-in-specific details of a result view. For more information, see
[Restoring Result Views](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/restoring-result-views).

This method supersedes the use of the
[MMCN_RESTORE_VIEW](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-restore-view) notification.

## Parameters

### `cookie` [in]

A value that specifies the unique identifier whose result view will be restored.

### `pResultViewType` [in]

A pointer to the
[RESULT_VIEW_TYPE_INFO](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-result_view_type_info) structure for the result view.

## Return value

If successful, the return value is S_OK. The snap-in can return S_FALSE to prevent MMC from restoring the view based on the information in **pResultViewType*. Other return values indicate an error code.

## Remarks

The **pstrPersistableViewDescription** member of **pResultViewType* specifies the name assigned to the result view. To restore the result view identified by the **pstrPersistableViewDescription** member, the snap-in fills in the remaining members of **pResultViewType*. The name of the result view is originally assigned during the snap-in's implementation of
[IComponent2::GetResultViewType2](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent2-getresultviewtype2). MMC calls **IComponent2::RestoreResultView** so that the snap-in can restore internal view settings when the result view is revisited by the user.

When the user customizes the view, some of the settings (such as view options or view mode) are known by MMC, and some (such as **Oldest First** in the Event Viewer snap-in) are internal to the snap-in. Prior to MMC 2.0, there was no mechanism for MMC to communicate to the snap-in to restore the internal view settings. The [IComponent2::GetResultViewType2](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent2-getresultviewtype2) and **IComponent2::RestoreResultView** methods in MMC 2.0, however, provide the mechanism whereby internal view settings are restored. The snap-in persists internal view settings against the **pstrPersistableViewDescription** member of the [RESULT_VIEW_TYPE_INFO](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-result_view_type_info) structure. When MMC calls **IComponent2::RestoreResultView** to restore the result view, the snap-in uses the persisted settings to complete the view restoration.

The user revisits the result view by pressing the MMC **Back/Forward** buttons or loading a saved console file.

## See also

[IComponent2::GetResultViewType2](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent2-getresultviewtype2)

[RESULT_VIEW_TYPE_INFO](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-result_view_type_info)

[Restoring Result Views](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/restoring-result-views)