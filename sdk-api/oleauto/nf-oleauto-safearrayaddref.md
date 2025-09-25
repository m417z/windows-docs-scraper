# SafeArrayAddRef function

## Description

**Note** You should only call **SafeArrayAddRef** if you are implementing a scripting engine that needs to guard against running potentially malicious scripts.

Increases the pinning reference count of the descriptor for the specified safe array by one, and may increase the pinning reference count of the data for the specified safe array by one if that data was dynamically allocated, as determined by the descriptor of the safe array.

## Parameters

### `psa` [in]

The safe array for which the pinning reference count of the descriptor should increase. While that count remains greater than 0, the memory for the descriptor is prevented from being freed by calls to the [SafeArrayDestroy](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-safearraydestroy) or [SafeArrayDestroyDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraydestroydescriptor) functions.

### `ppDataToRelease` [out]

Returns the safe array data for which a pinning reference was added, if **SafeArrayAddRef** also added a pinning reference for the safe array data. This parameter is NULL if **SafeArrayAddRef** did not add a pinning reference for the safe array data. **SafeArrayAddRef** does not add a pinning reference for the safe array data if that safe array data was not dynamically allocated.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Safe arrays have not traditionally had a reference count. All existing usage of safe arrays will continue to work with no changes. The **SafeArrayAddRef**, [SafeArrayReleaseData](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayreleasedata), [SafeArrayReleaseDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayreleasedescriptor) functions add the ability to use reference counting to pin the safe array into memory before calling from an untrusted script into an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) method that may not expect the script to free that memory before the method returns, so that the script cannot force the code for that method into accessing memory that has been freed. After such a method safely returns, the pinning references should be released. You can release the pinning references by calling the following functions:

* [SafeArrayReleaseData](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayreleasedata), for the data that the *ppDataToRelease* parameter points to, if it is not null.
* [SafeArrayReleaseDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayreleasedescriptor), for the descriptor that the *psa* parameter specifies.

## See also

[SafeArrayReleaseData](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayreleasedata)

[SafeArrayReleaseDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayreleasedescriptor)