# CreateOleAdviseHolder function

## Description

Creates an advise holder object for managing compound document notifications. It returns a pointer to the object's OLE implementation of the [IOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleadviseholder) interface.

## Parameters

### `ppOAHolder` [out]

Address of [IOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleadviseholder) pointer variable that receives the interface pointer to the new advise holder object.

## Return value

This function returns S_OK on success and supports the standard return value E_OUTOFMEMORY.

## Remarks

The function **CreateOleAdviseHolder** creates an instance of an advise holder, which supports the OLE implementation of the [IOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleadviseholder) interface. The methods of this interface are intended to be used to implement the advisory methods of [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject), and, when advisory connections have been set up with objects supporting an advisory sink, to send notifications of changes in the object to the advisory sink. The advise holder returned by **CreateOleAdviseHolder** will suffice for the great majority of applications. The OLE-provided implementation does not, however, support [IOleAdviseHolder::EnumAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-enumadvise), so if you need to use this method, you will need to implement your own advise holder.

## See also

[IOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleadviseholder)

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)