# MMCFreeNotifyHandle function

## Description

The
MMCFreeNotifyHandle function is called by a snap-in to free the handle to an
[MMCN_PROPERTY_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-property-change) notification message sent to the snap-in by MMC in response to an
[MMCPropertyChangeNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-mmcpropertychangenotify) call made by a property sheet.

## Parameters

### `lNotifyHandle` [in]

A value that specifies a handle provided by the console during an
[IExtendPropertySheet2::CreatePropertyPages](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814847(v=vs.85)) call.

## Return value

This callback function can return one of these values.

## Remarks

The handle to the notification is passed to the snap-in through a call to the
[IExtendPropertySheet2::CreatePropertyPages](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814847(v=vs.85)) method. If the snap-in returns a success code (S_OK, S_FALSE) from this method, then the snap-in must call
*MMCFreeNotifyHandle*. If the snap-in returns an error code, then MMC immediately frees the handle.

The snap-in can free the handle at any time, because MMC does not use the handle after it is given to the snap-in. The snap-in must only call
*MMCFreeNotifyHandle* once and it must not use the handle in an
[MMCPropertyChangeNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-mmcpropertychangenotify) call after it is freed.

Be aware that the snap-in only must call
*MMCFreeNotifyHandle* if its
[IExtendPropertySheet2::CreatePropertyPages](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814847(v=vs.85)) method is called. MMC will not call **IExtendPropertySheet2::CreatePropertyPages** if the snap-in uses
[IPropertySheetCallback](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-ipropertysheetcallback) to add property pages and then calls [IPropertySheetProvider::AddPrimaryPages](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ipropertysheetprovider-addprimarypages) with a **NULL** first parameter. Calling
AddPrimaryPages in this way informs MMC that the pages have already been added, so it is not required to call the snap-in's **IExtendPropertySheet2::CreatePropertyPages** method. For more information, see
[Adding Wizard Pages: Implementation Details](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/adding-wizard-pages-implementation-details).

The following list contains scenarios that illustrate situations in which the snap-in can call
*MMCFreeNotifyHandle*:

* In [IExtendPropertySheet2::CreatePropertyPages](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814847(v=vs.85)), the snap-in does not add any property pages. If
  CreatePropertyPages does not return an error result, the snap-in can call
  MMCFreeNotifyHandle before returning. Otherwise, MMC will free the handle.
* In [IExtendPropertySheet2::CreatePropertyPages](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814847(v=vs.85)), the snap-in adds property pages, but does not pass the handle to the pages. Again, if
  CreatePropertyPages does not return an error result, the snap-in can call
  MMCFreeNotifyHandle before returning.
* In [IExtendPropertySheet2::CreatePropertyPages](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814847(v=vs.85)), the snap-in adds property pages and also passes the handle to the pages. However, the property pages do not call
  [MMCPropertyChangeNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-mmcpropertychangenotify). In this case, the snap-in can call
  *MMCFreeNotifyHandle* either in the destructor of the property pages or before returning (without an error result) from
  CreatePropertyPages.
* In [IExtendPropertySheet2::CreatePropertyPages](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814847(v=vs.85)), the snap-in adds property pages and also passes the handle to the pages. The property pages call
  [MMCPropertyChangeNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-mmcpropertychangenotify). In this case, the snap-in should call
  *MMCFreeNotifyHandle* in the destructor of the property pages. Be aware that calling
  *MMCFreeNotifyHandle* in the snap-in's [MMCN_PROPERTY_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-property-change) notification handler is not recommended, because multiple pages may send notifications, or the same page could send multiple notifications (one each time the user clicks the **Apply** button).

## See also

[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent)

[IExtendPropertySheet2::CreatePropertyPages](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814847(v=vs.85))

[MMCPropertyChangeNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-mmcpropertychangenotify)