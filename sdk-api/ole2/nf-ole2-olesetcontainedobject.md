# OleSetContainedObject function

## Description

Notifies an object that it is embedded in an OLE container, which ensures that reference counting is done correctly for containers that support links to embedded objects.

## Parameters

### `pUnknown` [in]

Pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the object.

### `fContained` [in]

**TRUE** if the object is an embedded object; **FALSE** otherwise.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory for the operation. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_UNEXPECTED** | An unexpected error occurred. |

## Remarks

The **OleSetContainedObject** function notifies an object that it is embedded in an OLE container. The implementation of **OleSetContainedObject** was changed in OLE 2.01 to coincide with the publication of the [IRunnableObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunnableobject) interface. You can use **OleSetContainedObject** and the [IRunnableObject::SetContainedObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunnableobject-setcontainedobject) method interchangeably. The **OleSetContainedObject** function queries the object for a pointer to the **IRunnableObject** interface. If successful, the function returns the results of calling **IRunnableObject::SetContainedObject**.

## See also

[IRunnableObject::SetContainedObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunnableobject-setcontainedobject)