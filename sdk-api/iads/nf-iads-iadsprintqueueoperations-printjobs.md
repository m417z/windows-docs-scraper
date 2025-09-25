# IADsPrintQueueOperations::PrintJobs

## Description

The **IADsPrintQueueOperations::PrintJobs** method gets an [IADsCollection](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscollection) interface pointer on the collection of the print jobs processed in this print queue. This collection can be enumerated using the standard Automation enumeration methods on [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant). To delete a print job, use the [IADsCollection::Remove](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadscollection-remove) method on the retrieved interface pointer.

## Parameters

### `pObject` [out]

Pointer to a pointer to the [IADsCollection](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscollection) interface on the collection of objects added to this print queue. Objects in the collection implement the [IADsPrintJob](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsprintjob) interface.

## Return value

This method supports the standard return values. For more information about other return values, see the [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## See also

[ADsEnumerateNext](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsenumeratenext)

[IADsCollection](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscollection)

[IADsCollection::Remove](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadscollection-remove)

[IADsPrintJob](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsprintjob)

[IADsPrintJob Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadsprintjob-property-methods)

[IADsPrintQueueOperations](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsprintqueueoperations)

[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant)