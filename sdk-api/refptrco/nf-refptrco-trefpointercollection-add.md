# TRefPointerCollection::Add

## Description

[The [TRefPointerCollection](https://learn.microsoft.com/windows/desktop/api/refptrco/nl-refptrco-trefpointercollection) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **Add** method adds a reference to the collection.

## Parameters

### `ptr`

Pointer to be added to the collection.

## Return value

If the method is successful, it returns **TRUE**.

If the method fails, it returns **FALSE**.

## Remarks

The **Add** method calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on this pointer.