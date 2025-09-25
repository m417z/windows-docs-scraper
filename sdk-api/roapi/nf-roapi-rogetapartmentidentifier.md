# RoGetApartmentIdentifier function

## Description

Gets a unique identifier for the current apartment.

## Parameters

### `apartmentIdentifier` [out]

A process-unique identifier for the current apartment.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IApartmentShutdown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iapartmentshutdown)

[RoRegisterForApartmentShutdown](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-roregisterforapartmentshutdown)

[RoUnregisterForApartmentShutdown](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-rounregisterforapartmentshutdown)