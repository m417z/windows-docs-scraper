# IObjectProvider::QueryObject

## Description

Queries for a specified object.

## Parameters

### `guidObject` [in]

Type: **REFGUID**

A reference to the **GUID** used to identify the object.

### `riid` [in]

Type: **REFIID**

Specifies the desired interface ID.

### `ppvOut` [out]

Type: **void****

On success, contains the address of a pointer to the object specified by *riid*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Object implementers that want to enable the discovery of other objects that they can produce or that they hold should implement **IObjectProvider::QueryObject** and publish the **GUID** values that name those objects for clients of that object. Note that objects should not pass on the request for an object to other objects like [QueryService](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/cc678966(v=vs.85)).