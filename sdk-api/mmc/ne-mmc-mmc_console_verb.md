# MMC_CONSOLE_VERB enumeration

## Description

The
**MMC_CONSOLE_VERB** enumeration defines the command identifiers available for MMC verbs. These values are used in the *m_eCmdID* parameter of
[IConsoleVerb::GetVerbState](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsoleverb-getverbstate),
[IConsoleVerb::SetVerbState](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsoleverb-setverbstate), and
[IConsoleVerb::SetDefaultVerb](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsoleverb-setdefaultverb).

## Constants

### `MMC_VERB_NONE:0x0000`

No verbs specified. Snap-ins can use this verb in calls to
[IConsoleVerb::SetDefaultVerb](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsoleverb-setdefaultverb) to specify that the selected item does not have a default verb.

### `MMC_VERB_OPEN:0x8000`

Allows the selected item to be opened.

### `MMC_VERB_COPY:0x8001`

Allows the selected item to be copied to the clipboard. When the user activates this verb, MMC calls the snap-in's [IComponentData::QueryDataObject](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponentdata-querydataobject) or [IComponent::QueryDataObject](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-querydataobject) implementation to request a data object for the selected item.

### `MMC_VERB_PASTE:0x8002`

Allows the selected item that has been cut or copied to be pasted into the result pane. When the user activates this verb, MMC sends the snap-in's [IComponent::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-notify) method a [MMCN_QUERY_PASTE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-query-paste) notification message.

### `MMC_VERB_DELETE:0x8003`

Allows the selected item to be deleted. When the user activates this verb, MMC sends the snap-in's [IComponent::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-notify) method a [MMCN_DELETE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-delete) notification message.

### `MMC_VERB_PROPERTIES:0x8004`

The console instructs the snap-in and all snap-in extensions to provide property pages for the currently selected item. When the user activates this verb, MMC calls the [IExtendPropertySheet2::CreatePropertyPages](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814847(v=vs.85)) method of all snap-ins (primary and extension) that add property pages for the selected item.

Be aware that primary snap-ins are responsible for enabling the **MMC_VERB_PROPERTIES** verb. Extensions snap-ins cannot do this, because they do not own the item for which the verb is enabled.

### `MMC_VERB_RENAME:0x8005`

Allows the selected item to be renamed. When the user activates this verb, MMC sends the snap-in's [IComponent::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-notify) or [IComponentData::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponentdata-notify) method a [MMCN_RENAME](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-rename) notification message.

### `MMC_VERB_REFRESH:0x8006`

Determines whether the currently selected scope item (folder) can be refreshed. When the user activates this verb, MMC sends the snap-in's [IComponent::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-notify) a [MMCN_REFRESH](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-refresh) notification message.

### `MMC_VERB_PRINT:0x8007`

Determines whether the currently selected item can be printed. When the user activates this verb, MMC sends the snap-in's [IComponent::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-notify) a [MMCN_PRINT](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-print) notification message.

### `MMC_VERB_CUT:0x8008`

(Applies to MMC 1.1 and later.) Used only to explicitly disable or hide the cut verb, when the copy and paste verbs are enabled. When the user activates this verb, MMC calls the snap-in's [IComponentData::QueryDataObject](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponentdata-querydataobject) or [IComponent::QueryDataObject](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-querydataobject) implementation to request a data object for the cut item.

### `MMC_VERB_MAX`

### `MMC_VERB_FIRST`

### `MMC_VERB_LAST`