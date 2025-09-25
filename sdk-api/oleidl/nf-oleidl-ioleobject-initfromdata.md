# IOleObject::InitFromData

## Description

Initializes a newly created object with data from a specified data object, which can reside either in the same container or on the Clipboard.

## Parameters

### `pDataObject` [in]

Pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data object from which the initialization data is to be obtained. This parameter can be **NULL**, which indicates that the caller wants to know if it is worthwhile trying to send data; that is, whether the container is capable of initializing an object from data passed to it. The data object to be passed can be based on either the current selection within the container document or on data transferred to the container from an external source.

### `fCreation` [in]

**TRUE** indicates the container is inserting a new object inside itself and initializing that object with data from the current selection; **FALSE** indicates a more general programmatic data transfer, most likely from a source other than the current selection.

### `dwReserved` [in]

This parameter is reserved and must be zero.

## Return value

This method returns S_OK if *pDataObject* is not **NULL**, the object successfully attempted to initialize itself from the provided data; if *pDataObject* is **NULL**, the object is able to attempt a successful initialization.. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | If pDataObject is not **NULL**, the object made no attempt to initialize itself; if *pDataObject* is **NULL**, the object cannot attempt to initialize itself from the data provided. |
| **E_NOTIMPL** | The object does not support *InitFromData*. |
| **OLE_E_NOTRUNNING** | The object is not running and therefore cannot perform the operation. |

## Remarks

This method enables a container document to insert within itself a new object whose content is based on a current data selection within the container. For example, a spreadsheet document may want to create a graph object based on data in a selected range of cells.

Using this method, a container can also replace the contents of an embedded object with data transferred from another source. This provides a convenient way of updating an embedded object.

### Notes to Callers

Following initialization, the container should call [IOleObject::GetMiscStatus](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmiscstatus) to check the value of the OLEMISC_INSERTNOTREPLACE bit. If the bit is on, the new object inserts itself following the selected data. If the bit is off, the new object replaces the selected data.

### Notes to Implementers

A container specifies whether to base a new object on the current selection by passing either **TRUE** or **FALSE** to the *fCreation* parameter.

If *fCreation* is **TRUE**, the container is attempting to create a new instance of an object, initializing it with the selected data specified by the data object.

If *fCreation* is **FALSE**, the caller is attempting to replace the object's current contents with that pointed to by *pDataObject*. The usual constraints that apply to an object during a paste operation should be applied here. For example, if the type of the data provided is unacceptable, the object should fail to initialize and return S_FALSE.

If the object returns S_FALSE, it cannot initialize itself from the provided data.

## See also

[IDataObject::SetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-setdata)

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::GetMiscStatus](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmiscstatus)