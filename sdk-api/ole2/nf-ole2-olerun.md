# OleRun function

## Description

Puts an OLE compound document object into the running state.

## Parameters

### `pUnknown` [in]

Pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the object, with which it will query for a pointer to the [IRunnableObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunnableobject) interface, and then call its [Run](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunnableobject-run) method.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_CLASSDIFF** | The source of an OLE link has been converted to a different class. |

## Remarks

The **OleRun** function puts an object in the running state. The implementation of **OleRun** was changed in OLE 2.01 to coincide with the publication of the [IRunnableObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunnableobject) interface. You can use **OleRun** and [IRunnableObject::Run](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunnableobject-run) interchangeably. **OleRun** queries the object for a pointer to **IRunnableObject**. If successful, the function returns the results of calling the **IRunnableObject::Run** method.

For more information on using this function, see [IRunnableObject::Run](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunnableobject-run).

## See also

[IOleLink::BindToSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-bindtosource)

[IRunnableObject::Run](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunnableobject-run)