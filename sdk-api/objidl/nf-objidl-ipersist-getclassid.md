# IPersist::GetClassID

## Description

Retrieves the class identifier (CLSID) of the object.

## Parameters

### `pClassID` [out]

A pointer to the location that receives the CLSID on return. The CLSID is a globally unique identifier (GUID) that uniquely represents an object class that defines the code that can manipulate the object's data.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## Remarks

The **GetClassID** method retrieves the class identifier (CLSID) for an object, used in later operations to load object-specific code into the caller's context.

### Notes to Callers

A container application might call this method to retrieve the original CLSID of an object that it is treating as a different class. Such a call would be necessary if a user performed an editing operation that required the object to be saved. If the container were to save it using the treat-as CLSID, the original application would no longer be able to edit the object. Typically, in this case, the container calls the [OleSave](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesave) helper function, which performs all the necessary steps. For this reason, most container applications have no need to call this method directly.

The exception would be a container that provides an object handler for certain objects. In particular, a container application should not get an object's CLSID and then use it to retrieve class specific information from the registry. Instead, the container should use [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject) and [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interfaces to retrieve such class-specific information directly from the object.

### Notes to Implementers

Typically, implementations of this method simply supply a constant CLSID for an object. If, however, the object's **[TreatAs](https://learn.microsoft.com/windows/desktop/com/treatas)** registry key has been set by an application that supports emulation (and so is treating the object as one of a different class), a call to **GetClassID** must supply the CLSID specified in the **[TreatAs](https://learn.microsoft.com/windows/desktop/com/treatas)** key. For more information on emulation, see [CoTreatAsClass](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cotreatasclass).

When an object is in the running state, the default handler calls an implementation of **GetClassID** that delegates the call to the implementation in the object. When the object is not running, the default handler instead calls the [ReadClassStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-readclassstg) function to read the CLSID that is saved in the object's storage.

If you are writing a custom object handler for your object, you might want to simply delegate this method to the default handler implementation (see [OleCreateDefaultHandler](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatedefaulthandler)).

### URL Moniker Notes

This method returns CLSID_StdURLMoniker.

## See also

[IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter)

[IPersist](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersist)

[IPersistFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipersistfolder)