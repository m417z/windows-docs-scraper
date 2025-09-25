# IS_SPECIAL_DATAOBJECT macro

## Description

The
**IS_SPECIAL_DATAOBJECT** macro determines whether an **LPDATAOBJECT** passed by MMC in a call to the snap-in's
Notify method is a special type of data object instead of a pointer to an actual
[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) object.

## Parameters

### `d`

A value of type **LPDATAOBJECT** to be evaluated.

## Remarks

MMC can pass **DOBJ_CUSTOMOCX** or **DOBJ_CUSTOMWEB** as the data object in the following methods with the following notifications:

* [IExtendControlbar::ControlbarNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendcontrolbar-controlbarnotify)

  [MMCN_BTN_CLICK](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-btn-click)
* [IComponent::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-notify)

  [MMCN_BTN_CLICK](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-btn-click) with *param* set to **MMC_VERB_PROPERTIES**

  [MMCN_DELETE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-delete)

  [MMCN_PASTE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-paste)

  [MMCN_PRINT](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-print)

  [MMCN_REFRESH](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-refresh)

If you have custom views (webpage, custom OCX, or taskpad), you can use this macro to verify that the notifications listed above pass a pointer to a data object or one of the special values, and then handle them appropriately.