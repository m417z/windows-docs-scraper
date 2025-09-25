# IPropertyStorage::Commit

## Description

The **IPropertyStorage::Commit** method saves changes made to a property storage object to the parent storage object.

## Parameters

### `grfCommitFlags` [in]

The flags that specify the conditions under which the commit is to be performed. For more information about specific flags and their meanings, see the Remarks section.

## Return value

This method supports the standard return value E_UNEXPECTED, as well as the following:

## Remarks

Like [IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit), the **IPropertyStorage::Commit** method ensures that any changes made to a property storage object are reflected in the parent storage.

In direct mode in the compound file implementation, a call to this method causes any changes currently in the memory buffers to be flushed to the underlying property stream. In the compound-file implementation for nonsimple property sets,
[IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit) is also called on the underlying substorage object with the passed *grfCommitFlags* parameter.

In transacted mode, this method causes the changes to be permanently reflected in the persistent image of the storage object. The changes that are committed must have been made to this property set since it was opened or since the last commit on this opening of the property set. The **commit** method publishes the changes made on one object level to the next level. Of course, this remains subject to any outer-level transaction that may be present on the object in which this property set is contained. Write permission must be specified when the property set is opened (through
[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage)) on the property set opening for the commit operation to succeed.

If the commit operation fails for any reason, the state of the property storage object remains as it was before the commit.

This call has no effect on existing storage- or stream-valued properties opened from this property storage, but it does commit them.

Valid values for the *grfCommitFlags* parameter are listed in the following table.

| Value | Meaning |
| --- | --- |
| STGC_DEFAULT | Commits per the usual transaction semantics. Last writer wins. This flag may not be specified with other flag values. |
| STGC_ONLYIFCURRENT | Commits the changes only if the current persistent contents of the property set are the ones on which the changes about to be committed are based. That is, does not commit changes if the contents of the property set have been changed by a commit from another opening of the property set. The error STG_E_NOTCURRENT is returned if the commit does not succeed for this reason. |
| STGC_OVERWRITE | Useful only when committing a transaction that has no further outer nesting level of transactions, though acceptable in all cases.<br><br>**Note** Indicates that the caller is willing to risk some data corruption at the expense of decreased disk usage on the destination volume. This flag is potentially useful in low disk-space scenarios, though it should be used with caution. |

**Note** Using **IPropertyStorage::Commit** to write properties to image files on Windows XP does not work. Affected image file formats include:

* .bmp
* .dib
* .emf
* .gif
* .ico
* .jfif
* .jpe
* .jpeg
* .jpg
* .png
* .rle
* .tiff
* .wmf

Due to a bug in the image file property handler on Windows XP, calling **IPropertyStorage::Commit** actually discards any changes made rather than persisting them.

A workaround is to

omit the call to **IPropertyStorage::Commit**. Calling IUnknown::Release on the XP image file property handler without calling **IPropertyStorage::Commit** first implicitly commits the changes to the file. Note that in general, calling IUnknown::Release without first calling **IPropertyStorage::Commit** will discard any changes made; this workaround is specific to the image file property handler on Windows XP. Also note that on later versions of Windows, this component functions properly (that is, calling **IPropertyStorage::Commit** persists changes and calling IUnknown::Release without calling **IPropertyStorage::Commit** discards them).

## See also

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[IPropertyStorage::ReadMultiple](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-readmultiple)

[IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit)