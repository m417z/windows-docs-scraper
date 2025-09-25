# IPersistStorage::HandsOffStorage

## Description

Instructs the object to release all storage objects that have been passed to it by its container and to enter HandsOff mode.

## Return value

This method returns S_OK to indicate that the object has entered HandsOff mode successfully.

## Remarks

This method causes an object to release any storage objects that it is holding and to enter the HandsOff mode until a subsequent [IPersistStorage::SaveCompleted](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-savecompleted) call. In HandsOff mode, the object cannot do anything and the only operation that works is a close operation.

A container application typically calls this method during a full save or low-memory full save operation to force the object to release all pointers to its current storage. In these scenarios, the **HandsOffStorage** call comes after a call to either [OleSave](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesave) or [IPersistStorage::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-save), putting the object in HandsOffAfterSave mode. Calling this method is necessary so the container application can delete the current file as part of a full save, or so it can call the [IRootStorage::SwitchToFile](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irootstorage-switchtofile) method as part of a low-memory save.

A container application also calls this method when an object is in Normal mode to put the object in HandsOffFromNormal mode.

While the component object is in either HandsOffAfterSave or HandsOffFromNormal mode, most operations on the object will fail. Thus, the container should restore the object to Normal mode as soon as possible. The container application does this by calling the [IPersistStorage::SaveCompleted](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-savecompleted) method, which passes a storage pointer back to the component object for the new storage object.

### Notes to Implementers

This method must release all pointers to the current storage object, including pointers to any nested streams and storages. If the object contains nested objects, the container application must recursively call this method for any nested objects that are loaded or running.

## See also

[IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage)

[OleSave](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesave)