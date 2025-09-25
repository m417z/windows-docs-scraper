# IPersistStorage::SaveCompleted

## Description

Notifies the object that it can write to its storage object. It does this by notifying the object that it can revert from NoScribble mode (in which it must not write to its storage object), to Normal mode (in which it can). The object enters NoScribble mode when it receives an [IPersistStorage::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-save) call.

## Parameters

### `pStgNew` [in]

An [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to the new storage object, if different from the storage object prior to saving. This pointer can be **NULL** if the current storage object does not change during the save operation. If the object is in HandsOff mode, this parameter must be non-**NULL**.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_OUTOFMEMORY** | The object remained in HandsOff mode or NoScribble mode due to a lack of memory. Typically, this error occurs when the object is not able to open the necessary streams and storage objects in *pStgNew*. |
| **E_INVALIDARG** | The *pStgNew* parameter is not valid. Typically, this error occurs if *pStgNew* is **NULL** when the object is in HandsOff mode. |
| **E_UNEXPECTED** | The object is in Normal mode, and there was no previous call to [IPersistStorage::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-save) or [IPersistStorage::HandsOffStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-handsoffstorage). |

## Remarks

This method notifies an object that it can revert to Normal mode and can once again write to its storage object. The object exits NoScribble mode or HandsOff mode.

If the object is reverting from HandsOff mode, the pStgNew parameter must be non-**NULL**. In HandsOffFromNormal mode, this parameter is the new storage object that replaces the one that was revoked by the [IPersistStorage::HandsOffStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-handsoffstorage) method. The data in the storage object is a copy of the data from the revoked storage object. In HandsOffAfterSave mode, the data is the same as the data that was most recently saved. It is not the same as the data in the revoked storage object.

If the object is reverting from NoScribble mode, the *pStgNew* parameter can be **NULL** or non-**NULL**. If **NULL**, the object once again has access to its storage object. If it is not **NULL**, the component object should simulate receiving a call to its [HandsOffStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-handsoffstorage) method. If the component object cannot simulate this call, its container must be prepared to actually call the **HandsOffStorage** method.

This method must recursively call any nested objects that are loaded or running.

If this method returns an error code, the object is not returned to Normal mode. Thus, the container object can attempt different save strategies.

## See also

[IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage)