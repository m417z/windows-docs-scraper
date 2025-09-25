# SHBindToParent function

## Description

Takes a pointer to a fully qualified item identifier list (PIDL), and returns a specified interface pointer on the parent object.

## Parameters

### `pidl` [in]

Type: **PCIDLIST_ABSOLUTE**

The item's PIDL.

### `riid` [in]

Type: **REFIID**

The **REFIID** of one of the interfaces exposed by the item's parent object.

### `ppv` [out]

Type: **VOID****

A pointer to the interface specified by *riid*. You must release the object when you are finished.

### `ppidlLast` [out]

Type: **PCUITEMID_CHILD***

The item's PIDL relative to the parent folder. This PIDL can be used with many of the methods supported by the parent folder's interfaces. If you set *ppidlLast* to **NULL**, the PIDL is not returned.

**Note** **SHBindToParent** does not allocate a new PIDL; it simply receives a pointer through this parameter. Therefore, you are not responsible for freeing this resource.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.