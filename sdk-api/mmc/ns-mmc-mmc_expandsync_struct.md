# MMC_EXPANDSYNC_STRUCT structure

## Description

The
**MMC_EXPANDSYNC_STRUCT** structure is introduced in MMC 1.1.

The
**MMC_EXPANDSYNC_STRUCT** structure contains information about a scope item that must be expanded synchronously. MMC passes a pointer to an
**MMC_EXPANDSYNC_STRUCT** structure when it calls the snap-in's
[IComponentData::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponentdata-notify) method with the
[MMCN_EXPANDSYNC](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-expandsync) notification.

## Members

### `bHandled`

A value that specifies whether the snap-in has expanded the specified scope item. If this value is **TRUE**, the snap-in handles **MMC_EXPANDSYNC**, and consequently MMC does not send a further [MMCN_EXPAND](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-expand) notification to the snap-in.

The default value for **bHandled** is **FALSE**. If the snap-in does not handle **MMC_EXPANDSYNC** or sets **bHandled** to **FALSE**, MMC sends an [MMCN_EXPAND](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-expand) notification to the snap-in.

### `bExpanding`

A value that specifies whether the snap-in is expanding or collapsing. **TRUE** if the folder is being expanded. **FALSE** if the folder is being collapsed.

### `hItem`

The **HSCOPEITEM** of the item that must be expanded.

## Remarks

The [MMCN_EXPANDSYNC](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-expandsync) notification is sent by MMC when it requires a scope item to be synchronously expanded. Normally, this occurs when a console file is reloaded with a scope item expanded. For more information about handling this notification, see
**MMCN_EXPANDSYNC**.

## See also

[IComponentData::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponentdata-notify)

[IConsoleNameSpace2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace2)

[MMCN_EXPAND](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-expand)

[MMCN_EXPANDSYNC](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-expandsync)