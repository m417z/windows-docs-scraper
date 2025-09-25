# WS_ASYNC_CALLBACK callback function

## Description

The callback function parameter used with the [asynchronous model](https://learn.microsoft.com/windows/desktop/wsw/asynchronous-model).

## Parameters

### `errorCode` [in]

The result of the operation. If the operation fails
and a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object is supplied, the object is filled with rich error information
before the callback is invoked.

### `callbackModel` [in]

A [WS_CALLBACK_MODEL](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_callback_model) value that determines whether the callback is being invoked as a long or short term callback.

### `callbackState` [in]

A void pointer that corresponds to the value of the **callbackState** field of
the [WS_ASYNC_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_async_context) structure. This parameter is used to pass user-defined data to the callback function if the operation completes asynchronously.

## Remarks

All error return codes of an operation are represented as HRESULTs. This API defines a set of HRESULTs in the FACILITY_WS range, but also returns errors defined elsewhere in the Windows API.