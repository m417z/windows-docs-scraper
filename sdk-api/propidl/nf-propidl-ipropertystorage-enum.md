# IPropertyStorage::Enum

## Description

The **Enum** method creates an enumerator object designed to enumerate data of type
[STATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropstg), which contains information on the current property set. On return, this method supplies a pointer to the
[IEnumSTATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ienumstatpropstg) pointer on this object.

## Parameters

### `ppenum` [out]

Pointer to
[IEnumSTATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ienumstatpropstg) pointer variable that receives the interface pointer to the new enumerator object.

## Return value

This method supports the standard return value E_UNEXPECTED, in addition to the following:

## Remarks

**IPropertyStorage::Enum** creates an enumeration object that can be used to iterate
[STATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropstg) structures. On return, this method supplies a pointer to an instance of the
[IEnumSTATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ienumstatpropstg) interface on this object, whose methods you can call to obtain information about the current property set.

## See also

[EnumAll Sample](https://learn.microsoft.com/windows/desktop/Stg/enumall-sample)

[IEnumSTATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ienumstatpropstg)

[IEnumSTATPROPSTG - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/ienumstatpropstg-compound-file-implementation)

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[Samples](https://learn.microsoft.com/windows/desktop/Stg/samples)