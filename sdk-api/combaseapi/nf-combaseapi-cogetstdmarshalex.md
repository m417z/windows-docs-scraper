# CoGetStdMarshalEx function

## Description

Creates an aggregated standard marshaler for use with lightweight client-side handlers.

## Parameters

### `pUnkOuter` [in]

A pointer to the controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown).

### `smexflags` [in]

One of two values indicating whether the aggregated standard marshaler is on the client side or the server side. These flags are defined in the **STDMSHLFLAGS** enumeration.

| Value | Meaning |
| --- | --- |
| **SMEXF_SERVER**<br><br>0x01 | Indicates a server-side aggregated standard marshaler. |
| **SMEXF_HANDLER**<br><br>0x0 | Indicates a client-side (handler) aggregated standard marshaler. |

### `ppUnkInner` [out]

On successful return, address of pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/com/iunknown-and-interface-inheritance) interface on the newly-created aggregated standard marshaler. If an error occurs, this value is **NULL**.

## Return value

This function returns S_OK.

## Remarks

The server calls **CoGetStdMarshalEx** passing in the flag SMEXF_SERVER. This creates a server side standard marshaler (known as a stub manager). The handler calls **CoGetStdMarshalEx** passing in the flag SMEXF_HANDLER. This creates a client side standard marshaler (known as a proxy manager). Note that when calling this function, the handler must pass the original controlling unknown that was passed to the handler when the handler was created. This will be the system implemented controlling unknown. Failure to pass the correct [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) results in an error returned. On success, the ppUnkInner returned is the controlling unknown of the inner object. The server and handler must keep this pointer, and may use it to call [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for the [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) interface.

## See also

[IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal)

[IStdMarshalInfo](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istdmarshalinfo)

[The Lightweight Client-Side Handler](https://learn.microsoft.com/windows/desktop/com/the-lightweight-client-side-handler)