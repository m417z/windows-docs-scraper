# IOleClientSite::SaveObject

## Description

Saves the embedded object associated with the client site. This function is synchronous; by the time it returns, the save will be completed.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation has failed. |

## Remarks

An embedded object calls **SaveObject** to ask its container to save it to persistent storage when an end user chooses the File Update or Exit commands. The call is synchronous, meaning that by the time it returns, the save operation will be completed.

Calls to **SaveObject** occur in most implementations of [IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close). Normally, when a container tells an object to close, the container passes a flag specifying whether the object should save itself before closing, prompt the user for instructions, or close without saving itself. If an object is instructed to save itself, either by its container or an end user, it calls **SaveObject** to ask the container application to save the object's contents before the object closes itself. If a container instructs an object not to save itself, the object should not call **SaveObject**.

## See also

[IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite)

[IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close)