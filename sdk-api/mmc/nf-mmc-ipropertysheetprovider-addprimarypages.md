# IPropertySheetProvider::AddPrimaryPages

## Description

The **IPropertySheetProvider::AddPrimaryPages** method collects the pages from the primary snap-in.

## Parameters

### `lpUnknown` [in]

A pointer to snap-in interface that will be queried for the **IExtendPropertySheet** interface. If *bCreateHandle* is set to **TRUE**, this should also be a pointer to the snap-in's
[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent) or
[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata) interface that will be queried for **IExtendPropertySheet**. Be aware that this value can be **NULL**. See Remarks for details.

### `bCreateHandle` [in]

A value that specifies whether to create a console-provided notification handle that is used to route the [MMCN_PROPERTY_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-property-change) notification to the appropriate
**IComponent** or
**IComponentData** interface during calls to
[MMCPropertyChangeNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-mmcpropertychangenotify). The notification handle is passed back to the snap-in during calls to the snap-in's implementation of the
[IExtendPropertySheet2::CreatePropertyPages](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814847(v=vs.85)) method.

If *bCreateHandle* is set to **TRUE**, the *lpUnknown* parameter should be a pointer to the
**IComponent** or
**IComponentData** that receives the [MMCN_PROPERTY_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-property-change) notification.

### `hNotifyWindow` [in]

Reserved for future use. This value should be **NULL**.

### `bScopePane` [in]

Set to **TRUE** if the item is in the scope pane. Set to **FALSE** if it is in the result pane.

## Return value

This method can return one of these values.

## Remarks

The snap-in might not add any pages during this method call. If this is the case, extension pages should not be added.

## See also

[IPropertySheetProvider](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-ipropertysheetprovider)

[Using IPropertySheetProvider Directly](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-ipropertysheetprovider-directly)