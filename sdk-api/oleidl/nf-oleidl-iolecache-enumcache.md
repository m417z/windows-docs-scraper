# IOleCache::EnumCache

## Description

Creates an enumerator that can be used to enumerate the current cache connections.

## Parameters

### `ppenumSTATDATA` [out]

A pointer to an [IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata) pointer variable that receives the interface pointer to the new enumerator object. If this parameter is **NULL**, there are no cache connections at this time.

## Return value

This method returns S_OK if enumerator object is successfully instantiated or there are no cache connections.

**Note** Check the *ppenumSTATDATA* parameter to determine which result occurred. If the *ppenumSTATDATA* parameter is **NULL**, then there are no cache connections at this time.

## Remarks

The enumerator object returned by this method implements the [IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata) interface. **IEnumSTATDATA** enumerates the data stored in an array of [STATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statdata) structures containing information about current cache connections.

## See also

[IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata)

[IOleCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache)

[IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache)