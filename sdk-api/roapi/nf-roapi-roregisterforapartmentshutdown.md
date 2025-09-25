# RoRegisterForApartmentShutdown function

## Description

Registers an [IApartmentShutdown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iapartmentshutdown) callback to be invoked when the current apartment shuts down.

## Parameters

### `callbackObject` [in]

The application-supplied [IApartmentShutdown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iapartmentshutdown) interface.

### `apartmentIdentifier` [out]

The identifier for the current apartment.

### `regCookie` [out]

A cookie that you can use to unregister the callback.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To receive apartment shutdown notifications, your app must register its apartment shutdown handler with the system by calling the **RoRegisterForApartmentShutdown** function.

**Warning**

Don't call the **RoRegisterForApartmentShutdown** function from the [OnUninitialize](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iapartmentshutdown-onuninitialize) callback.

## See also

[IApartmentShutdown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iapartmentshutdown)

[RoUnregisterForApartmentShutdown](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-rounregisterforapartmentshutdown)