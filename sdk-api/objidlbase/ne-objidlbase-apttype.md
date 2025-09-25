# APTTYPE enumeration

## Description

Specifies different types of apartments.

## Constants

### `APTTYPE_CURRENT:-1`

The current thread.

### `APTTYPE_STA:0`

A single-threaded apartment.

### `APTTYPE_MTA:1`

A multithreaded apartment.

### `APTTYPE_NA:2`

A neutral apartment.

### `APTTYPE_MAINSTA:3`

The main single-threaded apartment.

## See also

[CoGetApartmentType](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetapartmenttype)

[IComThreadingInfo::GetCurrentApartmentType](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-icomthreadinginfo-getcurrentapartmenttype)