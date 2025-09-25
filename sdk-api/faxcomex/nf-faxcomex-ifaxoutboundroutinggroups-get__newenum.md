# IFaxOutboundRoutingGroups::get__NewEnum

## Description

The **IFaxOutboundRoutingGroups::get__NewEnum** method returns a reference to an enumerator object that you can use to iterate through the [FaxOutboundRoutingGroups](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutinggroups) collection.

## Parameters

### `ppUnk` [out, retval]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

Receives an indirect pointer to the enumerator object's [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface for this collection.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFaxOutboundRoutingGroups](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutinggroups)