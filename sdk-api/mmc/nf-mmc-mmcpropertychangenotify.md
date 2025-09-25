# MMCPropertyChangeNotify function

## Description

The
MMCPropertyChangeNotify function enables a snap-in property sheet to notify its
[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent) or
[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata) interface that an item's properties have changed.

Property sheets run in a different thread than their
IComponent and
IComponentData server; therefore, if *param* is a COM interface pointer, it must be marshaled. Asynchronously calling this function notifies the
IComponent or the
IComponentData associated with the property page whose properties have changed.

## Parameters

### `lNotifyHandle` [in]

A value that specifies the handle used to route the notification message to the appropriate
[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent) or
[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata).

### `param` [in]

User-defined. Can be used freely.

## Return value

This callback function can return one of these values.

## Remarks

This is the handle passed to [IExtendPropertySheet2::CreatePropertyPages](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814847(v=vs.85)).

A call to
*MMCPropertyChangeNotify* causes an [MMCN_PROPERTY_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-property-change) notification to be sent to the snap-in.

The *param* value that is passed to
*MMCPropertyChangeNotify* is, in turn, forwarded to the snap-in as the *param* argument to MMCN_PROPERTY_CHANGE.

## See also

[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent)

[IExtendPropertySheet2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendpropertysheet2)

[MMCFreeNotifyHandle](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-mmcfreenotifyhandle)