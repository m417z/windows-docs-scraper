# RoUnregisterForApartmentShutdown function

## Description

Unregisters a previously registered [IApartmentShutdown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iapartmentshutdown) interface.

## Parameters

### `regCookie` [in]

A registration cookie obtained from a previous call to the [RoRegisterForApartmentShutdown](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-roregisterforapartmentshutdown) function.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call the **RoUnregisterForApartmentShutdown** to stop receiving apartment shutdown notifications and unregister a previously registered [IApartmentShutdown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iapartmentshutdown) interface.

**Warning**

Don't call the **RoUnregisterForApartmentShutdown** function from the [OnUninitialize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iapartmentshutdown-onuninitialize) callback.

## See also

[IApartmentShutdown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iapartmentshutdown)

[RoRegisterForApartmentShutdown](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-roregisterforapartmentshutdown)