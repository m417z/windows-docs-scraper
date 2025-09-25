# IFsrmCommittableCollection::Commit

## Description

Commits all the objects of the collection and returns the commit results for each
object.

## Parameters

### `options` [in]

One or more options to use when committing the collection of objects. For possible values, see the
[FsrmCommitOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmcommitoptions) enumeration.

### `results` [out]

A collection of **HRESULT** values that correspond directly to the objects in the
collection. The **HRESULT** value indicates the success or failure of committing the
object.

If the method returns **FSRM_S_PARTIAL_BATCH** or
**FSRM_E_FAIL_BATCH**, check the results.

## Return value

The method returns the following return values.

## Remarks

Committing objects in a batch operation provides better performance than committing each object in the
collection individually (for example, calling the
[IFsrmFileScreen::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit) method).

Note that the state of the objects in the collection must be the same. For example, the collection must
contain all new objects, objects marked for deletion, or modified objects. The modified category covers objects
are not new or marked for deletion—it does not necessarily mean that they've been
modified.

A collection of imported objects would be considered a collection of modified objects. If you marked one or
more of the imported objects for deletion (called the
[Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-delete) method on the object), you would first have to
[remove](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmmutablecollection-remove) those objects from the collection before
committing the rest.

## See also

[IFsrmCommittableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcommittablecollection)